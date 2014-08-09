using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Collections;
using System.IO;

namespace M8PushBoxLevelMaker
{
    public partial class Form1 : Form
    {
        bool mouseDown = false;
        PictureBox[,] pics = new PictureBox[13, 8]; 

        ToolTip toolTip1;
        bool hasFile = false;

        string fileName;
        private Dictionary<int,string> picPath;
        public Form1()
        {
            picPath = new Dictionary<int, string>();

            picPath.Add(0, "pic/blank.bmp");
            picPath.Add(1, "pic/wall.bmp");
            picPath.Add(2, "pic/box.bmp");
            picPath.Add(4, "pic/person.bmp");
            picPath.Add(6, "pic/target.bmp");

            toolTip1 = new ToolTip();   // Set up the delays for the ToolTip.   
            toolTip1.AutoPopDelay = 5000;
            toolTip1.InitialDelay = 200;
            toolTip1.ReshowDelay = 200;   // Force the ToolTip text to be displayed whether or not the form is active.   
            toolTip1.ShowAlways = true;         // Set up the ToolTip text for the Button and Checkbox.   

            //GenPictureBox(1,1,1);
            //GenPictureBox(2, 1, 2);

            for (int i = 0; i < 13; i++)
            {
                for (int j = 0; j < 8; j++)
                {
                    PictureBox picb= GenPictureBox(i * 13 + j, j, i);
                    pics[i,j] = picb;

                }
            }
            
            InitializeComponent();
            this.Width = 700;
            this.Height = 720;
            
            button3.Enabled = false;



            pictureBox1.Image = Image.FromFile(picPath[0]);
            pictureBox2.Image = Image.FromFile(picPath[1]);
            pictureBox3.Image = Image.FromFile(picPath[2]);
            pictureBox4.Image = Image.FromFile(picPath[6]);
            pictureBox5.Image = Image.FromFile(picPath[4]);


        }

        private PictureBox GenPictureBox(int id, int left, int top)
        {
            PictureBox picBox = new PictureBox();
            //picBox.ImageLocation = picPath[0];
            picBox.Image = Image.FromFile(picPath[0]);
            picBox.Tag = 0;
            Controls.Add(picBox);
            picBox.Left = 10+48*(left+1);
            picBox.Top = 5+48*(top+1);
            picBox.Click += new EventHandler(pictureBox1_Click);
            picBox.MouseEnter += new EventHandler(picBox_MouseEnter);
            picBox.MouseLeave += new EventHandler(picBox_MouseLeave);
            picBox.Width = 48;
            picBox.Height = 48;

            toolTip1.SetToolTip(picBox, "点击控件切换地图形状.");
            return picBox;

        }

        void picBox_MouseLeave(object sender, EventArgs e)
        {
            PictureBox p = sender as PictureBox;
            Cursor = Cursors.Default;
        }

        void picBox_MouseEnter(object sender, EventArgs e)
        {
            PictureBox p = sender as PictureBox;
            Cursor = Cursors.Hand;
            if (mouseDown)
            {
                p.Image = Image.FromFile(picPath[1]);
                p.Tag = 1;
            }
            



        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {
            //Image pic = new Bitmap("pic/person.png");
            PictureBox p = sender as PictureBox;
            int t = int.Parse(p.Tag.ToString() );
            switch (t)
            { 
                case 0:
                    p.Tag = 1;
                    p.Image = Image.FromFile(picPath[1]);
                    break;
                case 1:
                    p.Tag = 2;
                    p.Image = Image.FromFile(picPath[2]);
                    break;
                case 2:
                    p.Tag = 6;
                    p.Image = Image.FromFile(picPath[6]);
                    break;
                case 6:
                    p.Tag = 4;
                    p.Image = Image.FromFile(picPath[4]);
                    break;
                case 4:
                    p.Tag = 0;
                    p.Image = Image.FromFile(picPath[0]);
                    break;
            }
            
        }

        private void button1_Click(object sender, EventArgs e)
        {
            openFileDialog1.Filter =  "bin文件(*.bin)|*.bin"; //openFileDialog1
            //openFileDialog1.Filter = "数据文件(*.dat)|*.dat| bin文件(*.bin)|*.bin"; //openFileDialog1

            if (openFileDialog1.ShowDialog() == DialogResult.OK)
            {
                fileName = openFileDialog1.FileName;
                hasFile = true;
            }

        }

        private void openFileDialog1_FileOk(object sender, CancelEventArgs e)
        {
            textBox1.Text = openFileDialog1.FileName;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            mouseDown = true;
            button2.Enabled = false;
            button3.Enabled = true;

        }

        private void button3_Click(object sender, EventArgs e)
        {
            mouseDown = false;
            button2.Enabled = true;
            button3.Enabled = false;
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            this.Top = 0;
            
        }

        //生成关卡
        private void button4_Click(object sender, EventArgs e)
        {
            if (!hasFile)
            {
                MessageBox.Show("请选择关卡数据文件");
                return;

            }
            if (string.IsNullOrEmpty(textBoxLevel.Text))
            {
                MessageBox.Show("请填写当前关数");
                return;
                
            }

            FileStream datStream;
            BinaryWriter datWriter;
            datStream = new FileStream(fileName, FileMode.Append);
            datWriter = new BinaryWriter(datStream);
            
            
            
            //datWriter.Write(OriginalLevels.Count);
            char[] buff = new char[8];
            for (int j = 0; j < 8; j++)
            {
                int num = int.Parse(textBoxLevel.Text);
                char level = (char)num;

                
                buff[j] = level;
            }

            for (int row = 0; row < 13; row++)
            {
                for (int col = 0; col < 8; col++)
                {
                    PictureBox pic = pics[row,col];
                    
                    int tag = int.Parse(pic.Tag.ToString());

                    char ctag = (char)tag;
                    datWriter.Write(ctag);

                    if (col == 7)
                    {
                        datWriter.Write(buff);
                        break;
                    }
                }
            }
            datWriter.Close();
            datStream.Close();

        }

        private void button5_Click(object sender, EventArgs e)
        {
            for (int row = 0; row < 13; row++)
            {
                for (int col = 0; col < 8; col++)
                {
                    PictureBox pic = pics[row, col];
                    pic.Tag = 0;
                    pic.Image = Image.FromFile(picPath[0]);
 
                }
            }
        }

        private void Form1_FormClosed(object sender, FormClosedEventArgs e)
        {

        }

        




    }
}
