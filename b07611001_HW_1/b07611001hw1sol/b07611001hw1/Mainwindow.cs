using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace b07611001hw1
{
    public partial class Mainwindow : Form
    {
        //declaration of variables
        Image64 img1;
        Image64 img2;
        Image64 img3;
        public Mainwindow()
        {
            InitializeComponent();
        }

        

        private void btnRead_Click(object sender, EventArgs e)
        {
            //use dialogue to get the filepath
            DialogResult ans = dlgOpen.ShowDialog();
            if (ans != DialogResult.OK) return;
            img1 = new Image64(dlgOpen.FileName);
            //use attribute to get the bitmap data and show
            pbxPic1.Image = img1.Bmp;
            //use PopulateSeries function to show the histogram
            PopulateSeries(chtHisto1.Series[0], img1);
            //enable operation buttons only if both images exist
            if (img1 != null && img2 != null)
            {
                btnOperation1.Enabled = true;
                btnOperation2.Enabled = true;
                btnOperation3.Enabled = true;

            }


        }

        private void btnRead2_Click(object sender, EventArgs e)
        {
            //use dialogue to get the filepath
            DialogResult ans = dlgOpen.ShowDialog();
            if (ans != DialogResult.OK) return;
            img2 = new Image64(dlgOpen.FileName);
            //use attribute to get the bitmap data and show
            pbxPic2.Image = img2.Bmp;
            //use PopulateSeries function to show the histogram
            PopulateSeries(chtHisto2.Series[0], img2);
            //enable manipulation buttons if both image2 exist
            btnResume.Enabled = gbxMultiple.Enabled = gbxDisplacement.Enabled = true;
            //enable operation buttons only if both images exist
            if (img1 != null && img2 != null)
            {
                btnOperation1.Enabled = true;
                btnOperation2.Enabled = true;
                btnOperation3.Enabled = true;
            }


        }

        private void btnDisplacement_Click(object sender, EventArgs e)
        {
            //get the offset value
            int offset = (int)nudDisplacement.Value;
            //offset the image
            img2.Dsiplacepixval(offset);
            PopulateSeries(chtHisto2.Series[0], img2);
            pbxPic2.Image = img2.Bmp;
        }


        private void btnResume_Click(object sender, EventArgs e)
        {
            //resume original image
            img2.Resumepixval();
            PopulateSeries(chtHisto2.Series[0], img2);
            pbxPic2.Image = img2.Bmp;
        }

        private void btnMultiple_Click(object sender, EventArgs e)
        {
            //get the multiplier value
            int multiplier = (int)nudMultiple.Value;
            //manipulate the image
            img2.Multiplepixval(multiplier);
            PopulateSeries(chtHisto2.Series[0], img2);
            pbxPic2.Image = img2.Bmp;
        }

        private void btnOperation1_Click(object sender, EventArgs e)
        {
            //operation1: average
            img3 = Image64.AverageTwo64(img1, img2);
            pbxPic3.Image = img3.Bmp;
            PopulateSeries(chtHisto3.Series[0], img3);


        }

        private void btnOperation2_Click(object sender, EventArgs e)
        {
            //operation2: g(x,y) = f(x,y) - f(x-1,y) 
            img3 = Image64.Operation2Two64(img1);
            pbxPic3.Image = img3.Bmp;
            PopulateSeries(chtHisto3.Series[0], img3);

        }

        private void btnOperation3_Click(object sender, EventArgs e)
        {
            //operation: g(x,y) = f(x,y) - f(x,y-1) 
            img3 = Image64.Operation3Two64(img1);
            pbxPic3.Image = img3.Bmp;
            PopulateSeries(chtHisto3.Series[0],img3);
        }

        //show histogram
        private void PopulateSeries(System.Windows.Forms.DataVisualization.Charting.Series s, Image64 img)
        {
            s.Points.Clear();
            for (int i = 0; i < 32; i++)
            {
                int yval = img.HisCounts[i];
                //show Y value on corresponding X value
                s.Points.AddXY(i, yval);

            }
        }


    }
}
