using System;
using System.Collections.Generic;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms.DataVisualization.Charting;

namespace b07611001hw1
{
    //create a image class
    class Image64
    {

        char[,] letters = new char[64, 64];
        byte[,] pixels = new byte[64, 64];
        int[] hisCounts = new int[32];
        Bitmap bmp = new Bitmap(64, 64);

        //create an attribute to get the bitmap data
        public Bitmap Bmp
        {
            //set
            //{

            //}
            get
            {
                return bmp;
            }
        }

        //create an attribute to get the histogram data
        public int[] HisCounts
        {
            //set
            //{

            //}
            get
            {
                return hisCounts;
            }
        }

        //one way to new
        public Image64()
        {

        }

        //second way to new
        public Image64(string path)
        {
            //use the path to read the file
            StreamReader SR = new StreamReader(path);
            for (int r = 0; r < 64; r++)
            {
                string str = SR.ReadLine();
                for (int c = 0; c < 64; c++)
                {
                    //transpose
                    letters[c, r] = str[c];
                }
            }
            SR.Close();
            for (int i = 0; i < 64; i++)
            {
                for (int j = 0; j < 64; j++)
                {   
                    //mapping ASCII number to grey level
                    if (letters[i, j] > '9')
                    {
                        //-7: bypass some symbols
                        pixels[i, j] = (byte)((letters[i, j] - 7 - '0'));
                    }
                    else
                    {
                        pixels[i, j] = (byte)((letters[i, j] - '0'));
                    }

                }
            }
            //update the histogram and the bitmap
            updatehisto();
            updatebitmap();

        }

        //add or subtract a constant in grey level
        public void Dsiplacepixval(int displace)
        {
            for (int i = 0; i < 64; i++)
            {
                for (int j = 0; j < 64; j++)
                {
                    int newpixel = pixels[i, j] + displace;
                    
                    //if the pixel out of bound, set it to boundary value
                    if (newpixel > 31)
                    {
                        newpixel = 31;
                    }
                    else if(newpixel < 0)
                    {
                        newpixel = 0;
                    }
                    pixels[i, j] = (byte)(newpixel);
                }
            }
            updatehisto();
            updatebitmap();
        }

        //multiply a constant in grey level
        public void Multiplepixval(int multiplier)
        {
            for (int i = 0; i < 64; i++)
            {
                for (int j = 0; j < 64; j++)
                {
                    int newpixel = pixels[i, j] * multiplier;

                    //if the pixel out of bound, set it to boundary value
                    if (newpixel > 31)
                    {
                        newpixel = 31;
                    }
                    else if (newpixel < 0)
                    {
                        newpixel = 0;
                    }
                    pixels[i, j] = (byte)(newpixel);
                }
            }
            updatehisto();
            updatebitmap();
        }

        //resume original picture 
        public void Resumepixval()
        {
            for (int i = 0; i < 64; i++)
            {
                for (int j = 0; j < 64; j++)
                {
                    if (letters[i, j] > '9')
                    {
                        pixels[i, j] = (byte)((letters[i, j] - 7 - '0'));
                    }
                    else
                    {
                        pixels[i, j] = (byte)((letters[i, j] - '0'));
                    }

                }
            }
            updatehisto();
            updatebitmap();
        }

        //operation1: average two image
        public static Image64 AverageTwo64(Image64 A, Image64 B)
        {
            Image64 C = new Image64();

            for (int i = 0; i < 64; i++)
            {
                for (int j = 0; j < 64; j++)
                {
                    //average
                    C.pixels[i, j] = (byte)((A.pixels[i, j] + B.pixels[i, j]) / 2);
                }
            }

            C.updatehisto();
            C.updatebitmap();

            return C;
        }

        //operation2: g(x,y) = f(x,y) - f(x-1,y) 
        public static Image64 Operation2Two64(Image64 A)
        {
            Image64 C = new Image64();

            for (int i = 0; i < 64; i++)
            {
                for (int j = 0; j < 64; j++)
                {
                    //for first column, regard f(-1,y) = 0, then f(0,y) = f(0,y)
                    if (i == 0)
                    {
                        C.pixels[i, j] = (byte)(A.pixels[i, j]);
                    }
                    else
                    {
                        int newpixel = A.pixels[i, j] - A.pixels[i-1, j];
                        if (newpixel < 0) newpixel = 0;
                        C.pixels[i, j] = (byte)(newpixel);
                    }

                }
            }

            C.updatehisto();
            C.updatebitmap();

            return C;
        }

        //operation3: g(x,y) = f(x,y) - f(x,y-1) 
        public static Image64 Operation3Two64(Image64 A)
        {
            Image64 C = new Image64();

            for (int i = 0; i < 64; i++)
            {
                for (int j = 0; j < 64; j++)
                {
                    //for first row, regard f(x,-1) = 0, then f(x,0) = f(x,0)
                    if (j == 0)
                    {
                        C.pixels[i, j] = (byte)(A.pixels[i, j]);
                    }
                    else
                    {
                        int newpixel = A.pixels[i, j] - A.pixels[i, j-1];
                        if (newpixel < 0) newpixel = 0;
                        C.pixels[i, j] = (byte)(newpixel);
                    }

                }
            }

            C.updatehisto();
            C.updatebitmap();

            return C;
        }

        //update histogram
        void updatehisto()
        {
            //clear counters
            for (int i = 0; i < hisCounts.Length; i++)
            {
                hisCounts[i] = 0;
            }
            
            for (int i = 0; i < 64; i++)
            {
                for (int j = 0; j < 64; j++)
                {
                    //hisCounts[pixels[i, j]] = hisCounts[pixels[i, j]] + 1
                    hisCounts[pixels[i, j]]++;
                }
            }
        }

        //update bitmap
        void updatebitmap()
        {
            for (int r = 0; r < 64; r++)
            {
                for (int c = 0; c < 64; c++)
                {
                    //change grey scale from 0-31 to 7-255 to show in picturebox
                    byte mapval = (byte)((pixels[r, c] + 1) * 8 - 1);
                    Color col = Color.FromArgb(mapval, mapval, mapval);
                    bmp.SetPixel(r, c, col);

                }
            }
        }
    }
}
