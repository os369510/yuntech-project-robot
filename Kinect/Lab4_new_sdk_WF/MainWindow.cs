using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Drawing.Imaging;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using Microsoft.Kinect;
using System.Runtime.InteropServices;
using System.IO.Ports;
using System.IO;

namespace Lab4_new_sdk_WF
{
    public partial class MainWindow : Form
    {
        //Initial
        public MainWindow()
        {
            InitializeComponent();
        }

        //private struct sPixelInformation{
        //    private Point sLocation_pixel ;
        //    private SkeletonPoint sLocation_cm;
        //    private Int32 sBGRA ;
        //    private int sUserIndex;
        //    private int sDepth;
        //}

        //ComPort
        public string ComPortSetting = "ComPortSetting.txt";
        public string ComPortComName = "";
        public string ComPortBaudRate = "";
        public string ComPortParity = "";
        public string ComPortStopBit = "";
        
        //RS232 set
        byte[] tx = new byte[8];
        //Initial
        uint GameStartFlag = 0;
        //timer
        public int TextChangeFlag = 0;
        //GameTime
        int GameTimeValued = 30;
        public Int32 GameTimeDefault=30;
        //Flag
        int StartButtonFlag = 0;
        //Player
        int NowPlayerIndex = 0;
        Boolean PlayerMarkFlag = false;

        int PhaseR1 = 180;
        int PhaseR2 = 90;
        int PhaseR3 = 90; //int PhaseR3StoE = 0; int PhaseR3EtoW = 0;
        int PhaseR4 = 90; //int PhaseR4EtoW = 0; int PhaseR4WtoH = 0;
        int PhaseL1 = 180;
        int PhaseL2 = 90;
        int PhaseL3 = 90; //int PhaseL3StoE = 0; int PhaseL3EtoW = 0;
        int PhaseL4 = 90; //int PhaseL4EtoW = 0; int PhaseL4WtoH = 0;

        double RadiansTransform = 180 / Math.PI;


        //***********************************************
        //******************UI***************************
        //***********************************************
        //Load
        private void Form1_Load(object sender, EventArgs e) //Window Initial
        {
            //Read ComPortSetting.txt
            ReadComPortFromTxt();
            //Timer
            TextChangeTimer.Start();
            //Initial
            GameTimeValue.Text = Convert.ToString(GameTimeValued);
            StatusValue.Text = "Wait";
        }

        //***********************************************
        //******************Kinect***********************
        //***********************************************
        #region Kinect Class
        //Kinect set initial
        KinectSensor sensor = KinectSensor.KinectSensors[0];
        
        Skeleton[] skeletons; //Skeleton
        //Skeleton sHaveUserSkeletons;
        byte[] pixelData; //RGB Image
        short[] pixelDataFingerUse; //Depth data
        int[] UserIndex;
        int[] DepthInformation;
        //int[] playercoded;

        List<JointCollection> jcs = new List<JointCollection>();

        Boolean Kinect_Initialize()
        {
            try
            {
                sensor.Start();
                sensor.ElevationAngle = 0;// -10;
                sensor.SkeletonFrameReady += new EventHandler<SkeletonFrameReadyEventArgs>(sensor_SkeletonFrameReady);
                sensor.ColorFrameReady += new EventHandler<ColorImageFrameReadyEventArgs>(sensor_ColorFrameReady);
                sensor.DepthFrameReady += new EventHandler<DepthImageFrameReadyEventArgs>(sensor_DepthFrameReady);
                //Skeleton smooth
                var parameter = new TransformSmoothParameters
                {
                    Smoothing = 0.3f,
                    Correction=0.0f,
                    Prediction=0.0f,
                    JitterRadius=1.0f,
                    MaxDeviationRadius=0.5f
                };
                sensor.SkeletonStream.Enable(parameter);
                sensor.SkeletonStream.Enable();
                //Color
                sensor.ColorStream.Enable(ColorImageFormat.RgbResolution640x480Fps30);
                sensor.ColorStream.Enable();
                //Depth
                sensor.DepthStream.Enable(DepthImageFormat.Resolution640x480Fps30);
                sensor.DepthStream.Enable();
                return true;
            }
            catch
            {
                return false;
            }
        }
        Boolean SerialPort_Initialize()
        {
            try
            {
                serialPort1.PortName = ComPortComName;
                serialPort1.BaudRate = Convert.ToInt32(ComPortBaudRate);
                switch (ComPortParity)
                {
                    case "None":
                        serialPort1.Parity = Parity.None;
                        break;
                    case "Odd":
                        serialPort1.Parity = Parity.Odd;
                        break;
                    case "Even":
                        serialPort1.Parity = Parity.Even;
                        break;
                }
                switch (ComPortStopBit)
                {
                    case "None":
                        serialPort1.StopBits = StopBits.None;
                        break;
                    case "One":
                        serialPort1.StopBits = StopBits.One;
                        break;
                    case "Two":
                        serialPort1.StopBits = StopBits.Two;
                        break;
                }
                serialPort1.Open();
                return true;
            }
            catch
            {
                return false;
            }
        }

        //Skeleton 
        void sensor_SkeletonFrameReady(object sender, SkeletonFrameReadyEventArgs e)
        {
            jcs.Clear();
            bool receivedData = false;
            UInt16 sTotalPlayer = 0;

            using (SkeletonFrame SFrame = e.OpenSkeletonFrame())
            {
                if (SFrame == null)
                {
                    // The image processing took too long. More than 2 frames behind.
                }
                else
                {
                    skeletons = new Skeleton[SFrame.SkeletonArrayLength];
                    SFrame.CopySkeletonDataTo(skeletons);
                    receivedData = true;
                }
            }

            if (receivedData)
            {
                foreach (Skeleton Data in skeletons)
                {
                    if (Data.TrackingState == SkeletonTrackingState.Tracked)
                    {
                        //sHaveUserSkeletons = Data;
                        sTotalPlayer += 1;
                        jcs.Add(Data.Joints);
                    }
                }
                NowTotalPlayerNumberTextBox.Text = sTotalPlayer.ToString();
                pictureBox1.Invalidate();
            }
        }

