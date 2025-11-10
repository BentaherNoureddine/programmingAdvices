namespace PizzaProject
{
    partial class Form1
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
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
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            label1 = new Label();
            rbSizeGroup = new GroupBox();
            rdS = new RadioButton();
            rdSizeMedium = new RadioButton();
            rdSizeLarge = new RadioButton();
            rbCrustTypeGroup = new GroupBox();
            rbCrustThin = new RadioButton();
            rbCrustThik = new RadioButton();
            chBExtraCheese = new CheckBox();
            chBMuchrroms = new CheckBox();
            chBGreenPepper = new CheckBox();
            chBTomatoes = new CheckBox();
            chBOlives = new CheckBox();
            chBOnion = new CheckBox();
            label2 = new Label();
            rbWHereToEatGroup = new GroupBox();
            rbEatInside = new RadioButton();
            rbTakeOut = new RadioButton();
            label3 = new Label();
            label4 = new Label();
            SizeLabl = new Label();
            label5 = new Label();
            toppingsLabel = new Label();
            crustTypeLabelee = new Label();
            whereToEatLabel = new Label();
            label8 = new Label();
            totalPriceLabel = new Label();
            label9 = new Label();
            label7 = new Label();
            orderbutton = new Button();
            crustTypeLabel = new Label();
            REsetForm = new Button();
            rbSizeGroup.SuspendLayout();
            rbCrustTypeGroup.SuspendLayout();
            rbWHereToEatGroup.SuspendLayout();
            SuspendLayout();
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Font = new Font("Segoe Print", 24F, FontStyle.Bold | FontStyle.Italic, GraphicsUnit.Point, 0);
            label1.ForeColor = Color.Red;
            label1.Location = new Point(435, 38);
            label1.Name = "label1";
            label1.Size = new Size(441, 71);
            label1.TabIndex = 0;
            label1.Text = "MAKE YOUR PIZZA";
            label1.Click += label1_Click;
            // 
            // rbSizeGroup
            // 
            rbSizeGroup.Controls.Add(rdS);
            rbSizeGroup.Controls.Add(rdSizeMedium);
            rbSizeGroup.Controls.Add(rdSizeLarge);
            rbSizeGroup.Location = new Point(53, 139);
            rbSizeGroup.Name = "rbSizeGroup";
            rbSizeGroup.Size = new Size(343, 203);
            rbSizeGroup.TabIndex = 0;
            rbSizeGroup.TabStop = false;
            rbSizeGroup.Text = "Size";
            // 
            // rdS
            // 
            rdS.AutoSize = true;
            rdS.Location = new Point(35, 56);
            rdS.Name = "rdS";
            rdS.Size = new Size(67, 24);
            rdS.TabIndex = 1;
            rdS.TabStop = true;
            rdS.Tag = "10";
            rdS.Text = "Small";
            rdS.UseVisualStyleBackColor = true;
            rdS.CheckedChanged += rdS_CheckedChanged;
            // 
            // rdSizeMedium
            // 
            rdSizeMedium.AutoSize = true;
            rdSizeMedium.Location = new Point(35, 108);
            rdSizeMedium.Name = "rdSizeMedium";
            rdSizeMedium.Size = new Size(85, 24);
            rdSizeMedium.TabIndex = 2;
            rdSizeMedium.TabStop = true;
            rdSizeMedium.Tag = "20";
            rdSizeMedium.Text = "Medium";
            rdSizeMedium.UseVisualStyleBackColor = true;
            rdSizeMedium.CheckedChanged += rdSizeMedium_CheckedChanged;
            // 
            // rdSizeLarge
            // 
            rdSizeLarge.AutoSize = true;
            rdSizeLarge.Location = new Point(35, 160);
            rdSizeLarge.Name = "rdSizeLarge";
            rdSizeLarge.Size = new Size(67, 24);
            rdSizeLarge.TabIndex = 3;
            rdSizeLarge.TabStop = true;
            rdSizeLarge.Tag = "30";
            rdSizeLarge.Text = "Large";
            rdSizeLarge.UseVisualStyleBackColor = true;
            rdSizeLarge.CheckedChanged += rdSizeLarge_CheckedChanged;
            // 
            // rbCrustTypeGroup
            // 
            rbCrustTypeGroup.Controls.Add(rbCrustThin);
            rbCrustTypeGroup.Controls.Add(rbCrustThik);
            rbCrustTypeGroup.Location = new Point(53, 469);
            rbCrustTypeGroup.Name = "rbCrustTypeGroup";
            rbCrustTypeGroup.Size = new Size(343, 143);
            rbCrustTypeGroup.TabIndex = 4;
            rbCrustTypeGroup.TabStop = false;
            rbCrustTypeGroup.Text = "Crust Type";
            // 
            // rbCrustThin
            // 
            rbCrustThin.AutoSize = true;
            rbCrustThin.Location = new Point(35, 56);
            rbCrustThin.Name = "rbCrustThin";
            rbCrustThin.Size = new Size(95, 24);
            rbCrustThin.TabIndex = 5;
            rbCrustThin.TabStop = true;
            rbCrustThin.Tag = "10";
            rbCrustThin.Text = "Thin Crust";
            rbCrustThin.UseVisualStyleBackColor = true;
            rbCrustThin.CheckedChanged += rbCrustThin_CheckedChanged;
            // 
            // rbCrustThik
            // 
            rbCrustThik.AutoSize = true;
            rbCrustThik.Location = new Point(35, 108);
            rbCrustThik.Name = "rbCrustThik";
            rbCrustThik.Size = new Size(92, 24);
            rbCrustThik.TabIndex = 6;
            rbCrustThik.TabStop = true;
            rbCrustThik.Tag = "20";
            rbCrustThik.Text = "Thik crust";
            rbCrustThik.UseVisualStyleBackColor = true;
            rbCrustThik.CheckedChanged += rbCrustThik_CheckedChanged;
            // 
            // chBExtraCheese
            // 
            chBExtraCheese.AutoSize = true;
            chBExtraCheese.Location = new Point(572, 195);
            chBExtraCheese.Name = "chBExtraCheese";
            chBExtraCheese.Size = new Size(113, 24);
            chBExtraCheese.TabIndex = 7;
            chBExtraCheese.Tag = "10";
            chBExtraCheese.Text = "Extra cheese";
            chBExtraCheese.UseVisualStyleBackColor = true;
            chBExtraCheese.CheckedChanged += chBExtraCheese_CheckedChanged;
            // 
            // chBMuchrroms
            // 
            chBMuchrroms.AutoSize = true;
            chBMuchrroms.Location = new Point(572, 248);
            chBMuchrroms.Name = "chBMuchrroms";
            chBMuchrroms.Size = new Size(108, 24);
            chBMuchrroms.TabIndex = 9;
            chBMuchrroms.Tag = 10;
            chBMuchrroms.Text = "Mushrooms";
            chBMuchrroms.UseVisualStyleBackColor = true;
            chBMuchrroms.CheckedChanged += chBMuchrroms_CheckedChanged;
            // 
            // chBGreenPepper
            // 
            chBGreenPepper.AutoSize = true;
            chBGreenPepper.Location = new Point(735, 299);
            chBGreenPepper.Name = "chBGreenPepper";
            chBGreenPepper.Size = new Size(126, 24);
            chBGreenPepper.TabIndex = 12;
            chBGreenPepper.Tag = 10;
            chBGreenPepper.Text = "Green Peppers";
            chBGreenPepper.UseVisualStyleBackColor = true;
            chBGreenPepper.CheckedChanged += chBGreenPepper_CheckedChanged;
            // 
            // chBTomatoes
            // 
            chBTomatoes.AutoSize = true;
            chBTomatoes.Location = new Point(572, 300);
            chBTomatoes.Name = "chBTomatoes";
            chBTomatoes.Size = new Size(96, 24);
            chBTomatoes.TabIndex = 11;
            chBTomatoes.Tag = 10;
            chBTomatoes.Text = "Tomatoes";
            chBTomatoes.UseVisualStyleBackColor = true;
            chBTomatoes.CheckedChanged += chBTomatoes_CheckedChanged;
            // 
            // chBOlives
            // 
            chBOlives.AutoSize = true;
            chBOlives.Location = new Point(735, 248);
            chBOlives.Name = "chBOlives";
            chBOlives.Size = new Size(71, 24);
            chBOlives.TabIndex = 10;
            chBOlives.Tag = 10;
            chBOlives.Text = "Olives";
            chBOlives.UseVisualStyleBackColor = true;
            chBOlives.CheckedChanged += chBOlives_CheckedChanged;
            // 
            // chBOnion
            // 
            chBOnion.AutoSize = true;
            chBOnion.Location = new Point(735, 195);
            chBOnion.Name = "chBOnion";
            chBOnion.Size = new Size(71, 24);
            chBOnion.TabIndex = 8;
            chBOnion.Tag = 10;
            chBOnion.Text = "Onion";
            chBOnion.UseVisualStyleBackColor = true;
            chBOnion.CheckedChanged += chBOnion_CheckedChanged;
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Location = new Point(572, 150);
            label2.Name = "label2";
            label2.Size = new Size(70, 20);
            label2.TabIndex = 14;
            label2.Text = "Toppings";
            // 
            // rbWHereToEatGroup
            // 
            rbWHereToEatGroup.Controls.Add(rbEatInside);
            rbWHereToEatGroup.Controls.Add(rbTakeOut);
            rbWHereToEatGroup.FlatStyle = FlatStyle.Popup;
            rbWHereToEatGroup.Location = new Point(550, 469);
            rbWHereToEatGroup.Name = "rbWHereToEatGroup";
            rbWHereToEatGroup.Size = new Size(343, 100);
            rbWHereToEatGroup.TabIndex = 13;
            rbWHereToEatGroup.TabStop = false;
            rbWHereToEatGroup.Text = "Where To Eat";
            // 
            // rbEatInside
            // 
            rbEatInside.AutoSize = true;
            rbEatInside.Location = new Point(35, 56);
            rbEatInside.Name = "rbEatInside";
            rbEatInside.Size = new Size(94, 24);
            rbEatInside.TabIndex = 14;
            rbEatInside.TabStop = true;
            rbEatInside.Tag = "10";
            rbEatInside.Text = "Eat inside";
            rbEatInside.UseVisualStyleBackColor = true;
            rbEatInside.CheckedChanged += rbEatInside_CheckedChanged;
            // 
            // rbTakeOut
            // 
            rbTakeOut.AutoSize = true;
            rbTakeOut.Location = new Point(175, 56);
            rbTakeOut.Name = "rbTakeOut";
            rbTakeOut.Size = new Size(87, 24);
            rbTakeOut.TabIndex = 15;
            rbTakeOut.TabStop = true;
            rbTakeOut.Tag = "20";
            rbTakeOut.Text = "Take Out";
            rbTakeOut.UseVisualStyleBackColor = true;
            rbTakeOut.CheckedChanged += rbTakeOut_CheckedChanged;
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.Location = new Point(1002, 139);
            label3.Name = "label3";
            label3.Size = new Size(117, 20);
            label3.TabIndex = 15;
            label3.Text = "Order  Summary";
            // 
            // label4
            // 
            label4.AutoSize = true;
            label4.FlatStyle = FlatStyle.System;
            label4.Font = new Font("Segoe UI", 10.8F, FontStyle.Bold, GraphicsUnit.Point, 0);
            label4.Location = new Point(1022, 172);
            label4.Name = "label4";
            label4.Size = new Size(51, 25);
            label4.TabIndex = 16;
            label4.Text = "Size:";
            // 
            // SizeLabl
            // 
            SizeLabl.AutoSize = true;
            SizeLabl.Location = new Point(1063, 172);
            SizeLabl.Name = "SizeLabl";
            SizeLabl.Size = new Size(0, 20);
            SizeLabl.TabIndex = 17;
            // 
            // label5
            // 
            label5.AutoSize = true;
            label5.Font = new Font("Segoe UI", 10.8F, FontStyle.Bold, GraphicsUnit.Point, 0);
            label5.Location = new Point(1018, 229);
            label5.Name = "label5";
            label5.Size = new Size(94, 25);
            label5.TabIndex = 18;
            label5.Text = "Toppings:";
            // 
            // toppingsLabel
            // 
            toppingsLabel.AutoSize = true;
            toppingsLabel.Location = new Point(1063, 263);
            toppingsLabel.Name = "toppingsLabel";
            toppingsLabel.Size = new Size(0, 20);
            toppingsLabel.TabIndex = 19;
            // 
            // crustTypeLabelee
            // 
            crustTypeLabelee.AutoSize = true;
            crustTypeLabelee.Font = new Font("Segoe UI", 10.8F, FontStyle.Bold, GraphicsUnit.Point, 0);
            crustTypeLabelee.Location = new Point(1022, 369);
            crustTypeLabelee.Name = "crustTypeLabelee";
            crustTypeLabelee.Size = new Size(102, 25);
            crustTypeLabelee.TabIndex = 20;
            crustTypeLabelee.Text = "Crust Type";
            // 
            // whereToEatLabel
            // 
            whereToEatLabel.AutoSize = true;
            whereToEatLabel.Location = new Point(1071, 466);
            whereToEatLabel.Name = "whereToEatLabel";
            whereToEatLabel.Size = new Size(0, 20);
            whereToEatLabel.TabIndex = 23;
            // 
            // label8
            // 
            label8.AutoSize = true;
            label8.Font = new Font("Segoe UI", 10.8F, FontStyle.Bold, GraphicsUnit.Point, 0);
            label8.Location = new Point(1022, 431);
            label8.Name = "label8";
            label8.Size = new Size(125, 25);
            label8.TabIndex = 22;
            label8.Text = "Where To Eat";
            // 
            // totalPriceLabel
            // 
            totalPriceLabel.AutoSize = true;
            totalPriceLabel.Font = new Font("Segoe Print", 16.2F, FontStyle.Bold);
            totalPriceLabel.ForeColor = Color.LightSeaGreen;
            totalPriceLabel.Location = new Point(1166, 560);
            totalPriceLabel.Name = "totalPriceLabel";
            totalPriceLabel.Size = new Size(42, 50);
            totalPriceLabel.TabIndex = 25;
            totalPriceLabel.Text = "0";
            // 
            // label9
            // 
            label9.AutoSize = true;
            label9.Font = new Font("Segoe UI", 10.8F, FontStyle.Bold, GraphicsUnit.Point, 0);
            label9.Location = new Point(1026, 512);
            label9.Name = "label9";
            label9.Size = new Size(101, 25);
            label9.TabIndex = 24;
            label9.Text = "Total Price";
            // 
            // label7
            // 
            label7.AutoSize = true;
            label7.Font = new Font("Segoe Print", 16.2F, FontStyle.Bold);
            label7.ForeColor = Color.LightSeaGreen;
            label7.Location = new Point(1132, 560);
            label7.Name = "label7";
            label7.Size = new Size(37, 50);
            label7.TabIndex = 26;
            label7.Text = "$";
            // 
            // orderbutton
            // 
            orderbutton.BackColor = Color.White;
            orderbutton.FlatStyle = FlatStyle.Popup;
            orderbutton.Location = new Point(538, 638);
            orderbutton.Name = "orderbutton";
            orderbutton.Size = new Size(94, 29);
            orderbutton.TabIndex = 16;
            orderbutton.Text = "Order Pizza";
            orderbutton.UseVisualStyleBackColor = false;
            // 
            // crustTypeLabel
            // 
            crustTypeLabel.AutoSize = true;
            crustTypeLabel.Font = new Font("Segoe UI Emoji", 10.8F, FontStyle.Regular, GraphicsUnit.Point, 0);
            crustTypeLabel.ForeColor = Color.Black;
            crustTypeLabel.Location = new Point(1147, 368);
            crustTypeLabel.Name = "crustTypeLabel";
            crustTypeLabel.Size = new Size(0, 24);
            crustTypeLabel.TabIndex = 29;
            // 
            // REsetForm
            // 
            REsetForm.BackColor = Color.White;
            REsetForm.FlatStyle = FlatStyle.Popup;
            REsetForm.Location = new Point(799, 638);
            REsetForm.Name = "REsetForm";
            REsetForm.Size = new Size(94, 29);
            REsetForm.TabIndex = 17;
            REsetForm.Text = "Reset Form";
            REsetForm.UseVisualStyleBackColor = false;
            REsetForm.Click += REsetForm_Click;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(1351, 728);
            Controls.Add(REsetForm);
            Controls.Add(crustTypeLabel);
            Controls.Add(orderbutton);
            Controls.Add(label7);
            Controls.Add(totalPriceLabel);
            Controls.Add(label9);
            Controls.Add(whereToEatLabel);
            Controls.Add(label8);
            Controls.Add(crustTypeLabelee);
            Controls.Add(toppingsLabel);
            Controls.Add(label5);
            Controls.Add(SizeLabl);
            Controls.Add(label4);
            Controls.Add(label3);
            Controls.Add(rbWHereToEatGroup);
            Controls.Add(label2);
            Controls.Add(chBOnion);
            Controls.Add(chBOlives);
            Controls.Add(chBTomatoes);
            Controls.Add(chBGreenPepper);
            Controls.Add(chBMuchrroms);
            Controls.Add(chBExtraCheese);
            Controls.Add(rbCrustTypeGroup);
            Controls.Add(rbSizeGroup);
            Controls.Add(label1);
            Name = "Form1";
            Text = "Form1";
            Load += Form1_Load;
            rbSizeGroup.ResumeLayout(false);
            rbSizeGroup.PerformLayout();
            rbCrustTypeGroup.ResumeLayout(false);
            rbCrustTypeGroup.PerformLayout();
            rbWHereToEatGroup.ResumeLayout(false);
            rbWHereToEatGroup.PerformLayout();
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Label label1;
        private GroupBox rbSizeGroup;
        private RadioButton rdS;
        private RadioButton rdSizeMedium;
        private RadioButton rdSizeLarge;
        private GroupBox rbCrustTypeGroup;
        private RadioButton rbCrustThin;
        private RadioButton rbCrustThik;
        private CheckedListBox checkedListBox1;
        private CheckBox chBExtraCheese;
        private CheckBox chBMuchrroms;
        private CheckBox chBGreenPepper;
        private CheckBox chBTomatoes;
        private CheckBox chBOlives;
        private CheckBox chBOnion;
        private Label label2;
        private GroupBox rbWHereToEatGroup;
        private RadioButton rbEatInside;
        private RadioButton rbTakeOut;
        private Label label3;
        private Label label4;
        private Label SizeLabl;
        private Label label5;
        private Label toppingsLabel;
        private Label crustTypeLabelee;
        private Label whereToEatLabel;
        private Label label8;
        private Label totalPriceLabel;
        private Label label9;
        private Label label7;
        private Button orderbutton;
        private Label crustTypeLabel;
        private Button REsetForm;
    }
}
