using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO.Ports;

namespace Panel
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            string[] ports = SerialPort.GetPortNames();  //Tespit edilen seri portlar diziye eklenir.
            foreach (string port in ports)
            PortKutu.Items.Add(port); //Diziye eklenen portlar PortKutu'ya eklenir.
        }

        private void PortKutu_SelectedIndexChanged(object sender, EventArgs e)
        {
            serialPort1.PortName = PortKutu.SelectedItem.ToString(); //PortKutu'da seçili olan portu asıl port olarak ata.
            serialPort1.Open(); //Belirlenen portu aç.
        }

        private void Servo0Btn_Click(object sender, EventArgs e)
        {
            serialPort1.Write("0");    //Servoyu 0 dereceye gönderir.
            Konsol.Text += "Servo 0 dereceye gönderildi.\r\n";
        }

        private void Servo90Btn_Click(object sender, EventArgs e)
        {
            serialPort1.Write("1");    //Servoyu 90 dereceye gönderir.
            Konsol.Text += "Servo 90 dereceye gönderildi.\r\n";
        }

        private void Role1ABtn_Click(object sender, EventArgs e)
        {
            serialPort1.Write("2");    //1. röleyi aktif hale getirir.
            Konsol.Text += "Röle 1 aktif hale getirildi.\r\n";
        }

        private void Role1PBtn_Click(object sender, EventArgs e)
        {
            serialPort1.Write("3");    //1. röleyi pasif hale getirir.
            Konsol.Text += "Röle 1 pasif hale getirildi.\r\n";
        }

        private void Role2ABtn_Click(object sender, EventArgs e)
        {
            serialPort1.Write("4");    //2. röleyi aktif hale getirir.
            Konsol.Text += "Röle 2 aktif hale getirildi.\r\n";
        }

        private void Role2PBtn_Click(object sender, EventArgs e)
        {
            serialPort1.Write("5");    //2. röleyi pasif hale getirir.
            Konsol.Text += "Röle 2 pasif hale getirildi.\r\n";
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            if (serialPort1.IsOpen) serialPort1.Close();  //Uygulama kapanınca portun kapanmasını sağlar.
        }

        private void Konsol_TextChanged(object sender, EventArgs e)
        {
            Konsol.ScrollBars = ScrollBars.Both;
            Konsol.SelectionStart = Konsol.Text.Length;
            Konsol.ScrollToCaret();
        }

        private void serialPort1_DataReceived(object sender, System.IO.Ports.SerialDataReceivedEventArgs e)
        {
            while (true) {
                
                if (serialPort1.ReadLine().Contains("ikiHata")) 
                    { label4.Invoke(new Action(() => label4.Text = "Uyarı Var!")); panel3.BackColor = Color.Crimson;
                      label5.Invoke(new Action(() => label5.Text = "Uyarı Var!")); panel4.BackColor = Color.Crimson; }

                else if(serialPort1.ReadLine().Contains("gaz")) 
                    { label5.Invoke(new Action(() => label5.Text = "Uyarı Var!")); panel4.BackColor = Color.Crimson;
                      label4.Invoke(new Action(() => label4.Text = "Uyarı Yok")); panel3.BackColor = Color.GreenYellow; }

                else if (serialPort1.ReadLine().Contains("mesafe"))
                    { label5.Invoke(new Action(() => label5.Text = "Uyarı Yok")); panel4.BackColor = Color.GreenYellow;
                      label4.Invoke(new Action(() => label4.Text = "Uyarı Var!")); panel3.BackColor = Color.Crimson; } 

                else { label5.Invoke(new Action(() => label5.Text = "Uyarı Yok")); panel4.BackColor = Color.GreenYellow;
                       label4.Invoke(new Action(() => label4.Text = "Uyarı Yok")); panel3.BackColor = Color.GreenYellow; }

            }

        }
    }
}