        //DepthFrame
        void sensor_DepthFrameReady(object sender, DepthImageFrameReadyEventArgs e)
        {
            using (DepthImageFrame DFrame = e.OpenDepthImageFrame())
            {
                if (DFrame != null)
                {
                    pixelDataFingerUse = new short[DFrame.PixelDataLength];
                    DFrame.CopyPixelDataTo(pixelDataFingerUse);
                    UserIndex = new int[pixelDataFingerUse.Length];
                    DepthInformation = new int[pixelDataFingerUse.Length];
                    //playercoded = new int[pixelDataFingerUse.Length];

                    for (int i = 0; i < DepthInformation.Length; i++)
                    {
                        UserIndex[i] = pixelDataFingerUse[i] & DepthImageFrame.PlayerIndexBitmask;
                        DepthInformation[i] = ((ushort)pixelDataFingerUse[i]) >> DepthImageFrame.PlayerIndexBitmaskWidth;
                        //playercoded[i] = 0;
                        //if ((UserIndex[i] & 0x1) == 0x1)
                        //    playercoded[i] |= 0xFF0000;

                        //if ((UserIndex[i] & 0x2) == 0x2)
                        //    playercoded[i] |= 0x00FF00;

                        //if ((UserIndex[i] & 0x4) == 0x4)
                        //    playercoded[i] |= 0x0000FF;

                    }
                    //pictureBox2.Image = IntToBitmap(playercoded, pictureBox2.Width, pictureBox2.Height);
                    //byte[] coloredFrame = GenerateColoredBytes(DFrame.Width, DFrame.Height, pixelDataFingerUse);
                    //IntPtr ctpr = Marshal.UnsafeAddrOfPinnedArrayElement(coloredFrame, 0);
                    //Bitmap am = new Bitmap(640, 480, 640*4 ,System.Drawing.Imaging.PixelFormat.Format32bppRgb, ctpr);
                    //pictureBox2.Image = am;
                }
            }
        }
        /*
        byte[] GenerateColoredBytes(int width, int height, short[] img)//Block3 //將黑白的深度影像轉換成彩色深度影像
        {
            //擷取影像相關參數

                short[] depthData = img;

                //每一個像素有 紅 + 綠 + 藍 + 空byte = 4 byte = 32 bits
                //BGR32 = 紅 + 綠 + 藍 + 空byte
                byte[] colorFrame = new byte[width * height * 4];

                //宣告每個顏色的位置索引
                const int Blue_index = 0;
                const int Green_index = 1;
                const int red_index = 2;
                int NumberY = 0;
                int NumberX = 0;

                int depthindex = 0;
                //用來逐一從dapthData裡一個一個加上去抓資料
                for (NumberY = 0; NumberY < height; NumberY++) //列迴圈
                {
                    int hightOffset = NumberY * width; //每一列最左邊的像素位置

                    //將顏色分成三段,以三種顏色表示
                    for (NumberX = 0; NumberX < width; NumberX++)
                    {
                        int distance = GetDistance(depthData[depthindex]);
                        //int index = ((width - x - 1) + hightOffset) * 4;
                        int index = (NumberX + hightOffset) * 4;
                        if (distance <= 900)//藍
                        {
                            colorFrame[index + Blue_index] = 255;
                            colorFrame[index + Green_index] = 0;
                            colorFrame[index + red_index] = 0;
                        }
                        else   //紅
                        {
                            colorFrame[index + Blue_index] = 0;
                            colorFrame[index + Green_index] = 255;
                            colorFrame[index + red_index] = 0;

                            if (NumberX >= (FingerArray[0] - 40) && NumberX <= (FingerArray[0] + 40) && NumberY >= (FingerArray[1] - 40) && NumberY <= (FingerArray[1] + 40)) FingerNumberR++;
                            if (NumberX >= (FingerArray[2] - 40) && NumberX <= (FingerArray[2] + 40) && NumberY >= (FingerArray[3] - 40) && NumberY <= (FingerArray[3] + 40)) FingerNumberL++;
                            
                        }
                        depthindex += 1;
                    }
                }
            return colorFrame;
        }

        int GetDistance(short first)
        {
            //int distance = (int)(first >> 3);
            int distance = (int)((first & 0x07) * 1500);
            return distance;
        }
        */

        //ColorFrame
        void sensor_ColorFrameReady(object sender, ColorImageFrameReadyEventArgs e)
        {
            bool receivedData = false;
            
            using (ColorImageFrame CFrame = e.OpenColorImageFrame())
            {
                if (CFrame == null)
                {
                    // The image processing took too long. More than 2 frames behind.
                }
                else
                {
                    pixelData = new byte[CFrame.PixelDataLength];
                    CFrame.CopyPixelDataTo(pixelData);
                    //GenerateColoredBytes(640, 480, pixelData);
                    receivedData = true;
                }
            }

            if (receivedData)
            {
                IntPtr ctpr = Marshal.UnsafeAddrOfPinnedArrayElement(pixelData, 0);
                Bitmap bm = new Bitmap(640, 480, 640 * 4, System.Drawing.Imaging.PixelFormat.Format32bppRgb, ctpr);

                pictureBox1.Image = bm;
            }

        }

        //Get Player Position
        Point GetDisplayPosition(SkeletonPoint jointPosition)
        {
            ColorImagePoint jPoint;

            jPoint = sensor.MapSkeletonPointToColor(jointPosition, ColorImageFormat.RgbResolution640x480Fps30);

            return new Point((int)(jPoint.X * pictureBox1.Width / 640), (int)(jPoint.Y * pictureBox1.Height / 480));
        }
        #endregion

