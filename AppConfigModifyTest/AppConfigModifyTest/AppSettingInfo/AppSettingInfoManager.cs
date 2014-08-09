using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Reflection;
using System.Xml.Serialization;

namespace AppConfigModifyTest.AppSettingInfo
{
    public class AppSettingInfoManager
    {
        private AppSettingInfo appsettinginfo;

        public AppSettingInfo Appsettinginfo
        {
            get { return appsettinginfo; }
            set { appsettinginfo = value; }
        }     
        
        private static AppSettingInfoManager instance = null;
        public static AppSettingInfoManager Instance
        {
            get
            {
                if (instance == null)
                {
                    instance = new AppSettingInfoManager();
                }
                return instance;
            }
        }
        private AppSettingInfoManager()
        {
            LoadData();
        }

        public string XmlFile
        {
            get
            {
                string path = Path.Combine(System.Windows.Forms.Application.StartupPath,
                  "AppSettingInfo\\");
                if (!Directory.Exists(path))
                {
                    Directory.CreateDirectory(path);
                }
                path = Path.Combine(path, "AppSettingInfo.xml");

                try
                {
                    //如果config.xml不存在，则从程序集里读取默认的XML，然后保存到该目录下
                    //if (!Directory.Exists(path))
                    if (!File.Exists(path))
                    {
                        //DebugHelper.Write("节点关系约束配置文件【" + path + "】不存在，将读取程序集默认的配置文件。");
                        Assembly _assembly = Assembly.GetExecutingAssembly();
                        string resourceName = "AppConfigModifyTest.AppSettingInfo.AppSettingInfo.xml";//根据资源名称从Assembly中获取此资源的Stream
                        Stream stream = _assembly.GetManifestResourceStream(resourceName);

                        WriteFile(stream, path);
                    }
                }
                catch (Exception err)
                {
                    //DebugHelper.Write(err);
                }
                return path;


            }
        }
        #region 公共方法

        /// <summary>
        /// 载入参数
        /// </summary>
        public void LoadData()
        {
            FileStream myFileStream = null;

            try
            {
                //DebugHelper.Write("加载系统配置参数。。。");
                XmlSerializer mySerializer = new XmlSerializer(typeof(AppSettingInfo));

                myFileStream = new FileStream(XmlFile, FileMode.Open);
                appsettinginfo = (AppSettingInfo)mySerializer.Deserialize(myFileStream);
                myFileStream.Close();
            }
            catch (Exception err)
            {
                //DebugHelper.Write(err);
                appsettinginfo = GetDefaultValue();
            }
            finally
            {
                if (myFileStream != null)
                {
                    myFileStream.Close();
                }
            }


        }
        /// <summary>
        /// 保存参数
        /// </summary>
        public bool SaveData()
        {
            StreamWriter myWriter = null;
            try
            {
                XmlSerializer mySerializer = new XmlSerializer(typeof(AppSettingInfo));
                myWriter = new StreamWriter(XmlFile);

                mySerializer.Serialize(myWriter, appsettinginfo);
                myWriter.Close();
                return true;
            }
            catch (Exception err)
            {
                //DebugHelper.Write(err);
                return false;
            }
            finally
            {
                if (myWriter != null)
                    myWriter.Close();

            }


        }


        #endregion

        #region 私有方法
        private void WriteFile(System.IO.Stream stream, string filename)
        {
            if (stream == null) return;
            try
            {
                #region
                //两种方式读取字节流，第二种快一些。
                //using (System.IO.StreamWriter objwrite = new System.IO.StreamWriter(filename))
                //{
                //    int k = 0;
                //    while (k != -1)
                //    {
                //        k = stream.ReadByte();
                //        if (k != -1)
                //        {
                //            objwrite.BaseStream.WriteByte((byte)k);
                //        }
                //    }
                //}
                #endregion

                using (System.IO.StreamWriter objwrite = new System.IO.StreamWriter(filename))
                {
                    byte[] bytes = new byte[stream.Length];
                    stream.Read(bytes, 0, bytes.Length);
                    objwrite.BaseStream.Write(bytes, 0, bytes.Length);
                }
            }
            catch (Exception err)
            {
                // DebugHelper.Write(err);
            }
        }

        /// <summary>
        /// 设置默认参数值
        /// </summary>
        /// <returns></returns>
        private AppSettingInfo GetDefaultValue()
        {
            AppSettingInfo l = new AppSettingInfo();

            l.Key = Guid.NewGuid().ToString();

            return l;
        }
        #endregion

    }
}
