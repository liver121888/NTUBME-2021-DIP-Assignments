namespace b07611001hw1
{
    partial class Mainwindow
    {
        /// <summary>
        /// 設計工具所需的變數。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清除任何使用中的資源。
        /// </summary>
        /// <param name="disposing">如果應該處置受控資源則為 true，否則為 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form 設計工具產生的程式碼

        /// <summary>
        /// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改
        /// 這個方法的內容。
        /// </summary>
        private void InitializeComponent()
        {
            System.Windows.Forms.DataVisualization.Charting.ChartArea chartArea4 = new System.Windows.Forms.DataVisualization.Charting.ChartArea();
            System.Windows.Forms.DataVisualization.Charting.Series series4 = new System.Windows.Forms.DataVisualization.Charting.Series();
            System.Windows.Forms.DataVisualization.Charting.Title title4 = new System.Windows.Forms.DataVisualization.Charting.Title();
            System.Windows.Forms.DataVisualization.Charting.ChartArea chartArea5 = new System.Windows.Forms.DataVisualization.Charting.ChartArea();
            System.Windows.Forms.DataVisualization.Charting.Series series5 = new System.Windows.Forms.DataVisualization.Charting.Series();
            System.Windows.Forms.DataVisualization.Charting.Title title5 = new System.Windows.Forms.DataVisualization.Charting.Title();
            System.Windows.Forms.DataVisualization.Charting.ChartArea chartArea6 = new System.Windows.Forms.DataVisualization.Charting.ChartArea();
            System.Windows.Forms.DataVisualization.Charting.Series series6 = new System.Windows.Forms.DataVisualization.Charting.Series();
            System.Windows.Forms.DataVisualization.Charting.Title title6 = new System.Windows.Forms.DataVisualization.Charting.Title();
            this.btnRead1 = new System.Windows.Forms.Button();
            this.dlgOpen = new System.Windows.Forms.OpenFileDialog();
            this.pbxPic1 = new System.Windows.Forms.PictureBox();
            this.chtHisto1 = new System.Windows.Forms.DataVisualization.Charting.Chart();
            this.btnRead2 = new System.Windows.Forms.Button();
            this.pbxPic2 = new System.Windows.Forms.PictureBox();
            this.chtHisto2 = new System.Windows.Forms.DataVisualization.Charting.Chart();
            this.nudDisplacement = new System.Windows.Forms.NumericUpDown();
            this.btnDisplacement = new System.Windows.Forms.Button();
            this.btnResume = new System.Windows.Forms.Button();
            this.gbxDisplacement = new System.Windows.Forms.GroupBox();
            this.gbxMultiple = new System.Windows.Forms.GroupBox();
            this.btnMultiple = new System.Windows.Forms.Button();
            this.nudMultiple = new System.Windows.Forms.NumericUpDown();
            this.pbxPic3 = new System.Windows.Forms.PictureBox();
            this.chtHisto3 = new System.Windows.Forms.DataVisualization.Charting.Chart();
            this.btnOperation1 = new System.Windows.Forms.Button();
            this.btnOperation2 = new System.Windows.Forms.Button();
            this.btnOperation3 = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.pbxPic1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.chtHisto1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbxPic2)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.chtHisto2)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.nudDisplacement)).BeginInit();
            this.gbxDisplacement.SuspendLayout();
            this.gbxMultiple.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.nudMultiple)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbxPic3)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.chtHisto3)).BeginInit();
            this.SuspendLayout();
            // 
            // btnRead1
            // 
            this.btnRead1.Location = new System.Drawing.Point(9, 13);
            this.btnRead1.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.btnRead1.Name = "btnRead1";
            this.btnRead1.Size = new System.Drawing.Size(109, 23);
            this.btnRead1.TabIndex = 0;
            this.btnRead1.Text = "Open file A";
            this.btnRead1.UseVisualStyleBackColor = true;
            this.btnRead1.Click += new System.EventHandler(this.btnRead_Click);
            // 
            // dlgOpen
            // 
            this.dlgOpen.DefaultExt = "64";
            this.dlgOpen.Title = "Please select a .64 file.";
            // 
            // pbxPic1
            // 
            this.pbxPic1.BackColor = System.Drawing.SystemColors.AppWorkspace;
            this.pbxPic1.Location = new System.Drawing.Point(186, 13);
            this.pbxPic1.Name = "pbxPic1";
            this.pbxPic1.Size = new System.Drawing.Size(192, 192);
            this.pbxPic1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pbxPic1.TabIndex = 1;
            this.pbxPic1.TabStop = false;
            // 
            // chtHisto1
            // 
            this.chtHisto1.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            chartArea4.AxisX.Enabled = System.Windows.Forms.DataVisualization.Charting.AxisEnabled.True;
            chartArea4.AxisX.MajorGrid.LineColor = System.Drawing.Color.Silver;
            chartArea4.AxisX.Title = "pixel value";
            chartArea4.AxisY.Enabled = System.Windows.Forms.DataVisualization.Charting.AxisEnabled.True;
            chartArea4.AxisY.MajorGrid.LineColor = System.Drawing.Color.Silver;
            chartArea4.AxisY.Title = "count";
            chartArea4.Name = "ChartArea1";
            this.chtHisto1.ChartAreas.Add(chartArea4);
            this.chtHisto1.Location = new System.Drawing.Point(384, 13);
            this.chtHisto1.Name = "chtHisto1";
            series4.ChartArea = "ChartArea1";
            series4.Color = System.Drawing.Color.Red;
            series4.Name = "histogram";
            this.chtHisto1.Series.Add(series4);
            this.chtHisto1.Size = new System.Drawing.Size(420, 192);
            this.chtHisto1.TabIndex = 2;
            this.chtHisto1.Text = "chart1";
            title4.Alignment = System.Drawing.ContentAlignment.TopCenter;
            title4.Font = new System.Drawing.Font("Microsoft JhengHei", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            title4.Name = "Title1";
            title4.Text = "Histogram";
            this.chtHisto1.Titles.Add(title4);
            // 
            // btnRead2
            // 
            this.btnRead2.Location = new System.Drawing.Point(9, 211);
            this.btnRead2.Name = "btnRead2";
            this.btnRead2.Size = new System.Drawing.Size(109, 23);
            this.btnRead2.TabIndex = 3;
            this.btnRead2.Text = "Open file B";
            this.btnRead2.UseVisualStyleBackColor = true;
            this.btnRead2.Click += new System.EventHandler(this.btnRead2_Click);
            // 
            // pbxPic2
            // 
            this.pbxPic2.BackColor = System.Drawing.SystemColors.AppWorkspace;
            this.pbxPic2.Location = new System.Drawing.Point(186, 211);
            this.pbxPic2.Name = "pbxPic2";
            this.pbxPic2.Size = new System.Drawing.Size(192, 192);
            this.pbxPic2.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pbxPic2.TabIndex = 4;
            this.pbxPic2.TabStop = false;
            // 
            // chtHisto2
            // 
            this.chtHisto2.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            chartArea5.AxisX.Enabled = System.Windows.Forms.DataVisualization.Charting.AxisEnabled.True;
            chartArea5.AxisX.MajorGrid.LineColor = System.Drawing.Color.Silver;
            chartArea5.AxisX.Title = "pixel value";
            chartArea5.AxisY.Enabled = System.Windows.Forms.DataVisualization.Charting.AxisEnabled.True;
            chartArea5.AxisY.MajorGrid.LineColor = System.Drawing.Color.Silver;
            chartArea5.AxisY.Title = "count";
            chartArea5.Name = "ChartArea1";
            this.chtHisto2.ChartAreas.Add(chartArea5);
            this.chtHisto2.Location = new System.Drawing.Point(384, 211);
            this.chtHisto2.Name = "chtHisto2";
            series5.ChartArea = "ChartArea1";
            series5.Color = System.Drawing.Color.Red;
            series5.Name = "histogram";
            this.chtHisto2.Series.Add(series5);
            this.chtHisto2.Size = new System.Drawing.Size(420, 192);
            this.chtHisto2.TabIndex = 2;
            this.chtHisto2.Text = "chart1";
            title5.Font = new System.Drawing.Font("Microsoft JhengHei", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            title5.Name = "Title1";
            title5.Text = "Histogram";
            this.chtHisto2.Titles.Add(title5);
            // 
            // nudDisplacement
            // 
            this.nudDisplacement.Location = new System.Drawing.Point(6, 22);
            this.nudDisplacement.Minimum = new decimal(new int[] {
            100,
            0,
            0,
            -2147483648});
            this.nudDisplacement.Name = "nudDisplacement";
            this.nudDisplacement.Size = new System.Drawing.Size(52, 23);
            this.nudDisplacement.TabIndex = 5;
            this.nudDisplacement.Value = new decimal(new int[] {
            1,
            0,
            0,
            -2147483648});
            // 
            // btnDisplacement
            // 
            this.btnDisplacement.Location = new System.Drawing.Point(76, 22);
            this.btnDisplacement.Name = "btnDisplacement";
            this.btnDisplacement.Size = new System.Drawing.Size(75, 23);
            this.btnDisplacement.TabIndex = 7;
            this.btnDisplacement.Text = "Execute";
            this.btnDisplacement.UseVisualStyleBackColor = true;
            this.btnDisplacement.Click += new System.EventHandler(this.btnDisplacement_Click);
            // 
            // btnResume
            // 
            this.btnResume.Enabled = false;
            this.btnResume.Location = new System.Drawing.Point(85, 360);
            this.btnResume.Name = "btnResume";
            this.btnResume.Size = new System.Drawing.Size(75, 23);
            this.btnResume.TabIndex = 8;
            this.btnResume.Text = "Resume";
            this.btnResume.UseVisualStyleBackColor = true;
            this.btnResume.Click += new System.EventHandler(this.btnResume_Click);
            // 
            // gbxDisplacement
            // 
            this.gbxDisplacement.Controls.Add(this.btnDisplacement);
            this.gbxDisplacement.Controls.Add(this.nudDisplacement);
            this.gbxDisplacement.Enabled = false;
            this.gbxDisplacement.Location = new System.Drawing.Point(9, 240);
            this.gbxDisplacement.Name = "gbxDisplacement";
            this.gbxDisplacement.Size = new System.Drawing.Size(157, 54);
            this.gbxDisplacement.TabIndex = 11;
            this.gbxDisplacement.TabStop = false;
            this.gbxDisplacement.Text = "Dsiplacement";
            // 
            // gbxMultiple
            // 
            this.gbxMultiple.Controls.Add(this.btnMultiple);
            this.gbxMultiple.Controls.Add(this.nudMultiple);
            this.gbxMultiple.Enabled = false;
            this.gbxMultiple.Location = new System.Drawing.Point(9, 300);
            this.gbxMultiple.Name = "gbxMultiple";
            this.gbxMultiple.Size = new System.Drawing.Size(157, 54);
            this.gbxMultiple.TabIndex = 12;
            this.gbxMultiple.TabStop = false;
            this.gbxMultiple.Text = "Multiple";
            // 
            // btnMultiple
            // 
            this.btnMultiple.Location = new System.Drawing.Point(76, 21);
            this.btnMultiple.Name = "btnMultiple";
            this.btnMultiple.Size = new System.Drawing.Size(75, 23);
            this.btnMultiple.TabIndex = 7;
            this.btnMultiple.Text = "Execute";
            this.btnMultiple.UseVisualStyleBackColor = true;
            this.btnMultiple.Click += new System.EventHandler(this.btnMultiple_Click);
            // 
            // nudMultiple
            // 
            this.nudMultiple.Location = new System.Drawing.Point(6, 21);
            this.nudMultiple.Minimum = new decimal(new int[] {
            100,
            0,
            0,
            -2147483648});
            this.nudMultiple.Name = "nudMultiple";
            this.nudMultiple.Size = new System.Drawing.Size(52, 23);
            this.nudMultiple.TabIndex = 5;
            this.nudMultiple.Value = new decimal(new int[] {
            1,
            0,
            0,
            -2147483648});
            // 
            // pbxPic3
            // 
            this.pbxPic3.BackColor = System.Drawing.SystemColors.AppWorkspace;
            this.pbxPic3.Location = new System.Drawing.Point(186, 409);
            this.pbxPic3.Name = "pbxPic3";
            this.pbxPic3.Size = new System.Drawing.Size(192, 192);
            this.pbxPic3.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pbxPic3.TabIndex = 14;
            this.pbxPic3.TabStop = false;
            // 
            // chtHisto3
            // 
            this.chtHisto3.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            chartArea6.AxisX.Enabled = System.Windows.Forms.DataVisualization.Charting.AxisEnabled.True;
            chartArea6.AxisX.MajorGrid.LineColor = System.Drawing.Color.Silver;
            chartArea6.AxisX.Title = "pixel value";
            chartArea6.AxisY.Enabled = System.Windows.Forms.DataVisualization.Charting.AxisEnabled.True;
            chartArea6.AxisY.MajorGrid.LineColor = System.Drawing.Color.Silver;
            chartArea6.AxisY.Title = "count";
            chartArea6.Name = "ChartArea1";
            this.chtHisto3.ChartAreas.Add(chartArea6);
            this.chtHisto3.Location = new System.Drawing.Point(384, 409);
            this.chtHisto3.Name = "chtHisto3";
            series6.ChartArea = "ChartArea1";
            series6.Color = System.Drawing.Color.Red;
            series6.Name = "histogram";
            this.chtHisto3.Series.Add(series6);
            this.chtHisto3.Size = new System.Drawing.Size(420, 192);
            this.chtHisto3.TabIndex = 13;
            this.chtHisto3.Text = "chart1";
            title6.Font = new System.Drawing.Font("Microsoft JhengHei", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            title6.Name = "Title1";
            title6.Text = "Histogram";
            this.chtHisto3.Titles.Add(title6);
            // 
            // btnOperation1
            // 
            this.btnOperation1.Enabled = false;
            this.btnOperation1.Location = new System.Drawing.Point(9, 409);
            this.btnOperation1.Name = "btnOperation1";
            this.btnOperation1.Size = new System.Drawing.Size(131, 23);
            this.btnOperation1.TabIndex = 15;
            this.btnOperation1.Text = "C = average(A+B)";
            this.btnOperation1.UseVisualStyleBackColor = true;
            this.btnOperation1.Click += new System.EventHandler(this.btnOperation1_Click);
            // 
            // btnOperation2
            // 
            this.btnOperation2.Enabled = false;
            this.btnOperation2.Location = new System.Drawing.Point(9, 438);
            this.btnOperation2.Name = "btnOperation2";
            this.btnOperation2.Size = new System.Drawing.Size(157, 23);
            this.btnOperation2.TabIndex = 16;
            this.btnOperation2.Text = "C(x,y) = A(x,y) - A(x-1,y) ";
            this.btnOperation2.UseVisualStyleBackColor = true;
            this.btnOperation2.Click += new System.EventHandler(this.btnOperation2_Click);
            // 
            // btnOperation3
            // 
            this.btnOperation3.Enabled = false;
            this.btnOperation3.Location = new System.Drawing.Point(9, 468);
            this.btnOperation3.Name = "btnOperation3";
            this.btnOperation3.Size = new System.Drawing.Size(157, 23);
            this.btnOperation3.TabIndex = 17;
            this.btnOperation3.Text = "C(x,y) = A(x,y) - A(x,y-1) ";
            this.btnOperation3.UseVisualStyleBackColor = true;
            this.btnOperation3.Click += new System.EventHandler(this.btnOperation3_Click);
            // 
            // Mainwindow
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.Control;
            this.ClientSize = new System.Drawing.Size(884, 661);
            this.Controls.Add(this.btnOperation3);
            this.Controls.Add(this.pbxPic3);
            this.Controls.Add(this.chtHisto3);
            this.Controls.Add(this.btnOperation1);
            this.Controls.Add(this.btnOperation2);
            this.Controls.Add(this.gbxMultiple);
            this.Controls.Add(this.btnResume);
            this.Controls.Add(this.gbxDisplacement);
            this.Controls.Add(this.pbxPic2);
            this.Controls.Add(this.btnRead2);
            this.Controls.Add(this.chtHisto2);
            this.Controls.Add(this.chtHisto1);
            this.Controls.Add(this.pbxPic1);
            this.Controls.Add(this.btnRead1);
            this.Font = new System.Drawing.Font("Microsoft JhengHei", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(136)));
            this.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.MinimumSize = new System.Drawing.Size(900, 700);
            this.Name = "Mainwindow";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "HW1";
            ((System.ComponentModel.ISupportInitialize)(this.pbxPic1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.chtHisto1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbxPic2)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.chtHisto2)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.nudDisplacement)).EndInit();
            this.gbxDisplacement.ResumeLayout(false);
            this.gbxMultiple.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.nudMultiple)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbxPic3)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.chtHisto3)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button btnRead1;
        private System.Windows.Forms.OpenFileDialog dlgOpen;
        private System.Windows.Forms.PictureBox pbxPic1;
        private System.Windows.Forms.DataVisualization.Charting.Chart chtHisto1;
        private System.Windows.Forms.Button btnRead2;
        private System.Windows.Forms.PictureBox pbxPic2;
        private System.Windows.Forms.DataVisualization.Charting.Chart chtHisto2;
        private System.Windows.Forms.NumericUpDown nudDisplacement;
        private System.Windows.Forms.Button btnDisplacement;
        private System.Windows.Forms.Button btnResume;
        private System.Windows.Forms.GroupBox gbxDisplacement;
        private System.Windows.Forms.GroupBox gbxMultiple;
        private System.Windows.Forms.Button btnMultiple;
        private System.Windows.Forms.NumericUpDown nudMultiple;
        private System.Windows.Forms.PictureBox pbxPic3;
        private System.Windows.Forms.DataVisualization.Charting.Chart chtHisto3;
        private System.Windows.Forms.Button btnOperation1;
        private System.Windows.Forms.Button btnOperation2;
        private System.Windows.Forms.Button btnOperation3;
    }
}