        //Body Joint set
        JointType[] body = { JointType.HipCenter, JointType.Spine, JointType.ShoulderCenter, JointType.Head };
        JointType[] leftArm = { JointType.ShoulderCenter, JointType.ShoulderLeft, 
                                  JointType.ElbowLeft, JointType.WristLeft, JointType.HandLeft};
        JointType[] rightArm = { JointType.ShoulderCenter, JointType.ShoulderRight, 
                                   JointType.ElbowRight, JointType.WristRight, JointType.HandRight };
        JointType[] leftLeg = { JointType.HipCenter, JointType.HipLeft, JointType.KneeLeft, 
                                  JointType.AnkleLeft, JointType.FootLeft};
        JointType[] rightLeg = { JointType.HipCenter, JointType.HipRight, JointType.KneeRight,
                                   JointType.AnkleRight, JointType.FootRight};

        
        //Draw All Joint and Body
        private void pictureBox1_Paint(object sender, PaintEventArgs e)
        {
            JointType[][] lines = { body, leftArm, rightArm, leftLeg, rightLeg };

            Pen pen = new Pen(new SolidBrush(Color.FromArgb(0, 255, 0)), 5);
            Pen StartButton = new Pen(new SolidBrush(Color.FromArgb(50, 200, 50, 0)), 10);
            Pen HandUse = new Pen(new SolidBrush(Color.HotPink));
            Color[] sColorArray = { Color.Red, Color.Orange, Color.Yellow, Color.Green, Color.Blue, Color.Purple,Color.White,Color.Black };

            if (jcs.Count == 0)
            {
                if (GameTimer.Enabled == true)
                    GameOver(1);
                sPlayerInitialize();
            }
            foreach (JointCollection jc in jcs)
            {
                int sThisPlayerIndex = 0;

                #region Drawing
                //畫出所有身體,手,腳
                
                for (int i = 0; i < lines.Length; i++)
                {
                    List<Point> points = new List<Point>();
                    foreach (JointType jid in lines[i])
                        points.Add(GetDisplayPosition(jc[jid].Position));
                    try
                    {
                        /*pen = new Pen(new SolidBrush(sColorArray[UserIndex[
                            (int)(GetDisplayPosition(jc[JointType.Head].Position).X) +
                            ((int)(GetDisplayPosition(jc[JointType.Head].Position).Y-1)) * pictureBox1.Size.Width]]), 5);*/
                        pen = new Pen(new SolidBrush(sColorArray[
                            GetPlayerIndex(new Point(
                            (int)GetDisplayPosition(jc[JointType.Head].Position).X
                            , (int)GetDisplayPosition(jc[JointType.Head].Position).Y))
                            ]),5);
                    }
                    catch
                    {
                        pen = new Pen(new SolidBrush(Color.FromArgb(0, 255, 0)), 5);
                    }
                    e.Graphics.DrawLines(pen, points.ToArray());
                }

                //畫出所有關節
                foreach (JointType jid in Enum.GetValues(typeof(JointType)))
                {
                    Point p = GetDisplayPosition(jc[jid].Position);

                    e.Graphics.FillEllipse(Brushes.Red, p.X - 8, p.Y - 8, 17, 17);
                }
                #endregion

                #region Location Standard
                // Standard
                Point pHandRight = GetDisplayPosition(jc[JointType.HandRight].Position);
                Point pWristRight = GetDisplayPosition(jc[JointType.WristRight].Position);
                Point pElbowRight = GetDisplayPosition(jc[JointType.ElbowRight].Position);
                Point pShoulderRight = GetDisplayPosition(jc[JointType.ShoulderRight].Position);
                Point pHandLeft = GetDisplayPosition(jc[JointType.HandLeft].Position);
                Point pWristLeft = GetDisplayPosition(jc[JointType.WristLeft].Position);
                Point pElbowLeft = GetDisplayPosition(jc[JointType.ElbowLeft].Position);
                Point pShoulderLeft = GetDisplayPosition(jc[JointType.ShoulderLeft].Position);
                Point pHead = GetDisplayPosition(jc[JointType.Head].Position);
                SkeletonPoint HR = jc[JointType.HandRight].Position;
                SkeletonPoint WR = jc[JointType.WristRight].Position;
                SkeletonPoint ER = jc[JointType.ElbowRight].Position;
                SkeletonPoint SR = jc[JointType.ShoulderRight].Position;
                SkeletonPoint HL = jc[JointType.HandLeft].Position;
                SkeletonPoint WL = jc[JointType.WristLeft].Position;
                SkeletonPoint EL = jc[JointType.ElbowLeft].Position;
                SkeletonPoint SL = jc[JointType.ShoulderLeft].Position;
                SkeletonPoint Head = jc[JointType.Head].Position;
                //
                HR.X = (int)pHandRight.X;
                HR.Y = (int)pHandRight.Y;
                HR.Z = (int)(HR.Z * 100);
                WR.X = (int)pWristRight.X;
                WR.Y = (int)pWristRight.Y;
                WR.Z = (int)(WR.Z * 100);
                ER.X = (int)pElbowRight.X;
                ER.Y = (int)pElbowRight.Y;
                ER.Z = (int)(ER.Z * 100);
                SR.X = (int)pShoulderRight.X;
                SR.Y = (int)pShoulderRight.Y;
                SR.Z = (int)(SR.Z * 100);
                HL.X = (int)pHandLeft.X;
                HL.Y = (int)pHandLeft.Y;
                HL.Z = (int)(HL.Z * 100);
                WL.X = (int)pWristLeft.X;
                WL.Y = (int)pWristLeft.Y;
                WL.Z = (int)(WL.Z * 100);
                EL.X = (int)pElbowLeft.X;
                EL.Y = (int)pElbowLeft.Y;
                EL.Z = (int)(EL.Z * 100);
                SL.X = (int)pShoulderLeft.X;
                SL.Y = (int)pShoulderLeft.Y;
                SL.Z = (int)(SL.Z * 100);
                Head.X = (int)pHead.X;
                Head.Y = (int)pHead.Y;
                Head.Z = (int)(Head.Z * 100);
                #endregion

                #region before 2013/10/1
                /******************************************************/
                /* 2013/10/1 before use
                ////////////////////////////////////PhaseR2
                PhaseR2 = (int)(180 * Math.Atan((SR.Y - ER.Y) / (SR.X - ER.X)) / Math.PI);
                if (PhaseR2 >= 165 && PhaseR2 <= 255) PhaseR2 = PhaseR2 - 165;
                PhaseR2 = PhaseR2 + 90;
                if (PhaseR2 > 180) PhaseR2 = 180;
                if (PhaseR2 < 0) PhaseR2 = 0;
                ////////////////////////////////////PhaseL2
                PhaseL2 = (int)(180 * Math.Atan((SL.Y - EL.Y) / (SL.X - EL.X)) / Math.PI);
                if (PhaseL2 >= 165 && PhaseL2 <= 255) PhaseL2 = PhaseL2 - 165;
                PhaseL2 = PhaseL2 + 90;
                if (PhaseL2 > 180) PhaseL2 = 180;
                if (PhaseL2 < 0) PhaseL2 = 0;
                ////////////////////////////////////PhaseR3
                PhaseR3EtoW = (int)(180 * Math.Atan((ER.Y - WR.Y) / (ER.X - WR.X)) / Math.PI);
                PhaseR3StoE = (int)(180 * Math.Atan((SR.Y - ER.Y) / (SR.X - ER.X)) / Math.PI);
                if (PhaseR3EtoW < 0) PhaseR3EtoW = -PhaseR3EtoW;
                else PhaseR3EtoW = 180 - PhaseR3EtoW;
                PhaseR3StoE = 90 + PhaseR3StoE;
                if (ER.Y < WR.Y) PhaseR3EtoW = PhaseR3EtoW - 180;
                PhaseR3 = 360 - 90 - PhaseR3EtoW - PhaseR3StoE;
                if (PhaseR3 < 50) PhaseR3 = 50;
                if (PhaseR3 > 180) PhaseR3 = 180;
                ////////////////////////////////////PhaseL3
                PhaseL3EtoW = (int)(180 * Math.Atan((EL.Y - WL.Y) / (EL.X - WL.X)) / Math.PI);
                PhaseL3StoE = (int)(180 * Math.Atan((SL.Y - EL.Y) / (SL.X - EL.X)) / Math.PI);
                if (EL.X < WL.X) PhaseL3EtoW = PhaseL3EtoW + 180;
                PhaseL3StoE = 90 - PhaseL3StoE;
                PhaseL3 = 360 - 90 - PhaseL3EtoW - PhaseL3StoE;
                if (PhaseL3 < 50) PhaseL3 = 50;
                if (PhaseL3 > 180) PhaseL3 = 180;
                ////////////////////////////////////PhaseR4
                PhaseR4EtoW = (int)(180 * Math.Atan((ER.Y - WR.Y) / (ER.X - WR.X)) / Math.PI);
                PhaseR4WtoH = (int)(180 * Math.Atan((WR.Y - HR.Y) / (WR.X - HR.X)) / Math.PI);
                if (PhaseR4WtoH < 0) PhaseR4WtoH = -PhaseR4WtoH;
                else PhaseR4WtoH = 180 - PhaseR4WtoH;
                PhaseR4EtoW = 90 + PhaseR4EtoW;
                if (WR.Y < HR.Y) PhaseR4WtoH = PhaseR4WtoH - 180;
                PhaseR4 = 360 - 90 - PhaseR4WtoH - PhaseR4EtoW;
                if (WR.X < ER.X) PhaseR4 = PhaseR4 + 180;
                if (PhaseR4 < 90) PhaseR4 = 90;
                if (PhaseR4 > 270) PhaseR4 = 270;
                ////////////////////////////////////PhaseL4
                PhaseL4EtoW = (int)(180 * Math.Atan((EL.Y - WL.Y) / (EL.X - WL.X)) / Math.PI);
                PhaseL4WtoH = (int)(180 * Math.Atan((WL.Y - HL.Y) / (WL.X - HL.X)) / Math.PI);
                if (WL.X < HL.X) PhaseL4WtoH = PhaseL4WtoH + 180;
                PhaseL4EtoW = 90 - PhaseL4EtoW;
                PhaseL4 = 360 - 90 - PhaseL4WtoH - PhaseL4EtoW;
                if (WL.X > EL.X) PhaseL4 = PhaseL4 + 180;
                if (PhaseL4 < 90) PhaseL4 = 90;
                if (PhaseL4 > 270) PhaseL4 = 270;
                /*/

                /******************************************************/
              //  
#endregion

                sThisPlayerIndex = GetPlayerIndex(new Point(
                            (int)GetDisplayPosition(jc[JointType.Head].Position).X
                            , (int)GetDisplayPosition(jc[JointType.Head].Position).Y));

                if(NowPlayerIndex!=0 && sThisPlayerIndex!=NowPlayerIndex)
                    continue;

                //DriverGameStatusTextBox.Text = "等待開始";

                //after 2013/10/1
                /******************************************************/
                //Phase R1 nad Phase R2
                try //Compute
                {
                    RightArmCompute(SR.X, SR.Y, SR.Z, ER.X, ER.Y, ER.Z, WR.X, WR.Y, WR.Z, HR.X, HR.Y, HR.Z);
                    LeftArmCompute(SL.X, SL.Y, SL.Z, EL.X, EL.Y, EL.Z, WL.X, WL.Y, WL.Z, HL.X, HL.Y, HL.Z);
                }
                catch { }

                /******************************************************/
                /*
                FingerArray[0] = (int)HR.X ;
                FingerArray[1] = (int)HR.Y ;
                FingerArray[2] = (int)HL.X ;
                FingerArray[3] = (int)HL.Y ;
                e.Graphics.DrawRectangle(HandUse, FingerArray[0]-40, FingerArray[1]-40, 81, 81);
                e.Graphics.DrawRectangle(HandUse, FingerArray[2]-40, FingerArray[3]-40, 81, 81);*/

                if (pHandRight.X <= 590 && pHandRight.X >= 490 && pHandRight.Y <= 100 && pHandRight.Y >= 0
                    && pHandLeft.X <= 150 && pHandLeft.X >= 50 && pHandLeft.Y <= 100 && pHandLeft.Y >= 0)
                { // Check Location
                    //int sHandRIndex = -10;
                    //int sHandLIndex = -11;
                    //for (int i = -20; i <= 20; i++)
                    //{
                    //    try
                    //    {
                    //        if (sHandRIndex < GetPlayerIndex(new Point((int)HR.X, (int)HR.Y + i)))
                    //            sHandRIndex = GetPlayerIndex(new Point((int)HR.X, (int)HR.Y + i));
                    //        if (sHandLIndex < GetPlayerIndex(new Point((int)HL.X, (int)HL.Y + i)))
                    //            sHandLIndex = GetPlayerIndex(new Point((int)HL.X, (int)HL.Y + i));
                    //    }
                    //    catch { }
                    //}
                    //textBox1.Text = sHandRIndex.ToString();
                    //textBox2.Text = sHandLIndex.ToString();
                    //if (sHandRIndex == sHandLIndex)
                    //{
                    DriverGameStatusTextBox.Text = "準備開始";
                    if (PlayerMarkFlag == false) //updata user
                    {
                        NowPlayerIndex = sThisPlayerIndex; // get now player index
                        NowPlayerNumberTextBox.Text = NowPlayerIndex.ToString(); // print now player index
                        switch (NowPlayerIndex) // print now player color
                        {
                            case 0:
                                NowPlayerTextBox.Text = "Red";
                                break;
                            case 1:
                                NowPlayerTextBox.Text = "Orange";
                                break;
                            case 2:
                                NowPlayerTextBox.Text = "Yellow";
                                break;
                            case 3:
                                NowPlayerTextBox.Text = "Green";
                                break;
                            case 4:
                                NowPlayerTextBox.Text = "Blue";
                                break;
                            case 5:
                                NowPlayerTextBox.Text = "Purple";
                                break;
                            case 6:
                                NowPlayerTextBox.Text = "White";
                                break;
                            case 7:
                                NowPlayerTextBox.Text = "Black";
                                break;
                        }
                    }
                    StartButtonTimer.Start(); // wait 3 sec
                    //}
                }
                else
                {
                    StartButtonTimer.Stop();
                }
                if (GameStartFlag == 1)
                {
                    //HeadNew = (int)Head.Y;
                    //if (HeadNew > (HeadOld + 50))
                    //{
                    //    PhaseR1 = (int)((HR.X - SR.X) * (1.8));
                    //    PhaseR2 = 90;
                    //    PhaseR3 = 180;
                    //    PhaseR4 = 180;
                    //    PhaseL1 = (int)((SL.X - HL.X) * (1.8));
                    //    PhaseL2 = 90;
                    //    PhaseL3 = 180;
                    //    PhaseL4 = 180;
                    //    if (PhaseR1 >= 180) PhaseR1 = 180;
                    //    if (PhaseR1 <= 0) PhaseR1 = 0;
                    //    if (PhaseL1 >= 180) PhaseL1 = 180;
                    //    if (PhaseL1 <= 0) PhaseL1 = 0;
                    //}
                    Boolean CheckRootHere = false;
                    for (int i = -20; i <= 20; i++)
                    {
                        try
                        {
                            int flash_x = GetDisplayPosition(jc[JointType.Head].Position).X;
                            int flash_y = GetDisplayPosition(jc[JointType.Head].Position).Y;
                            if (GetPlayerIndex(new Point(flash_x, flash_y + i)) == NowPlayerIndex)
                                CheckRootHere = true;
                        }
                        catch { }
                    }
                    DriverGameStatusTextBox.Text = "遊戲進行中";
                    InformationBox.Items.Clear();
                    InformationBox.Items.Add("右手第一軸: " + PhaseR1.ToString().PadLeft(3,' '));
                    InformationBox.Items.Add("右手第二軸: " + PhaseR2.ToString().PadLeft(3, ' '));
                    InformationBox.Items.Add("右手第三軸: " + PhaseR3.ToString().PadLeft(3, ' '));
                    InformationBox.Items.Add("右手第四軸: " + PhaseR4.ToString().PadLeft(3, ' '));
                    InformationBox.Items.Add("左手第一軸: " + PhaseL1.ToString().PadLeft(3, ' '));
                    InformationBox.Items.Add("左手第二軸: " + PhaseL2.ToString().PadLeft(3, ' '));
                    InformationBox.Items.Add("左手第三軸: " + PhaseL3.ToString().PadLeft(3, ' '));
                    InformationBox.Items.Add("左手第四軸: " + PhaseL4.ToString().PadLeft(3, ' '));
                    tx[0] = (byte)PhaseR1;
                    tx[1] = (byte)PhaseR2;
                    tx[2] = (byte)PhaseR3;
                    tx[3] = (byte)PhaseR4;
                    tx[4] = (byte)PhaseL1;
                    tx[5] = (byte)PhaseL2;
                    tx[6] = (byte)PhaseL3;
                    tx[7] = (byte)PhaseL4;
                    if (CheckRootHere == false)
                    {
                        GameOver(1);
                        break;
                    }
                    serialPort1.Write(tx, 0, 8);
                    if (StartButtonFlag == 0)
                    {
                        PlayerMarkFlag = true;
                        e.Graphics.FillEllipse(Brushes.Yellow, 540 - 50, 50 - 50, 101, 101);
                        e.Graphics.FillEllipse(Brushes.Yellow, 100 - 50, 50 - 50, 101, 101);
                        ClearStart.Start();
                    }
                    StatusValue.Text = "Start";
                }

                if (GameStartFlag == 0)
                {
                    //DriverGameStatusTextBox.Text = "遊戲時間到";
                    //GameOver(0);
                    e.Graphics.FillEllipse(Brushes.Purple, 540 - 50, 50 - 50, 101, 101);
                    e.Graphics.FillEllipse(Brushes.Purple, 100 - 50, 50 - 50, 101, 101);
                    break;
                }
            }
        }

