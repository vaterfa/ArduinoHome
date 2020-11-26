
namespace Panel
{
    partial class Form1
    {
        /// <summary>
        ///Gerekli tasarımcı değişkeni.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///Kullanılan tüm kaynakları temizleyin.
        /// </summary>
        ///<param name="disposing">yönetilen kaynaklar dispose edilmeliyse doğru; aksi halde yanlış.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer üretilen kod

        /// <summary>
        /// Tasarımcı desteği için gerekli metot - bu metodun 
        ///içeriğini kod düzenleyici ile değiştirmeyin.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.PortKutu = new System.Windows.Forms.ComboBox();
            this.Servo90Btn = new System.Windows.Forms.Button();
            this.Servo0Btn = new System.Windows.Forms.Button();
            this.panel1 = new System.Windows.Forms.Panel();
            this.label1 = new System.Windows.Forms.Label();
            this.panel2 = new System.Windows.Forms.Panel();
            this.label2 = new System.Windows.Forms.Label();
            this.Role2ABtn = new System.Windows.Forms.Button();
            this.Role2PBtn = new System.Windows.Forms.Button();
            this.Role1ABtn = new System.Windows.Forms.Button();
            this.Role1PBtn = new System.Windows.Forms.Button();
            this.serialPort1 = new System.IO.Ports.SerialPort(this.components);
            this.label3 = new System.Windows.Forms.Label();
            this.Konsol = new System.Windows.Forms.TextBox();
            this.panel3 = new System.Windows.Forms.Panel();
            this.label4 = new System.Windows.Forms.Label();
            this.panel4 = new System.Windows.Forms.Panel();
            this.label5 = new System.Windows.Forms.Label();
            this.panel1.SuspendLayout();
            this.panel2.SuspendLayout();
            this.panel3.SuspendLayout();
            this.panel4.SuspendLayout();
            this.SuspendLayout();
            // 
            // PortKutu
            // 
            this.PortKutu.FormattingEnabled = true;
            this.PortKutu.Location = new System.Drawing.Point(12, 22);
            this.PortKutu.Name = "PortKutu";
            this.PortKutu.Size = new System.Drawing.Size(219, 21);
            this.PortKutu.TabIndex = 0;
            this.PortKutu.SelectedIndexChanged += new System.EventHandler(this.PortKutu_SelectedIndexChanged);
            // 
            // Servo90Btn
            // 
            this.Servo90Btn.Location = new System.Drawing.Point(112, 27);
            this.Servo90Btn.Name = "Servo90Btn";
            this.Servo90Btn.Size = new System.Drawing.Size(103, 40);
            this.Servo90Btn.TabIndex = 1;
            this.Servo90Btn.Text = "Servo 90 Derece";
            this.Servo90Btn.UseVisualStyleBackColor = true;
            this.Servo90Btn.Click += new System.EventHandler(this.Servo90Btn_Click);
            // 
            // Servo0Btn
            // 
            this.Servo0Btn.Location = new System.Drawing.Point(3, 27);
            this.Servo0Btn.Name = "Servo0Btn";
            this.Servo0Btn.Size = new System.Drawing.Size(103, 40);
            this.Servo0Btn.TabIndex = 1;
            this.Servo0Btn.Text = "Servo 0 Derece";
            this.Servo0Btn.UseVisualStyleBackColor = true;
            this.Servo0Btn.Click += new System.EventHandler(this.Servo0Btn_Click);
            // 
            // panel1
            // 
            this.panel1.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.panel1.Controls.Add(this.label1);
            this.panel1.Controls.Add(this.Servo0Btn);
            this.panel1.Controls.Add(this.Servo90Btn);
            this.panel1.Location = new System.Drawing.Point(12, 49);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(219, 73);
            this.panel1.TabIndex = 4;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(3, 11);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(72, 13);
            this.label1.TabIndex = 2;
            this.label1.Text = "Servo Ayarları";
            // 
            // panel2
            // 
            this.panel2.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.panel2.Controls.Add(this.label2);
            this.panel2.Controls.Add(this.Role2ABtn);
            this.panel2.Controls.Add(this.Role2PBtn);
            this.panel2.Controls.Add(this.Role1ABtn);
            this.panel2.Controls.Add(this.Role1PBtn);
            this.panel2.Location = new System.Drawing.Point(12, 128);
            this.panel2.Name = "panel2";
            this.panel2.Size = new System.Drawing.Size(219, 118);
            this.panel2.TabIndex = 6;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(3, 11);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(66, 13);
            this.label2.TabIndex = 6;
            this.label2.Text = "Röle Ayarları";
            // 
            // Role2ABtn
            // 
            this.Role2ABtn.Location = new System.Drawing.Point(3, 73);
            this.Role2ABtn.Name = "Role2ABtn";
            this.Role2ABtn.Size = new System.Drawing.Size(103, 40);
            this.Role2ABtn.TabIndex = 4;
            this.Role2ABtn.Text = "Röle 2 Aktif";
            this.Role2ABtn.UseVisualStyleBackColor = true;
            this.Role2ABtn.Click += new System.EventHandler(this.Role2ABtn_Click);
            // 
            // Role2PBtn
            // 
            this.Role2PBtn.Location = new System.Drawing.Point(112, 73);
            this.Role2PBtn.Name = "Role2PBtn";
            this.Role2PBtn.Size = new System.Drawing.Size(103, 40);
            this.Role2PBtn.TabIndex = 5;
            this.Role2PBtn.Text = "Röle 2 Pasif";
            this.Role2PBtn.UseVisualStyleBackColor = true;
            this.Role2PBtn.Click += new System.EventHandler(this.Role2PBtn_Click);
            // 
            // Role1ABtn
            // 
            this.Role1ABtn.Location = new System.Drawing.Point(3, 27);
            this.Role1ABtn.Name = "Role1ABtn";
            this.Role1ABtn.Size = new System.Drawing.Size(103, 40);
            this.Role1ABtn.TabIndex = 1;
            this.Role1ABtn.Text = "Röle 1 Aktif";
            this.Role1ABtn.UseVisualStyleBackColor = true;
            this.Role1ABtn.Click += new System.EventHandler(this.Role1ABtn_Click);
            // 
            // Role1PBtn
            // 
            this.Role1PBtn.Location = new System.Drawing.Point(112, 27);
            this.Role1PBtn.Name = "Role1PBtn";
            this.Role1PBtn.Size = new System.Drawing.Size(103, 40);
            this.Role1PBtn.TabIndex = 1;
            this.Role1PBtn.Text = "Röle 1 Pasif";
            this.Role1PBtn.UseVisualStyleBackColor = true;
            this.Role1PBtn.Click += new System.EventHandler(this.Role1PBtn_Click);
            // 
            // serialPort1
            // 
            this.serialPort1.BaudRate = 115200;
            this.serialPort1.DataReceived += new System.IO.Ports.SerialDataReceivedEventHandler(this.serialPort1_DataReceived);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(9, 6);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(60, 13);
            this.label3.TabIndex = 7;
            this.label3.Text = "Port Seçimi";
            // 
            // Konsol
            // 
            this.Konsol.BackColor = System.Drawing.SystemColors.Control;
            this.Konsol.Location = new System.Drawing.Point(238, 22);
            this.Konsol.Multiline = true;
            this.Konsol.Name = "Konsol";
            this.Konsol.ReadOnly = true;
            this.Konsol.Size = new System.Drawing.Size(219, 224);
            this.Konsol.TabIndex = 8;
            this.Konsol.TextChanged += new System.EventHandler(this.Konsol_TextChanged);
            // 
            // panel3
            // 
            this.panel3.BackColor = System.Drawing.Color.GreenYellow;
            this.panel3.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.panel3.Controls.Add(this.label4);
            this.panel3.Location = new System.Drawing.Point(12, 252);
            this.panel3.Name = "panel3";
            this.panel3.Size = new System.Drawing.Size(218, 34);
            this.panel3.TabIndex = 9;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(90, 9);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(35, 13);
            this.label4.TabIndex = 0;
            this.label4.Text = "label4";
            // 
            // panel4
            // 
            this.panel4.BackColor = System.Drawing.Color.GreenYellow;
            this.panel4.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.panel4.Controls.Add(this.label5);
            this.panel4.Location = new System.Drawing.Point(238, 252);
            this.panel4.Name = "panel4";
            this.panel4.Size = new System.Drawing.Size(219, 34);
            this.panel4.TabIndex = 10;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(94, 9);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(35, 13);
            this.label5.TabIndex = 1;
            this.label5.Text = "label5";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.ControlLight;
            this.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None;
            this.ClientSize = new System.Drawing.Size(470, 300);
            this.Controls.Add(this.panel4);
            this.Controls.Add(this.panel3);
            this.Controls.Add(this.Konsol);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.panel2);
            this.Controls.Add(this.panel1);
            this.Controls.Add(this.PortKutu);
            this.Name = "Form1";
            this.Text = "Arduino Panel";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            this.panel2.ResumeLayout(false);
            this.panel2.PerformLayout();
            this.panel3.ResumeLayout(false);
            this.panel3.PerformLayout();
            this.panel4.ResumeLayout(false);
            this.panel4.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ComboBox PortKutu;
        private System.Windows.Forms.Button Servo90Btn;
        private System.Windows.Forms.Button Servo0Btn;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Panel panel2;
        private System.Windows.Forms.Button Role2ABtn;
        private System.Windows.Forms.Button Role2PBtn;
        private System.Windows.Forms.Button Role1ABtn;
        private System.Windows.Forms.Button Role1PBtn;
        private System.IO.Ports.SerialPort serialPort1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox Konsol;
        private System.Windows.Forms.Panel panel3;
        private System.Windows.Forms.Panel panel4;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
    }
}

