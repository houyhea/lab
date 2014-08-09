using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Configuration;
using System.Collections.Specialized;
using AppConfigModifyTest.newP;

namespace AppConfigModifyTest
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            propertyGrid1.SelectedObject = GetAppsettings(ConfigurationManager.AppSettings);


        }

        //private void testc()
        //{
        //    AppSettingInfo.AppSettingInfo ap = new AppSettingInfo.AppSettingInfo();
        //    ap.Key = "";
        //    ap.Description = "应用程序配置信息";
        //    ap.AppSettings.Add(GetAppsettings());
        //    ap.AppSettings.Add(GetAppsettings());
        //    ap.AppSettings.Add(GetAppsettings());

        //    AppSettingInfo.AppSettingInfoManager.Instance.Appsettinginfo = ap;
        //    AppSettingInfo.AppSettingInfoManager.Instance.SaveData();


        //}

        //private AppSettingInfo.AppSettingInfo GetAppsettings()
        //{
        //    AppSettingInfo.AppSettingInfo ap = new AppSettingInfo.AppSettingInfo();
        //    ap.Key = "testid";
        //    ap.Categray = "基本";
        //    ap.Description = "测试的id";
        //    ap.DisplayName = "testid disc";
        //    return ap;
        //}

        private AppSettings GetAppsettings(NameValueCollection nameValueCollection)
        {
            //AppSettingsCollection col = new AppSettingsCollection();
            AppSettings col = new AppSettings();
            for (int i = 0; i < nameValueCollection.Count; i++)
            {
                col.Add(new AppSetting() { Key = nameValueCollection.Keys[i], Value = nameValueCollection[i]});
            }
            //foreach (KeyValuePair<object,object> item in nameValueCollection)
            //{
            //    col.Add(new AppSetting() { Key = item.Key, Value = item.Value });
            //}
            return col;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string dd1 = AppConfigHelper.getSetting("test1");
            string dd2 = ConfigurationManager.AppSettings["test1"];
            AppConfigHelper.updateSeeting("test1", DateTime.Now.ToString());
            ConfigurationManager.RefreshSection("appsetings");
            string dd = AppConfigHelper.getSetting("test1");
            string dd3 = ConfigurationManager.AppSettings["test1"];
        }

        private void button2_Click(object sender, EventArgs e)
        {
            AppSettings ass = propertyGrid1.SelectedObject as AppSettings;
            if (ass != null)
            {
                foreach (AppSetting item in ass)
                {
                    AppConfigHelper.updateSeeting(item.Key, item.Value);
                }
            }
        }
    }
}