        void GameOver(int sTrigger) // 0:Time out , 1:unfind user
        {
            //HeadOld = (int)Head.Y;
            GameStartFlag = 0;
            GameTimeValued = GameTimeDefault;
            GameTimeValue.Text = Convert.ToString(GameTimeValued);
            StatusValue.ForeColor = Color.Black;
            StatusValue.Text = "Wait";

            tx[0] = 0;//R1
            tx[1] = 20; //R2
            tx[2] = 180;//R3
            tx[3] = 180; //R4
            tx[4] = 0;//L1
            tx[5] = 180; //L2
            tx[6] = 180; //L3
            tx[7] = 180; //L4

            GameTimer.Stop();

            switch (sTrigger)
            {
                case 0:
                    DriverGameStatusTextBox.Text = "遊戲時間到";    
                    break;
                case 1:
                    DriverGameStatusTextBox.Text = "主玩家消失";       
                    break;
            }

            serialPort1.Write(tx, 0, 8);
            PlayerMarkFlag = false;

            sPlayerInitialize();
        }

        private void sPlayerInitialize()
        {
            NowPlayerIndex = 0;
            NowPlayerNumberTextBox.Text = NowPlayerIndex.ToString(); // print now player index
            NowPlayerTextBox.Text = "Nothing";          // print now player color
        }

