using System;
using System.Drawing;
using System.Collections;
using System.ComponentModel;
using System.Windows.Forms;
using System.Data;

namespace TabControlTest
{
	/// <summary>
	/// Summary description for Form1.
	/// </summary>
	public class Form1 : System.Windows.Forms.Form
    {
		private System.ComponentModel.IContainer components;

		public Form1()
		{
			//
			// Required for Windows Form Designer support
			//
			InitializeComponent();

			//
			// TODO: Add any constructor code after InitializeComponent call
			//
		}

		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		protected override void Dispose( bool disposing )
		{
			if( disposing )
			{
				if (components != null) 
				{
					components.Dispose();
				}
			}
			base.Dispose( disposing );
		}

		#region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		private void InitializeComponent()
		{
            this.flatTabControl1 = new FlatTabControl.FlatTabControl();
            this.tabPage1 = new System.Windows.Forms.TabPage();
            this.tabPage2 = new System.Windows.Forms.TabPage();
            this.flatTabControl1.SuspendLayout();
            this.SuspendLayout();
            // 
            // flatTabControl1
            // 
            this.flatTabControl1.Alignment = System.Windows.Forms.TabAlignment.Left;
            this.flatTabControl1.Controls.Add(this.tabPage1);
            this.flatTabControl1.Controls.Add(this.tabPage2);
            this.flatTabControl1.Location = new System.Drawing.Point(136, 77);
            this.flatTabControl1.Multiline = true;
            this.flatTabControl1.myBackColor = System.Drawing.SystemColors.Control;
            this.flatTabControl1.Name = "flatTabControl1";
            this.flatTabControl1.SelectedIndex = 0;
            this.flatTabControl1.Size = new System.Drawing.Size(521, 356);
            this.flatTabControl1.TabIndex = 0;
            // 
            // tabPage1
            // 
            this.tabPage1.Location = new System.Drawing.Point(26, 4);
            this.tabPage1.Name = "tabPage1";
            this.tabPage1.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage1.Size = new System.Drawing.Size(491, 348);
            this.tabPage1.TabIndex = 0;
            this.tabPage1.Text = "tabPage1";
            this.tabPage1.UseVisualStyleBackColor = true;
            // 
            // tabPage2
            // 
            this.tabPage2.Location = new System.Drawing.Point(26, 4);
            this.tabPage2.Name = "tabPage2";
            this.tabPage2.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage2.Size = new System.Drawing.Size(491, 348);
            this.tabPage2.TabIndex = 1;
            this.tabPage2.Text = "tabPage2";
            this.tabPage2.UseVisualStyleBackColor = true;
            // 
            // Form1
            // 
            this.AutoScaleBaseSize = new System.Drawing.Size(6, 14);
            this.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(68)))), ((int)(((byte)(83)))), ((int)(((byte)(104)))));
            this.ClientSize = new System.Drawing.Size(780, 526);
            this.Controls.Add(this.flatTabControl1);
            this.Name = "Form1";
            this.Text = "FlatTabControl test";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.flatTabControl1.ResumeLayout(false);
            this.ResumeLayout(false);

		}
		#endregion

		/// <summary>
		/// The main entry point for the application.
		/// </summary>
		[STAThread]
		static void Main() 
		{
			Application.Run(new Form1());
		}

		private void Form1_Load(object sender, System.EventArgs e)
		{
		
		}

        private FlatTabControl.FlatTabControl flatTabControl1;
        private TabPage tabPage1;
        private TabPage tabPage2;

		private static int nt = 0;

		private void button2_Click(object sender, System.EventArgs e)
		{
			TabPage tabPage = new System.Windows.Forms.TabPage("newTab");

			switch (nt)
			{
				case 0:
				{
					tabPage.BackColor = Color.LightCoral;
					tabPage.ImageIndex = 0;
					nt = 1;
				}
				break;

				case 1:
				{
					tabPage.BackColor = Color.LightGoldenrodYellow;
					tabPage.ImageIndex = 1;
					nt = 2;
				}
				break;

				case 2:
				{
					tabPage.BackColor = Color.LightSeaGreen;
					tabPage.ImageIndex = 2;
					nt = 0;
				}
				break;
			}
			
			flatTabControl1.TabPages.Add(tabPage);
		}

		private void button3_Click(object sender, System.EventArgs e)
		{
			flatTabControl1.TabPages.RemoveAt(flatTabControl1.SelectedIndex);
		}

		private void tabControl1_DrawItem(object sender, System.Windows.Forms.DrawItemEventArgs e)
		{
			MessageBox.Show("1");
		}
	}
}
