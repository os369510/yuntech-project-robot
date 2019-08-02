namespace Lab4_new_sdk_WF
{
    partial class SettingParameter
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            f1.comPortToolStripMenuItem.Enabled = true;
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.BaudRateBox = new System.Windows.Forms.ComboBox();
            this.StopBitsBox = new System.Windows.Forms.ComboBox();
            this.ParityBox = new System.Windows.Forms.ComboBox();
            this.SerialStartButton = new System.Windows.Forms.Button();
            this.ComPortBox = new System.Windows.Forms.ComboBox();
            this.label7 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.GameTime = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // BaudRateBox
            // 
            this.BaudRateBox.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.BaudRateBox.Font = new System.Drawing.Font("新細明體", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(136)));
            this.BaudRateBox.FormattingEnabled = true;
            this.BaudRateBox.ImeMode = System.Windows.Forms.ImeMode.NoControl;
            this.BaudRateBox.Items.AddRange(new object[] {
            "300",
            "600",
            "1200",
            "2400",
            "4800",
            "9600"});
            this.BaudRateBox.Location = new System.Drawing.Point(131, 74);
            this.BaudRateBox.Name = "BaudRateBox";
            this.BaudRateBox.Size = new System.Drawing.Size(125, 24);
            this.BaudRateBox.TabIndex = 87;
            // 
            // StopBitsBox
            // 
            this.StopBitsBox.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.StopBitsBox.Font = new System.Drawing.Font("新細明體", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(136)));
            this.StopBitsBox.FormattingEnabled = true;
            this.StopBitsBox.ImeMode = System.Windows.Forms.ImeMode.NoControl;
            this.StopBitsBox.Items.AddRange(new object[] {
            "None",
            "One",
            "Two"});
            this.StopBitsBox.Location = new System.Drawing.Point(131, 156);
            this.StopBitsBox.Name = "StopBitsBox";
            this.StopBitsBox.Size = new System.Drawing.Size(125, 24);
            this.StopBitsBox.TabIndex = 86;
            // 
            // ParityBox
            // 
            this.ParityBox.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.ParityBox.Font = new System.Drawing.Font("新細明體", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(136)));
            this.ParityBox.FormattingEnabled = true;
            this.ParityBox.ImeMode = System.Windows.Forms.ImeMode.NoControl;
            this.ParityBox.Items.AddRange(new object[] {
            "None",
            "Odd",
            "Even"});
            this.ParityBox.Location = new System.Drawing.Point(131, 115);
            this.ParityBox.Name = "ParityBox";
            this.ParityBox.Size = new System.Drawing.Size(125, 24);
            this.ParityBox.TabIndex = 85;
            // 
            // SerialStartButton
            // 
            this.SerialStartButton.Cursor = System.Windows.Forms.Cursors.Hand;
            this.SerialStartButton.Font = new System.Drawing.Font("新細明體", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(136)));
            this.SerialStartButton.Location = new System.Drawing.Point(63, 279);
            this.SerialStartButton.Name = "SerialStartButton";
            this.SerialStartButton.Size = new System.Drawing.Size(146, 30);
            this.SerialStartButton.TabIndex = 84;
            this.SerialStartButton.Text = "SaveAndLeave";
            this.SerialStartButton.UseVisualStyleBackColor = true;
            this.SerialStartButton.Click += new System.EventHandler(this.SerialStartButton_Click);
            // 
            // ComPortBox
            // 
            this.ComPortBox.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.ComPortBox.Font = new System.Drawing.Font("新細明體", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(136)));
            this.ComPortBox.FormattingEnabled = true;
            this.ComPortBox.ImeMode = System.Windows.Forms.ImeMode.NoControl;
            this.ComPortBox.Items.AddRange(new object[] {
            "COM1",
            "COM2",
            "COM3",
            "COM4",
            "COM5",
            "COM6",
            "COM7",
            "COM8",
            "COM9",
            "COM10",
            "COM11",
            "COM12",
            "COM13",
            "COM14",
            "COM15",
            "COM16",
            "COM17",
            "COM18",
            "COM19",
            "COM20"});
            this.ComPortBox.Location = new System.Drawing.Point(131, 33);
            this.ComPortBox.Name = "ComPortBox";
            this.ComPortBox.Size = new System.Drawing.Size(125, 24);
            this.ComPortBox.TabIndex = 83;
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Font = new System.Drawing.Font("新細明體", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(136)));
            this.label7.Location = new System.Drawing.Point(29, 118);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(44, 16);
            this.label7.TabIndex = 82;
            this.label7.Text = "Parity";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Font = new System.Drawing.Font("新細明體", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(136)));
            this.label5.Location = new System.Drawing.Point(29, 159);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(60, 16);
            this.label5.TabIndex = 81;
            this.label5.Text = "StopBits";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("新細明體", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(136)));
            this.label3.Location = new System.Drawing.Point(29, 36);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(67, 16);
            this.label3.TabIndex = 80;
            this.label3.Text = "Com Port";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("新細明體", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(136)));
            this.label2.Location = new System.Drawing.Point(29, 77);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(69, 16);
            this.label2.TabIndex = 79;
            this.label2.Text = "BaudRate";
            // 
            // GameTime
            // 
            this.GameTime.Location = new System.Drawing.Point(131, 203);
            this.GameTime.Name = "GameTime";
            this.GameTime.Size = new System.Drawing.Size(125, 22);
            this.GameTime.TabIndex = 88;
            this.GameTime.Text = "30";
            this.GameTime.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("新細明體", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(136)));
            this.label1.Location = new System.Drawing.Point(29, 203);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(77, 16);
            this.label1.TabIndex = 89;
            this.label1.Text = "GameTime";
            // 
            // SettingParameter
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(284, 330);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.GameTime);
            this.Controls.Add(this.BaudRateBox);
            this.Controls.Add(this.StopBitsBox);
            this.Controls.Add(this.ParityBox);
            this.Controls.Add(this.SerialStartButton);
            this.Controls.Add(this.ComPortBox);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Name = "SettingParameter";
            this.Text = "Form2";
            this.FormClosed += new System.Windows.Forms.FormClosedEventHandler(this.Form2_FormClosed);
            this.Load += new System.EventHandler(this.Form2_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        public System.Windows.Forms.ComboBox BaudRateBox;
        public System.Windows.Forms.ComboBox StopBitsBox;
        public System.Windows.Forms.ComboBox ParityBox;
        private System.Windows.Forms.Button SerialStartButton;
        public System.Windows.Forms.ComboBox ComPortBox;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox GameTime;
        private System.Windows.Forms.Label label1;
    }
}