        Bitmap IntToBitmap(int[] array, int w, int h)
        {
            Bitmap bmap = new Bitmap(w, h, PixelFormat.Format32bppRgb);
            BitmapData bmapdata = bmap.LockBits(new Rectangle(0, 0, w, h), ImageLockMode.WriteOnly, bmap.PixelFormat);
            IntPtr ptr = bmapdata.Scan0;
            Marshal.Copy(array, 0, ptr, array.Length);
            bmap.UnlockBits(bmapdata);
            return bmap;
        }

        //Get Player Index
        private int GetPlayerIndex(Point sPoint)
        {
            int sPlayerIndex=-5;
            for (int i = -10; i <= 10; i++)
            {
                try
                {
                    if(sPlayerIndex<UserIndex[((sPoint.Y - 2) * 640 + sPoint.X)])
                        sPlayerIndex = UserIndex[((sPoint.Y - 2) * 640 + sPoint.X)];
                }
                catch { }
            }

            return sPlayerIndex;
        }

        //Form close
        private void Form1_FormClosed(object sender, FormClosedEventArgs e)
        {
            sensor.Stop();
            serialPort1.Close();
        }

        //Start Button
        private void StartButtonTimer_Tick(object sender, EventArgs e)
        {
            GameStartFlag = 1;
            StartButtonFlag = 0;
            GameTimer.Start();
        }

