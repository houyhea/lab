using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.ComponentModel;
using System.Collections;

namespace AppConfigModifyTest.newP
{
    public class AppSettings : CollectionBase,ICustomTypeDescriptor
	{
       #region collection impl

        public void Add(AppSetting ddz)
        {
            this.List.Add(ddz);
        }

        public void Remove(AppSetting ddz)
        {
            this.List.Remove(ddz);
        }

        public AppSetting this[int index]
        {
            get
            {
                return (AppSetting)this.List[index];
            }
        }

        #endregion
        #region ICustomTypDescriptor
        public AttributeCollection GetAttributes()
        {            
            return TypeDescriptor.GetAttributes(this, true);
        }

        public string GetClassName()
        {
            return TypeDescriptor.GetClassName(this, true);
        }

        public string GetComponentName()
        {
            return TypeDescriptor.GetComponentName(this, true);
        }

        public System.ComponentModel.TypeConverter GetConverter()
        {
            return TypeDescriptor.GetConverter(this, true);
        }

        public EventDescriptor GetDefaultEvent()
        {
            return TypeDescriptor.GetDefaultEvent(this, true);
        }

        public PropertyDescriptor GetDefaultProperty()
        {
            return TypeDescriptor.GetDefaultProperty(this, true);
        }

        public object GetEditor(Type editorBaseType)
        {
            return TypeDescriptor.GetEditor(this, editorBaseType, true);
        }

        public EventDescriptorCollection GetEvents(Attribute[] attributes)
        {
            return TypeDescriptor.GetEvents(this, attributes, true);
        }

        public EventDescriptorCollection GetEvents()
        {
            return TypeDescriptor.GetEvents(this, true);
        }

        public PropertyDescriptorCollection GetProperties(Attribute[] attributes)
        {
            PropertyDescriptorCollection pds = new PropertyDescriptorCollection(null);

            for (int i = 0; i < this.List.Count; i++)
            {
                AppSettingDescriptor pd = new AppSettingDescriptor(this[i], attributes);
                //TypeDescriptor.AddAttributes(pd, new CategoryAttribute("更改"));
                pds.Add(pd);
            }
            return pds;
        }

        public PropertyDescriptorCollection GetProperties()
        {            
            return TypeDescriptor.GetProperties(this, true);
        }

        public object GetPropertyOwner(PropertyDescriptor pd)
        {
            return this;
        }
        #endregion
    }
}
