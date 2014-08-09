using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.ComponentModel;

namespace AppConfigModifyTest.newP
{
    /// <summary>
    /// 配置参数属性描述类。里面的好多属性都可以通过读取XML信息来动态变化。Editor也可以通过读取XML，反射出Editor对象出来。
    /// </summary>
    public class AppSettingDescriptor : PropertyDescriptor
    {
        private AppSetting ass = null;

        public AppSettingDescriptor(AppSetting coll, Attribute[] attrs) :
            base(coll.Key, attrs)
        {
            this.ass = coll;
        }
        public override bool CanResetValue(object component)
        {
            return false;
        }

        public override Type ComponentType
        {
            get { return this.ass.GetType(); }
        }

        public override object GetValue(object component)
        {
            return this.ass.Value;
        }

        public override bool IsReadOnly
        {
            get
            {
                return IsReadOnlyFromAppSettingInfo(ass.Key);
            }
        }


        public override Type PropertyType
        {
            get { return ass.Value.GetType(); }
        }

        public override void ResetValue(object component)
        {

        }

        public override void SetValue(object component, object value)
        {
            ass.Value = (string)value;
        }

        public override bool ShouldSerializeValue(object component)
        {
            return false;
        }

        public override string Category
        {
            get
            {
                string str = GetCategoryFromAppSettingInfo(ass.Key);
                if (str == string.Empty)
                    return base.Category;
                else
                    return str;
            }
        }
        public override string Description
        {
            get
            {
                string str = GetDescriptionFromAppSettingInfo(ass.Key);
                if (str == string.Empty)
                    return base.Description;
                else
                    return str;
            }
        }
        public override string DisplayName
        {
            get
            {
                string str = GetDisplayNameFromAppSettingInfo(ass.Key);
                if (str == string.Empty)
                    return base.DisplayName;
                else
                    return str;
            }
        }
        #region 私有方法
        private bool IsReadOnlyFromAppSettingInfo(string key)
        {
            foreach (AppSettingInfo.AppSettingInfo item in AppSettingInfo.AppSettingInfoManager.Instance.Appsettinginfo.AppSettings)
            {
                if (item.Key == key)
                    return item.IsReadOnly;
            }
            return false;
        }

        private string GetDisplayNameFromAppSettingInfo(string key)
        {
            foreach (AppSettingInfo.AppSettingInfo item in AppSettingInfo.AppSettingInfoManager.Instance.Appsettinginfo.AppSettings)
            {
                if (item.Key == key)
                    return item.DisplayName.Trim();
            }
            return string.Empty;
        }


        private string GetDescriptionFromAppSettingInfo(string key)
        {
            foreach (AppSettingInfo.AppSettingInfo item in AppSettingInfo.AppSettingInfoManager.Instance.Appsettinginfo.AppSettings)
            {
                if (item.Key == key)
                    return item.Description.Trim();
            }
            return string.Empty;
        }

        private string GetCategoryFromAppSettingInfo(string key)
        {
            foreach (AppSettingInfo.AppSettingInfo item in AppSettingInfo.AppSettingInfoManager.Instance.Appsettinginfo.AppSettings)
            {
                if (item.Key == key)
                    return item.Category.Trim();
            }
            return string.Empty;
        }
        #endregion
    }
}
