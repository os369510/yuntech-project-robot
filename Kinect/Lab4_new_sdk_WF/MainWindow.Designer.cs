namespace Lab4_new_sdk_WF
{
    partial class MainWindow
    {
        /// <summary>
        /// 設計工具所需的變數。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清除任何使用中的資源。
        /// </summary>
        /// <param name="disposing">如果應該處置 Managed 資源則為 true，否則為 false。</param>
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
        /// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器
        /// 修改這個方法的內容。
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.serialPort1 = new System.IO.Ports.SerialPort(this.components);
            this.StartButtonTimer = new System.Windows.Forms.Timer(this.components);
            this.GameTimer = new System.Windows.Forms.Timer(this.components);
            this.Status = new System.Windows.Forms.TextBox();
            this.StatusValue = new System.Windows.Forms.TextBox();
            this.GameTime = new System.Windows.Forms.TextBox();
            this.GameTimeValue = new System.Windows.Forms.TextBox();
            this.Title1 = new System.Windows.Forms.TextBox();
            this.TextChangeTimer = new System.Windows.Forms.Timer(this.components);
            this.ClearStart = new System.Windows.Forms.Timer(this.components);
            this.Title2 = new System.Windows.Forms.TextBox();
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.settingToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.comPortToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.StartButton = new System.Windows.Forms.ToolStripMenuItem();
            this.NowPlayerTextBox = new System.Windows.Forms.TextBox();
            this.textBox4 = new System.Windows.Forms.TextBox();
            this.NowPlayerNumberTextBox = new System.Windows.Forms.TextBox();
            this.textBox6 = new System.Windows.Forms.TextBox();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.InformationBox = new System.Windows.Forms.ListBox();
            this.NowTotalPlayerNumberTextBox = new System.Windows.Forms.TextBox();
            this.textBox5 = new System.Windows.Forms.TextBox();
            this.DriverGameStatusTextBox = new System.Windows.Forms.TextBox();
            this.textBox7 = new System.Windows.Forms.TextBox();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.menuStrip1.SuspendLayout();
            this.groupBox1.SuspendLayout();
            this.SuspendLayout();
            // 
            // pictureBox1
            // 
            this.pictureBox1.Location = new System.Drawing.Point(0, 101);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(640, 480);
            this.pictureBox1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pictureBox1.TabIndex = 0;
            this.pictureBox1.TabStop = false;
            this.pictureBox1.Paint += new System.Windows.Forms.PaintEventHandler(this.pictureBox1_Paint);
            // 
            // serialPort1
            // 
            this.serialPort1.PortName = "COM15";
            // 
            // StartButtonTimer
            // 
            this.StartButtonTimer.Interval = 3000;
            this.StartButtonTimer.Tick += new System.EventHandler(this.StartButtonTimer_Tick);
            // 
            // GameTimer
            // 
            this.GameTimer.Interval = 1000;
            this.GameTimer.Tick += new System.EventHandler(this.GameTimer_Tick);
            // 
            // Status
            // 
            this.Status.BackColor = System.Drawing.Color.Yellow;
            this.Status.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.Status.Cursor = System.Windows.Forms.Cursors.No;
            this.Status.Font = new System.Drawing.Font("新細明體", 18F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(136)));
            this.Status.ForeColor = System.Drawing.Color.Red;
            this.Status.Location = new System.Drawing.Point(496, 29);
            this.Status.Name = "Status";
            this.Status.ReadOnly = true;
            this.Status.Size = new System.Drawing.Size(63, 29);
            this.Status.TabIndex = 1;
            this.Status.Text = "狀態";
            this.Status.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // StatusValue
            // 
            this.StatusValue.BackColor = System.Drawing.Color.White;
            this.StatusValue.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.StatusValue.Cursor = System.Windows.Forms.Cursors.No;
            this.StatusValue.Font = new System.Drawing.Font("新細明體", 18F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(136)));
            this.StatusValue.Location = new System.Drawing.Point(565, 29);
            this.StatusValue.Name = "StatusValue";
            this.StatusValue.ReadOnly = true;
            this.StatusValue.Size = new System.Drawing.Size(75, 29);
            this.StatusValue.TabIndex = 2;
            this.StatusValue.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // GameTime
            // 
            this.GameTime.BackColor = System.Drawing.Color.Yellow;
            this.GameTime.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.GameTime.Cursor = System.Windows.Forms.Cursors.No;
            this.GameTime.Font = new System.Drawing.Font("新細明體", 18F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(136)));
            this.GameTime.ForeColor = System.Drawing.Color.Red;
            this.GameTime.Location = new System.Drawing.Point(496, 66);
            this.GameTime.Name = "GameTime";
            this.GameTime.ReadOnly = true;
            this.GameTime.Size = new System.Drawing.Size(63, 29);
            this.GameTime.TabIndex = 3;
            this.GameTime.Text = "時間";
            this.GameTime.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // GameTimeValue
            // 
            this.GameTimeValue.BackColor = System.Drawing.Color.White;
            this.GameTimeValue.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.GameTimeValue.Cursor = System.Windows.Forms.Cursors.No;
            this.GameTimeValue.Font = new System.Drawing.Font("新細明體", 18F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(136)));
            this.GameTimeValue.Location = new System.Drawing.Point(565, 64);
            this.GameTimeValue.Name = "GameTimeValue";
            this.GameTimeValue.ReadOnly = true;
            this.GameTimeValue.Size = new System.Drawing.Size(75, 29);
            this.GameTimeValue.TabIndex = 4;
            this.GameTimeValue.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // Title1
            // 
            this.Title1.BackColor = System.Drawing.SystemColors.Control;
            this.Title1.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.Title1.Cursor = System.Windows.Forms.Cursors.No;
            this.Title1.Font = new System.Drawing.Font("新細明體", 18F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(136)));
            this.Title1.ForeColor = System.Drawing.Color.MediumSlateBlue;
            this.Title1.Location = new System.Drawing.Point(0, 29);
            this.Title1.Name = "Title1";
            this.Title1.ReadOnly = true;
            this.Title1.Size = new System.Drawing.Size(495, 29);
            this.Title1.TabIndex = 5;
            this.Title1.Text = "請溫柔的對待我！！不要讓我做危險動作！！";
            this.Title1.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // TextChangeTimer
            // 
            this.TextChangeTimer.Interval = 500;
            this.TextChangeTimer.Tick += new System.EventHandler(this.TextChangeTimer_Tick);
            // 
            // ClearStart
            // 
            this.ClearStart.Interval = 1000;
            this.ClearStart.Tick += new System.EventHandler(this.ClearStart_Tick);
            // 
            // Title2
            // 
            this.Title2.BackColor = System.Drawing.SystemColors.Control;
            this.Title2.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.Title2.Cursor = System.Windows.Forms.Cursors.No;
            this.Title2.Font = new System.Drawing.Font("新細明體", 18F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(136)));
            this.Title2.ForeColor = System.Drawing.Color.Black;
            this.Title2.Location = new System.Drawing.Point(32, 64);
            this.Title2.Name = "Title2";
            this.Title2.ReadOnly = true;
            this.Title2.Size = new System.Drawing.Size(395, 29);
            this.Title2.TabIndex = 6;
            this.Title2.Text = "動作慢點！！我做不來原諒我Q_Q";
            this.Title2.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // menuStrip1
            // 
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.settingToolStripMenuItem,
            this.StartButton});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(964, 24);
            this.menuStrip1.TabIndex = 13;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // settingToolStripMenuItem
            // 
            this.settingToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.comPortToolStripMenuItem});
            this.settingToolStripMenuItem.Name = "settingToolStripMenuItem";
            this.settingToolStripMenuItem.Size = new System.Drawing.Size(59, 20);
            this.settingToolStripMenuItem.Text = "Setting";
            // 
            // comPortToolStripMenuItem
            // 
            this.comPortToolStripMenuItem.Name = "comPortToolStripMenuItem";
            this.comPortToolStripMenuItem.Size = new System.Drawing.Size(124, 22);
            this.comPortToolStripMenuItem.Text = "ComPort";
            this.comPortToolStripMenuItem.Click += new System.EventHandler(this.comPortToolStripMenuItem_Click);
            // 
            // StartButton
            // 
            this.StartButton.Name = "StartButton";
            this.StartButton.Size = new System.Drawing.Size(45, 20);
            this.StartButton.Text = "Start";
            this.StartButton.Click += new System.EventHandler(this.StartButton_Click);
            // 
            // NowPlayerTextBox
            // 
            this.NowPlayerTextBox.BackColor = System.Drawing.Color.White;
            this.NowPlayerTextBox.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.NowPlayerTextBox.Cursor = System.Windows.Forms.Cursors.No;
            this.NowPlayerTextBox.Font = new System.Drawing.Font("新細明體", 18F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(136)));
            this.NowPlayerTextBox.Location = new System.Drawing.Point(805, 29);
            this.NowPlayerTextBox.Name = "NowPlayerTextBox";
            this.NowPlayerTextBox.ReadOnly = true;
            this.NowPlayerTextBox.Size = new System.Drawing.Size(147, 29);
            this.NowPlayerTextBox.TabIndex = 17;
            this.NowPlayerTextBox.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // textBox4
            // 
            this.textBox4.BackColor = System.Drawing.Color.LightGreen;
            this.textBox4.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.textBox4.Cursor = System.Windows.Forms.Cursors.No;
            this.textBox4.Font = new System.Drawing.Font("新細明體", 18F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(136)));
            this.textBox4.ForeColor = System.Drawing.Color.Red;
            this.textBox4.Location = new System.Drawing.Point(646, 29);
            this.textBox4.Name = "textBox4";
            this.textBox4.ReadOnly = true;
            this.textBox4.Size = new System.Drawing.Size(153, 29);
            this.textBox4.TabIndex = 16;
            this.textBox4.Text = "目前玩家顏色";
            this.textBox4.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // NowPlayerNumberTextBox
            // 
            this.NowPlayerNumberTextBox.BackColor = System.Drawing.Color.White;
            this.NowPlayerNumberTextBox.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.NowPlayerNumberTextBox.Cursor = System.Windows.Forms.Cursors.No;
            this.NowPlayerNumberTextBox.Font = new System.Drawing.Font("新細明體", 18F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(136)));
            this.NowPlayerNumberTextBox.Location = new System.Drawing.Point(805, 66);
            this.NowPlayerNumberTextBox.Name = "NowPlayerNumberTextBox";
            this.NowPlayerNumberTextBox.ReadOnly = true;
            this.NowPlayerNumberTextBox.Size = new System.Drawing.Size(147, 29);
            this.NowPlayerNumberTextBox.TabIndex = 19;
            this.NowPlayerNumberTextBox.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // textBox6
            // 
            this.textBox6.BackColor = System.Drawing.Color.LightGreen;
            this.textBox6.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.textBox6.Cursor = System.Windows.Forms.Cursors.No;
            this.textBox6.Font = new System.Drawing.Font("新細明體", 18F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(136)));
            this.textBox6.ForeColor = System.Drawing.Color.Red;
            this.textBox6.Location = new System.Drawing.Point(646, 66);
            this.textBox6.Name = "textBox6";
            this.textBox6.ReadOnly = true;
            this.textBox6.Size = new System.Drawing.Size(153, 29);
            this.textBox6.TabIndex = 18;
            this.textBox6.Text = "目前玩家編號";
            this.textBox6.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.InformationBox);
            this.groupBox1.Font = new System.Drawing.Font("新細明體", 20.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(136)));
            this.groupBox1.Location = new System.Drawing.Point(646, 171);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(306, 410);
            this.groupBox1.TabIndex = 20;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "節點資訊";
            // 
            // InformationBox
            // 
            this.InformationBox.Font = new System.Drawing.Font("新細明體", 20.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(136)));
            this.InformationBox.FormattingEnabled = true;
            this.InformationBox.ItemHeight = 27;
            this.InformationBox.Location = new System.Drawing.Point(6, 39);
            this.InformationBox.Name = "InformationBox";
            this.InformationBox.Size = new System.Drawing.Size(294, 355);
            this.InformationBox.TabIndex = 0;
            // 
            // NowTotalPlayerNumberTextBox
            // 
            this.NowTotalPlayerNumberTextBox.BackColor = System.Drawing.Color.White;
            this.NowTotalPlayerNumberTextBox.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.NowTotalPlayerNumberTextBox.Cursor = System.Windows.Forms.Cursors.No;
            this.NowTotalPlayerNumberTextBox.Font = new System.Drawing.Font("新細明體", 18F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(136)));
            this.NowTotalPlayerNumberTextBox.Location = new System.Drawing.Point(805, 101);
            this.NowTotalPlayerNumberTextBox.Name = "NowTotalPlayerNumberTextBox";
            this.NowTotalPlayerNumberTextBox.ReadOnly = true;
            this.NowTotalPlayerNumberTextBox.Size = new System.Drawing.Size(147, 29);
            this.NowTotalPlayerNumberTextBox.TabIndex = 22;
            this.NowTotalPlayerNumberTextBox.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // textBox5
            // 
            this.textBox5.BackColor = System.Drawing.Color.LightGreen;
            this.textBox5.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.textBox5.Cursor = System.Windows.Forms.Cursors.No;
            this.textBox5.Font = new System.Drawing.Font("新細明體", 18F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(136)));
            this.textBox5.ForeColor = System.Drawing.Color.Red;
            this.textBox5.Location = new System.Drawing.Point(646, 101);
            this.textBox5.Name = "textBox5";
            this.textBox5.ReadOnly = true;
            this.textBox5.Size = new System.Drawing.Size(153, 29);
            this.textBox5.TabIndex = 21;
            this.textBox5.Text = "偵測畫面人數";
            this.textBox5.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // DriverGameStatusTextBox
            // 
            this.DriverGameStatusTextBox.BackColor = System.Drawing.Color.White;
            this.DriverGameStatusTextBox.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.DriverGameStatusTextBox.Cursor = System.Windows.Forms.Cursors.No;
            this.DriverGameStatusTextBox.Font = new System.Drawing.Font("新細明體", 18F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(136)));
            this.DriverGameStatusTextBox.Location = new System.Drawing.Point(805, 136);
            this.DriverGameStatusTextBox.Name = "DriverGameStatusTextBox";
            this.DriverGameStatusTextBox.ReadOnly = true;
            this.DriverGameStatusTextBox.Size = new System.Drawing.Size(147, 29);
            this.DriverGameStatusTextBox.TabIndex = 24;
            this.DriverGameStatusTextBox.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // textBox7
            // 
            this.textBox7.BackColor = System.Drawing.Color.LightGreen;
            this.textBox7.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.textBox7.Cursor = System.Windows.Forms.Cursors.No;
            this.textBox7.Font = new System.Drawing.Font("新細明體", 18F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(136)));
            this.textBox7.ForeColor = System.Drawing.Color.Red;
            this.textBox7.Location = new System.Drawing.Point(646, 136);
            this.textBox7.Name = "textBox7";
            this.textBox7.ReadOnly = true;
            this.textBox7.Size = new System.Drawing.Size(153, 29);
            this.textBox7.TabIndex = 23;
            this.textBox7.Text = "驅動遊戲狀態";
            this.textBox7.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // MainWindow
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(964, 596);
            this.Controls.Add(this.DriverGameStatusTextBox);
            this.Controls.Add(this.textBox7);
            this.Controls.Add(this.NowTotalPlayerNumberTextBox);
            this.Controls.Add(this.textBox5);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.NowPlayerNumberTextBox);
            this.Controls.Add(this.textBox6);
            this.Controls.Add(this.NowPlayerTextBox);
            this.Controls.Add(this.textBox4);
            this.Controls.Add(this.Title2);
            this.Controls.Add(this.Title1);
            this.Controls.Add(this.GameTimeValue);
            this.Controls.Add(this.GameTime);
            this.Controls.Add(this.StatusValue);
            this.Controls.Add(this.Status);
            this.Controls.Add(this.pictureBox1);
            this.Controls.Add(this.menuStrip1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.MainMenuStrip = this.menuStrip1;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "MainWindow";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "MainWindow";
            this.FormClosed += new System.Windows.Forms.FormClosedEventHandler(this.Form1_FormClosed);
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.groupBox1.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.PictureBox pictureBox1;
        private System.IO.Ports.SerialPort serialPort1;
        private System.Windows.Forms.Timer StartButtonTimer;
        private System.Windows.Forms.Timer GameTimer;
        private System.Windows.Forms.TextBox Status;
        private System.Windows.Forms.TextBox StatusValue;
        private System.Windows.Forms.TextBox GameTime;
        private System.Windows.Forms.TextBox GameTimeValue;
        private System.Windows.Forms.TextBox Title1;
        private System.Windows.Forms.Timer TextChangeTimer;
        private System.Windows.Forms.Timer ClearStart;
        private System.Windows.Forms.TextBox Title2;
        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem settingToolStripMenuItem;
        public System.Windows.Forms.ToolStripMenuItem comPortToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem StartButton;
        private System.Windows.Forms.TextBox NowPlayerTextBox;
        private System.Windows.Forms.TextBox textBox4;
        private System.Windows.Forms.TextBox NowPlayerNumberTextBox;
        private System.Windows.Forms.TextBox textBox6;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.ListBox InformationBox;
        private System.Windows.Forms.TextBox NowTotalPlayerNumberTextBox;
        private System.Windows.Forms.TextBox textBox5;
        private System.Windows.Forms.TextBox DriverGameStatusTextBox;
        private System.Windows.Forms.TextBox textBox7;
    }
}