        //Game Time
        private void GameTimer_Tick(object sender, EventArgs e)
        {
            GameTimeValued--;
            GameTimeValue.Text = Convert.ToString(GameTimeValued);
            if (GameTimeValued == 0)
            {
                DriverGameStatusTextBox.Text = "遊戲時間到";
                tx[0] = 0;//R1
                tx[1] = 20; //R2
                tx[2] = 180;//R3
                tx[3] = 180; //R4
                tx[4] = 0;//L1
                tx[5] = 180; //L2
                tx[6] = 180; //L3
                tx[7] = 180; //L4
                serialPort1.Write(tx, 0, 8);
                GameTimer.Stop();
                GameOver(0);
                GameStartFlag = 0;
            }
        }

        //Title color change
        private void TextChangeTimer_Tick(object sender, EventArgs e)
        {
            if (TextChangeFlag == 0)
            {
                Title1.ForeColor = Color.Red;
                Title2.ForeColor = Color.Red;
            }
            if (TextChangeFlag == 1)
            {
                Title1.ForeColor = Color.MediumBlue;
                Title2.ForeColor = Color.MediumBlue;
            }
            TextChangeFlag++;
            if (TextChangeFlag == 2) { TextChangeFlag = 0; }

        }

        //Start button clear
        private void ClearStart_Tick(object sender, EventArgs e)
        {
            StartButtonFlag = 1;
        }


