using comboBox.Properties;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace comboBox
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            switch (comboBox1.Text)
            {
                case "Girl":
                    pb1.Image = Resources.Girl;
                    break;
                case "Boy":
                    pb1.Image = Resources.Boy;
                    break;
                case "Book":
                    pb1.Image = Resources.Book;
                    break;
                case "Pen":
                    pb1.Image= Resources.Pen;
                    break;

            }
        }
    }
}
