using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace Lab4_new_sdk_WF
{
    public partial class SettingParameter : Form
    {
        MainWindow f1 = null;

        public SettingParameter(MainWindow Temp)
        {
            InitializeComponent();
            f1 = Temp;
        }

        private void Form2_FormClosed(object sender, FormClosedEventArgs e)
        {
            this.Dispose();
        }

        private void SerialStartButton_Click(object sender, EventArgs e)
        {
            try
            {
                f1.GameTimeDefault = Convert.ToInt32(GameTime.Text);
                f1.ComPortComName = ComPortBox.Text;
                f1.ComPortBaudRate = BaudRateBox.Text;
                f1.ComPortParity = ParityBox.Text;
                f1.ComPortStopBit = StopBitsBox.Text;
                f1.WriteComPortToTxt();
                this.Close();
            }
            catch
            {
                MessageBox.Show("Setting fail!", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void Form2_Load(object sender, EventArgs e)
        {
            ComPortBox.Text = f1.ComPortComName;
            BaudRateBox.Text = f1.ComPortBaudRate;
            ParityBox.Text = f1.ComPortParity;
            StopBitsBox.Text = f1.ComPortStopBit;
        }

    }
}