        private void RightArmCompute(double SRx, double SRy, double SRz,
                                          double ERx, double ERy, double ERz,
                                          double WRx, double WRy, double WRz,
                                          double HRx, double HRy, double HRz) //Left Hand compute method
        {
            double ae = 0;
            double be = 0;
            double ce = 0;
            double acr1 = 0;
            double bcr1 = 0;
            double ccr1 = 0;
            double Acr3 = 0;
            double Bcr3 = 0;
            double Ccr3 = 0;
            double Acr4 = 0;
            double Bcr4 = 0;
            double Ccr4 = 0;
            int newCr1 = 0;
            int newCr2 = 0;
            int newCr3 = 0;
            int newCr4 = 0;
            int oldCr1 = 0;
            int oldCr2 = 0;
            int oldCr3 = 0;
            int oldCr4 = 0;
            //phase R1 and R2
            switch ((ERz - SRz) <= 0)
            {
                case (true):
                    //ae = Math.Sqrt(Math.Pow((WRz - SRz), 2) + Math.Pow((ERy - SRy), 2));
                    ae = Math.Sqrt(Math.Pow((ERz - SRz), 2) + Math.Pow((ERy - SRy), 2));
                    be = Math.Sqrt(Math.Pow((ERx - SRx), 2) + Math.Pow((ERz - SRz), 2) + Math.Pow((ERy - SRy), 2));
                    //ce = Math.Sqrt(Math.Pow((ERx - SRx), 2) + Math.Pow((WRz - ERz), 2));
                    ce = Math.Sqrt(Math.Pow((ERx - SRx), 2) + Math.Pow((ERz - ERz), 2));
                    newCr2 = (int)(Math.Acos((Math.Pow(ae, 2) + Math.Pow(be, 2) - Math.Pow(ce, 2)) / (2 * ae * be)) * RadiansTransform);
                    acr1 = ae;
                    bcr1 = acr1;
                    //ccr1 = Math.Sqrt(Math.Pow(ERy - (SRy - bcr1), 2) + Math.Pow(WRz - SRz, 2));
                    ccr1 = Math.Sqrt(Math.Pow(ERy - (SRy - bcr1), 2) + Math.Pow(ERz - SRz, 2));
                    newCr1 = (int)((Math.Acos((Math.Pow(acr1, 2) + Math.Pow(bcr1, 2) - Math.Pow(ccr1, 2)) / (2 * acr1 * bcr1))) * RadiansTransform);
                    break;
                default:  //mean case (false):
                    //ae = Math.Sqrt(Math.Pow((WRz - SRz), 2) + Math.Pow((ERy - SRy), 2));
                    ae = Math.Sqrt(Math.Pow((ERz - SRz), 2) + Math.Pow((ERy - SRy), 2));
                    be = Math.Sqrt(Math.Pow((ERx - SRx), 2) + Math.Pow((ERz - SRz), 2) + Math.Pow((ERy - SRy), 2));
                    //ce = Math.Sqrt(Math.Pow((ERx - SRx), 2) + Math.Pow((WRz - ERz), 2));
                    ce = Math.Sqrt(Math.Pow((ERx - SRx), 2) + Math.Pow((ERz - ERz), 2));
                    newCr2 = 180 - (int)(Math.Acos((Math.Pow(ae, 2) + Math.Pow(be, 2) - Math.Pow(ce, 2)) / (2 * ae * be)) * RadiansTransform);
                    acr1 = ae;
                    bcr1 = acr1;
                    //ccr1 = Math.Sqrt(Math.Pow(ERy - (SRy - bcr1), 2) + Math.Pow(WRz - SRz, 2));
                    ccr1 = Math.Sqrt(Math.Pow(ERy - (SRy - bcr1), 2) + Math.Pow(ERz - SRz, 2));
                    newCr1 = 180 - (int)((Math.Acos((Math.Pow(acr1, 2) + Math.Pow(bcr1, 2) - Math.Pow(ccr1, 2)) / (2 * acr1 * bcr1))) * RadiansTransform);
                    break;
            }
            if (newCr1 <= 180 && newCr1 >= 0)
                oldCr1 = newCr1;
            if (newCr2 <= 180 && newCr2 >= 0)
                oldCr2 = newCr2;
            //Phase R3
            Acr3 = be;
            Bcr3 = Math.Sqrt(Math.Pow(ERx - WRx, 2) + Math.Pow(ERy - WRy, 2) + Math.Pow(ERz - WRz, 2));
            Ccr3 = Math.Sqrt(Math.Pow(WRx - SRx, 2) + Math.Pow(WRy - SRy, 2) + Math.Pow(WRz - SRz, 2));
            newCr3 = (int)((Math.Acos((Math.Pow(Acr3, 2) + Math.Pow(Bcr3, 2) - Math.Pow(Ccr3, 2)) / (2 * Acr3 * Bcr3)))*RadiansTransform);
            if (newCr3 <= 180 && newCr3 >= 0)
                oldCr3 = newCr3;
            //Phase R4
            Acr4 = Math.Sqrt(Math.Pow(WRx - HRx, 2) + Math.Pow(WRy - HRy, 2) + Math.Pow(WRz - HRz, 2));
            Bcr4 = Math.Sqrt(Math.Pow(WRx - ERx, 2) + Math.Pow(WRy - ERy, 2) + Math.Pow(WRz - ERz, 2));
            Ccr4 = Math.Sqrt(Math.Pow(HRx - ERx, 2) + Math.Pow(HRy - ERy, 2) + Math.Pow(HRz - ERz, 2));
            newCr4 = (int)((Math.Acos((Math.Pow(Acr4, 2) + Math.Pow(Bcr4, 2) - Math.Pow(Ccr4, 2)) / (2 * Acr4 * Bcr4))) * RadiansTransform);
            if (newCr4 <= 180 && newCr4 >= 0)
                oldCr4 = newCr4;
            PhaseR1 = oldCr1;
            PhaseR2 = oldCr2;
            PhaseR3 = oldCr3;
            PhaseR4 = oldCr4;
        }

