using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace AppConfigModifyTest.AppSettingInfo
{
    [Serializable]
    public class AppSettingInfo
    {
        public string Key{get;set;}
        public string Category { get; set; }
        public string Description { get; set; }
        public string DisplayName { get; set; }
        public bool IsReadOnly { get; set; }
        public List<AppSettingInfo> AppSettings { get; set; }
        

        public AppSettingInfo()
        {
            AppSettings = new List<AppSettingInfo>();
        }
    }
}
