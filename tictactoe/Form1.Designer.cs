namespace tictactoe
{
    partial class Form1
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.pb2 = new System.Windows.Forms.PictureBox();
            this.pb1 = new System.Windows.Forms.PictureBox();
            this.pb3 = new System.Windows.Forms.PictureBox();
            this.pb6 = new System.Windows.Forms.PictureBox();
            this.pb4 = new System.Windows.Forms.PictureBox();
            this.pb5 = new System.Windows.Forms.PictureBox();
            this.pb9 = new System.Windows.Forms.PictureBox();
            this.pb7 = new System.Windows.Forms.PictureBox();
            this.pb8 = new System.Windows.Forms.PictureBox();
            this.label1 = new System.Windows.Forms.Label();
            this.turnLabel = new System.Windows.Forms.Label();
            this.winnerLabel = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.gameOverLabel = new System.Windows.Forms.Label();
            this.button1 = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.pb2)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pb1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pb3)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pb6)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pb4)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pb5)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pb9)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pb7)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pb8)).BeginInit();
            this.SuspendLayout();
            // 
            // pb2
            // 
            this.pb2.BackColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.pb2.Image = global::tictactoe.Properties.Resources.question_mark_96;
            this.pb2.InitialImage = ((System.Drawing.Image)(resources.GetObject("pb2.InitialImage")));
            this.pb2.Location = new System.Drawing.Point(853, 161);
            this.pb2.Name = "pb2";
            this.pb2.Size = new System.Drawing.Size(192, 161);
            this.pb2.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.pb2.TabIndex = 0;
            this.pb2.TabStop = false;
            this.pb2.Click += new System.EventHandler(this.pb2_Click);
            // 
            // pb1
            // 
            this.pb1.BackColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.pb1.Image = global::tictactoe.Properties.Resources.question_mark_96;
            this.pb1.InitialImage = ((System.Drawing.Image)(resources.GetObject("pb1.InitialImage")));
            this.pb1.Location = new System.Drawing.Point(642, 161);
            this.pb1.Name = "pb1";
            this.pb1.Size = new System.Drawing.Size(192, 161);
            this.pb1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.pb1.TabIndex = 1;
            this.pb1.TabStop = false;
            this.pb1.Click += new System.EventHandler(this.pb1_Click);
            // 
            // pb3
            // 
            this.pb3.BackColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.pb3.Image = global::tictactoe.Properties.Resources.question_mark_96;
            this.pb3.InitialImage = ((System.Drawing.Image)(resources.GetObject("pb3.InitialImage")));
            this.pb3.Location = new System.Drawing.Point(1064, 161);
            this.pb3.Name = "pb3";
            this.pb3.Size = new System.Drawing.Size(192, 161);
            this.pb3.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.pb3.TabIndex = 2;
            this.pb3.TabStop = false;
            this.pb3.Click += new System.EventHandler(this.pb3_Click);
            // 
            // pb6
            // 
            this.pb6.BackColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.pb6.Image = ((System.Drawing.Image)(resources.GetObject("pb6.Image")));
            this.pb6.InitialImage = ((System.Drawing.Image)(resources.GetObject("pb6.InitialImage")));
            this.pb6.Location = new System.Drawing.Point(1064, 340);
            this.pb6.Name = "pb6";
            this.pb6.Size = new System.Drawing.Size(192, 161);
            this.pb6.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.pb6.TabIndex = 5;
            this.pb6.TabStop = false;
            this.pb6.Click += new System.EventHandler(this.pb6_Click);
            // 
            // pb4
            // 
            this.pb4.BackColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.pb4.Image = ((System.Drawing.Image)(resources.GetObject("pb4.Image")));
            this.pb4.InitialImage = ((System.Drawing.Image)(resources.GetObject("pb4.InitialImage")));
            this.pb4.Location = new System.Drawing.Point(642, 340);
            this.pb4.Name = "pb4";
            this.pb4.Size = new System.Drawing.Size(192, 161);
            this.pb4.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.pb4.TabIndex = 4;
            this.pb4.TabStop = false;
            this.pb4.Click += new System.EventHandler(this.pb4_Click);
            // 
            // pb5
            // 
            this.pb5.BackColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.pb5.Image = ((System.Drawing.Image)(resources.GetObject("pb5.Image")));
            this.pb5.InitialImage = ((System.Drawing.Image)(resources.GetObject("pb5.InitialImage")));
            this.pb5.Location = new System.Drawing.Point(853, 340);
            this.pb5.Name = "pb5";
            this.pb5.Size = new System.Drawing.Size(192, 161);
            this.pb5.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.pb5.TabIndex = 3;
            this.pb5.TabStop = false;
            this.pb5.Click += new System.EventHandler(this.pb5_Click);
            // 
            // pb9
            // 
            this.pb9.BackColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.pb9.Image = ((System.Drawing.Image)(resources.GetObject("pb9.Image")));
            this.pb9.InitialImage = ((System.Drawing.Image)(resources.GetObject("pb9.InitialImage")));
            this.pb9.Location = new System.Drawing.Point(1064, 519);
            this.pb9.Name = "pb9";
            this.pb9.Size = new System.Drawing.Size(192, 161);
            this.pb9.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.pb9.TabIndex = 8;
            this.pb9.TabStop = false;
            this.pb9.Click += new System.EventHandler(this.pb9_Click);
            // 
            // pb7
            // 
            this.pb7.BackColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.pb7.Image = ((System.Drawing.Image)(resources.GetObject("pb7.Image")));
            this.pb7.InitialImage = ((System.Drawing.Image)(resources.GetObject("pb7.InitialImage")));
            this.pb7.Location = new System.Drawing.Point(642, 519);
            this.pb7.Name = "pb7";
            this.pb7.Size = new System.Drawing.Size(192, 161);
            this.pb7.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.pb7.TabIndex = 7;
            this.pb7.TabStop = false;
            this.pb7.Click += new System.EventHandler(this.pb7_Click);
            // 
            // pb8
            // 
            this.pb8.BackColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.pb8.Image = ((System.Drawing.Image)(resources.GetObject("pb8.Image")));
            this.pb8.InitialImage = ((System.Drawing.Image)(resources.GetObject("pb8.InitialImage")));
            this.pb8.Location = new System.Drawing.Point(853, 519);
            this.pb8.Name = "pb8";
            this.pb8.Size = new System.Drawing.Size(192, 161);
            this.pb8.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.pb8.TabIndex = 6;
            this.pb8.TabStop = false;
            this.pb8.Click += new System.EventHandler(this.pb8_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Palatino Linotype", 48F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.ForeColor = System.Drawing.SystemColors.ButtonHighlight;
            this.label1.Location = new System.Drawing.Point(287, 19);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(854, 108);
            this.label1.TabIndex = 9;
            this.label1.Text = "TIC-TAC-TOE GAME";
            // 
            // turnLabel
            // 
            this.turnLabel.AutoSize = true;
            this.turnLabel.Font = new System.Drawing.Font("Microsoft YaHei", 16.2F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Italic))), System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.turnLabel.ForeColor = System.Drawing.Color.Yellow;
            this.turnLabel.Location = new System.Drawing.Point(209, 230);
            this.turnLabel.Name = "turnLabel";
            this.turnLabel.Size = new System.Drawing.Size(83, 37);
            this.turnLabel.TabIndex = 10;
            this.turnLabel.Text = "Turn";
            // 
            // winnerLabel
            // 
            this.winnerLabel.AutoSize = true;
            this.winnerLabel.Font = new System.Drawing.Font("Microsoft YaHei", 16.2F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Italic))), System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.winnerLabel.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(192)))), ((int)(((byte)(0)))));
            this.winnerLabel.Location = new System.Drawing.Point(169, 432);
            this.winnerLabel.Name = "winnerLabel";
            this.winnerLabel.Size = new System.Drawing.Size(175, 37);
            this.winnerLabel.TabIndex = 11;
            this.winnerLabel.Text = "In Progress";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Microsoft YaHei", 16.2F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Italic))), System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.ForeColor = System.Drawing.Color.Yellow;
            this.label3.Location = new System.Drawing.Point(183, 367);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(119, 37);
            this.label3.TabIndex = 12;
            this.label3.Text = "Winner";
            // 
            // gameOverLabel
            // 
            this.gameOverLabel.AutoSize = true;
            this.gameOverLabel.Font = new System.Drawing.Font("Microsoft YaHei", 16.2F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Italic))), System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.gameOverLabel.ForeColor = System.Drawing.SystemColors.ButtonHighlight;
            this.gameOverLabel.Location = new System.Drawing.Point(183, 297);
            this.gameOverLabel.Name = "gameOverLabel";
            this.gameOverLabel.Size = new System.Drawing.Size(128, 37);
            this.gameOverLabel.TabIndex = 13;
            this.gameOverLabel.Text = "Player 1";
            // 
            // button1
            // 
            this.button1.BackColor = System.Drawing.Color.Black;
            this.button1.Font = new System.Drawing.Font("Microsoft YaHei", 16.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button1.ForeColor = System.Drawing.Color.White;
            this.button1.Location = new System.Drawing.Point(121, 516);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(249, 60);
            this.button1.TabIndex = 14;
            this.button1.Text = "Restart Game";
            this.button1.UseVisualStyleBackColor = false;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.ClientSize = new System.Drawing.Size(1419, 715);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.gameOverLabel);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.winnerLabel);
            this.Controls.Add(this.turnLabel);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.pb9);
            this.Controls.Add(this.pb7);
            this.Controls.Add(this.pb8);
            this.Controls.Add(this.pb6);
            this.Controls.Add(this.pb4);
            this.Controls.Add(this.pb5);
            this.Controls.Add(this.pb3);
            this.Controls.Add(this.pb1);
            this.Controls.Add(this.pb2);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.Paint += new System.Windows.Forms.PaintEventHandler(this.Form1_Paint);
            this.MouseMove += new System.Windows.Forms.MouseEventHandler(this.Form1_MouseMove);
            ((System.ComponentModel.ISupportInitialize)(this.pb2)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pb1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pb3)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pb6)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pb4)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pb5)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pb9)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pb7)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pb8)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.PictureBox pb2;
        private System.Windows.Forms.PictureBox pb1;
        private System.Windows.Forms.PictureBox pb3;
        private System.Windows.Forms.PictureBox pb6;
        private System.Windows.Forms.PictureBox pb4;
        private System.Windows.Forms.PictureBox pb5;
        private System.Windows.Forms.PictureBox pb9;
        private System.Windows.Forms.PictureBox pb7;
        private System.Windows.Forms.PictureBox pb8;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label turnLabel;
        private System.Windows.Forms.Label winnerLabel;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label gameOverLabel;
        private System.Windows.Forms.Button button1;
    }
}