        private void LeftArmCompute(double SLx, double SLy, double SLz,
                                          double ELx, double ELy, double ELz,
                                          double WLx, double WLy, double WLz,
                                          double HLx, double HLy, double HLz) //Left Arm compute method
        {
            double ae = 0;
            double be = 0;
            double ce = 0;
            double acr1 = 0;
            double bcr1 = 0;
            double ccr1 = 0;
            double Acr3 = 0;
            double Bcr3 = 0;
            double Ccr3 = 0;
            double Acr4 = 0;
            double Bcr4 = 0;
            double Ccr4 = 0;
            int newCr1 = 0;
            int newCr2 = 0;
            int newCr3 = 0;
            int newCr4 = 0;
            int oldCr1 = 0;
            int oldCr2 = 0;
            int oldCr3 = 0;
            int oldCr4 = 0;
            //phase L1 and L2
            switch ((ELz - SLz) <= 0)
            {
                case (true):
                    //ae = Math.Sqrt(Math.Pow((WLz - SLz), 2) + Math.Pow((ELy - SLy), 2));
                    ae = Math.Sqrt(Math.Pow((ELz - SLz), 2) + Math.Pow((ELy - SLy), 2));
                    be = Math.Sqrt(Math.Pow((ELx - SLx), 2) + Math.Pow((ELz - SLz), 2) + Math.Pow((ELy - SLy), 2));
                    //ce = Math.Sqrt(Math.Pow((ELx - SLx), 2) + Math.Pow((WLz - ELz), 2));
                    ce = Math.Sqrt(Math.Pow((ELx - SLx), 2) + Math.Pow((ELz - ELz), 2));
                    newCr2 = (int)(Math.Acos((Math.Pow(ae, 2) + Math.Pow(be, 2) - Math.Pow(ce, 2)) / (2 * ae * be)) * RadiansTransform);
                    acr1 = ae;
                    bcr1 = acr1;
                    ccr1 = Math.Sqrt(Math.Pow(ELy - (SLy - bcr1), 2) + Math.Pow(ELz - SLz, 2));
                    //ccr1 = Math.Sqrt(Math.Pow(ELy - (SLy - bcr1), 2) + Math.Pow(WLz - SLz, 2));
                    newCr1 = (int)((Math.Acos((Math.Pow(acr1, 2) + Math.Pow(bcr1, 2) - Math.Pow(ccr1, 2)) / (2 * acr1 * bcr1))) * RadiansTransform);
                    break;
                default:  //mean case (false):
                    //ae = Math.Sqrt(Math.Pow((WLz - SLz), 2) + Math.Pow((ELy - SLy), 2));
                    ae = Math.Sqrt(Math.Pow((ELz - SLz), 2) + Math.Pow((ELy - SLy), 2));
                    be = Math.Sqrt(Math.Pow((ELx - SLx), 2) + Math.Pow((ELz - SLz), 2) + Math.Pow((ELy - SLy), 2));
                    //ce = Math.Sqrt(Math.Pow((ELx - SLx), 2) + Math.Pow((WLz - ELz), 2));
                    ce = Math.Sqrt(Math.Pow((ELx - SLx), 2) + Math.Pow((ELz - ELz), 2));
                    newCr2 = 180- (int)(Math.Acos((Math.Pow(ae, 2) + Math.Pow(be, 2) - Math.Pow(ce, 2)) / (2 * ae * be)) * RadiansTransform);
                    acr1 = ae;
                    bcr1 = acr1;
                    ccr1 = Math.Sqrt(Math.Pow(ELy - (SLy - bcr1), 2) + Math.Pow(ELz - SLz, 2));
                    //ccr1 = Math.Sqrt(Math.Pow(ELy - (SLy - bcr1), 2) + Math.Pow(WLz - SLz, 2));
                    newCr1 = 180- (int)((Math.Acos((Math.Pow(acr1, 2) + Math.Pow(bcr1, 2) - Math.Pow(ccr1, 2)) / (2 * acr1 * bcr1))) * RadiansTransform);
                    break;
            }
            if (newCr1 <= 180 && newCr1 >= 0)
                oldCr1 = newCr1;
            if (newCr2 <= 180 && newCr2 >= 0)
                oldCr2 = newCr2;
            //Phase L3
            Acr3 = be;
            Bcr3 = Math.Sqrt(Math.Pow(ELx - WLx, 2) + Math.Pow(ELy - WLy, 2) + Math.Pow(ELz - WLz, 2));
            Ccr3 = Math.Sqrt(Math.Pow(WLx - SLx, 2) + Math.Pow(WLy - SLy, 2) + Math.Pow(WLz - SLz, 2));
            newCr3 = (int)((Math.Acos((Math.Pow(Acr3, 2) + Math.Pow(Bcr3, 2) - Math.Pow(Ccr3, 2)) / (2 * Acr3 * Bcr3))) * RadiansTransform);
            if (newCr3 <= 180 && newCr3 >= 0)
                oldCr3 = newCr3;
            //Phase L4
            Acr4 = Math.Sqrt(Math.Pow(WLx - HLx, 2) + Math.Pow(WLy - HLy, 2) + Math.Pow(WLz - HLz, 2));
            Bcr4 = Math.Sqrt(Math.Pow(WLx - ELx, 2) + Math.Pow(WLy - ELy, 2) + Math.Pow(WLz - ELz, 2));
            Ccr4 = Math.Sqrt(Math.Pow(HLx - ELx, 2) + Math.Pow(HLy - ELy, 2) + Math.Pow(HLz - ELz, 2));
            newCr4 = (int)((Math.Acos((Math.Pow(Acr4, 2) + Math.Pow(Bcr4, 2) - Math.Pow(Ccr4, 2)) / (2 * Acr4 * Bcr4))) * RadiansTransform);
            if (newCr4 <= 180 && newCr4 >= 0)
                oldCr4 = newCr4;
         //   textBox1.Text = ae.ToString();
          //  textBox2.Text = be.ToString();
           // textBox3.Text = newCr1.ToString();
        //    textBox4.Text = newCr2.ToString();
         //   textBox5.Text = newCr3.ToString();
         //   textBox6.Text = newCr4.ToString();
            PhaseL1 = oldCr1;
            PhaseL2 = oldCr2;
            PhaseL3 = oldCr3;
            PhaseL4 = oldCr4;
        }

        private void comPortToolStripMenuItem_Click(object sender, EventArgs e)
        {
            comPortToolStripMenuItem.Enabled = false;
            SettingParameter f2 = new SettingParameter(this);
            f2.Show();
        }

        private void StartButton_Click(object sender, EventArgs e)
        {
            GameTimeValued = GameTimeDefault;
            //kinect
            if (Kinect_Initialize() == false)
                MessageBox.Show("Kinect Initial fail!", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            //serial
            if (SerialPort_Initialize() == false)
                MessageBox.Show("SerialPort Initial fail!", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
        }


        public void WriteComPortToTxt()
        {
            StreamWriter SW = new StreamWriter(ComPortSetting, false);
            SW.WriteLine(ComPortComName);
            SW.WriteLine(ComPortBaudRate);
            SW.WriteLine(ComPortParity);
            SW.WriteLine(ComPortStopBit);
            SW.Close();
        }
        
        public void ReadComPortFromTxt()
        {
            string All;
            char[] sp = { '\r','\n' };
            StreamReader SR = new StreamReader(ComPortSetting);
            All = SR.ReadToEnd();
            SR.Close();
            string[] AfterSP = All.Split(sp);
            ComPortComName = AfterSP[0];
            ComPortBaudRate = AfterSP[2];
            ComPortParity = AfterSP[4];
            ComPortStopBit = AfterSP[6];
        }

        


    }
}
