using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using tictactoe.Properties;
using static System.Net.Mime.MediaTypeNames;

namespace tictactoe
{


    public partial class Form1 : Form
    {

        static Player player1 = new Player("Player 1", Resources.X);
        static Player player2 = new Player("Player 2", Resources.O);

        static Player currentPlayer = player1;
        static Player[,] map = new Player[3,3];

        public static ushort leftTries=9;

        private  void _getNextPlayer(Player player) 
        {
            if (currentPlayer == player1)
            {
                gameOverLabel.Text = player2.name;
                currentPlayer = player2;
                return;
            }
            else if (currentPlayer == player2)
            {
                gameOverLabel.Text = player1.name;
                currentPlayer = player1;
                return;
            }
             
        }

        public Form1()
        {
            InitializeComponent();
          

        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {

        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }



        private void _drawLine(PaintEventArgs e,Color color, float width, float x, float y,float x2,float y2) 
        {

            Pen pen = new Pen(color, width);



            pen.StartCap = System.Drawing.Drawing2D.LineCap.Round;
            pen.EndCap = System.Drawing.Drawing2D.LineCap.Round;

            e.Graphics.DrawLine(pen, x, y, x2, y2);

        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {

            //FIRST VERTICAL
            _drawLine(e, Color.White,16, 632, 548, 632, 134);
            //SECOND VERTICAL
            _drawLine(e, Color.White,16, 791, 548, 791, 134);
            //FIRST HFORIZONTAL
            _drawLine(e, Color.White,16, 482, 270, 942, 270);
            //SECOND HORIZONTAL
            _drawLine(e, Color.White,16, 478, 415, 941, 415);
        }

        private void _changeMapStats(ushort pbNumber)
        {
            switch (pbNumber)
            {
                case 1:
                    map[0,0] = currentPlayer;
                    break;
                case 2:
                    map[0,1] = currentPlayer;
                    break;
                case 3:
                    map[0,2] = currentPlayer; 
                    break;
                case 4:
                    map[1,0] = currentPlayer;
                    break;
                case 5:
                    map[1,1] = currentPlayer;
                    break;
                case 6:
                    map[1,2] = currentPlayer;
                    break;
                case 7:
                    map[2,0] = currentPlayer;
                    break;
                case 8:
                    map[2,1] = currentPlayer;
                    break;
                case 9:
                    map[2,2] = currentPlayer;
                    break;
                
            }
        }

       private bool _getLeftVerticalStats()
        {
            return (map[0, 0] == player1 && map[1, 0] == player1 && map[2, 0] == player1) || (map[0, 0] == player2 && map[1, 0] == player2 && map[2, 0] == player2);
        }

        private bool _getMidVerticalStats()
        {
            return (map[0, 1] == player1 && map[1, 1] == player1 && map[2, 1] == player1) || (map[0, 1] == player2 && map[1, 1] == player2 && map[2, 1] == player2);
        }
        private bool _getRightVerticalStats()
        {
            return (map[0, 2] == player1 && map[1, 2] == player1 && map[2, 2] == player1) || (map[0, 2] == player2 && map[1, 2] == player2 && map[2, 2] == player2);
        }

        // Checks the first (top) row: [0, 0], [0, 1], [0, 2]
        private bool _getFirstHorizontalStats()
        {
            // Win for player1 OR win for player2
            return (map[0, 0] == player1 && map[0, 1] == player1 && map[0, 2] == player1) ||
                   (map[0, 0] == player2 && map[0, 1] == player2 && map[0, 2] == player2);
        }

        // Checks the second (middle) row: [1, 0], [1, 1], [1, 2]
        private bool _getMidHorizontalStats()
        {
            return (map[1, 0] == player1 && map[1, 1] == player1 && map[1, 2] == player1) ||
                   (map[1, 0] == player2 && map[1, 1] == player2 && map[1, 2] == player2);
        }

        // Checks the third (bottom) row: [2, 0], [2, 1], [2, 2]
        private bool _getLastHorizontalStats()
        {
            return (map[2, 0] == player1 && map[2, 1] == player1 && map[2, 2] == player1) ||
                   (map[2, 0] == player2 && map[2, 1] == player2 && map[2, 2] == player2);
        }


        // Checks the Top-Left to Bottom-Right diagonal: [0, 0], [1, 1], [2, 2]
        bool _getDiagonal1Stats()
        {
            return (map[0, 0] == player1 && map[1, 1] == player1 && map[2, 2] == player1) ||
                   (map[0, 0] == player2 && map[1, 1] == player2 && map[2, 2] == player2);
        }

        // Checks the Top-Right to Bottom-Left diagonal: [0, 2], [1, 1], [2, 0]
        private bool _getDiagonal2Stats()
        {
            return (map[0, 2] == player1 && map[1, 1] == player1 && map[2, 0] == player1) ||
                   (map[0, 2] == player2 && map[1, 1] == player2 && map[2, 0] == player2);
        }

  

        private void _highLightWinnerBoxes()
        {
            foreach(PictureBox box in currentPlayer.boxes)
            {
                box.BackColor = Color.White;
            }
        }
        private bool _chechAllTheMap()
        {
            return _getDiagonal1Stats() || _getDiagonal2Stats() || _getFirstHorizontalStats() || _getMidHorizontalStats() ||
                    _getLastHorizontalStats()||_getLeftVerticalStats()|| _getMidVerticalStats()|| _getRightVerticalStats() ;
                    
        }

        private bool _noMoreTries()
        {
           return leftTries<=0;
        }
        private void _disableAlltheMap()
        {
            pb1.Enabled = false;
            pb2.Enabled = false;
            pb3.Enabled = false;
            pb4.Enabled = false;
            pb5.Enabled = false;
            pb6.Enabled = false;
            pb7.Enabled = false;
            pb8.Enabled = false;
            pb9.Enabled = false;
        }

        private void _enableAlltheMap()
        {
            pb1.Enabled = true;
            pb2.Enabled = true;
            pb3.Enabled = true;
            pb4.Enabled = true;
            pb5.Enabled = true;
            pb6.Enabled = true;
            pb7.Enabled = true;
            pb8.Enabled = true;
            pb9.Enabled = true;
        }

       
      

        private void _GameOver()
        {
            if (_noMoreTries())
            {
                winnerLabel.Text = "NO WINNER";

                return;
            }
            _highLightWinnerBoxes();
            winnerLabel.Text = currentPlayer.name;
            gameOverLabel.Text = currentPlayer.name;
            _disableAlltheMap();

        }

        Player emptyPlayer = new Player("empty", Resources.question_mark_96);

        private void _initMapArray()
        {
            for (ushort column = 0; column < 3; column++)
            {
                for (ushort row = 0; row < 3; row++)
                {
                    map[row, column] = emptyPlayer;
                }

            }
        }

        private void _initMapImages()
        {
            System.Drawing.Image qImage = Resources.question_mark_96;
          
            pb1.Image= qImage;
            pb2.Image= qImage;
            pb3.Image= qImage;
            pb4.Image= qImage;
            pb5.Image= qImage;
            pb6.Image= qImage;
            pb7.Image= qImage;
            pb8.Image= qImage;
            pb9.Image = qImage;

            pb1.BackColor = Color.Black;
            pb2.BackColor = Color.Black;
            pb3.BackColor = Color.Black;
            pb4.BackColor = Color.Black;
            pb5.BackColor = Color.Black;
            pb6.BackColor = Color.Black;
            pb7.BackColor = Color.Black;
            pb8.BackColor = Color.Black;
            pb9.BackColor = Color.Black;
        }

        private void _initMap()
        {
            _initMapArray();
            _initMapImages();

        }

        private void _initTags()
        {
            pb1.Tag = "";
            pb2.Tag = "";
            pb3.Tag = "";
            pb4.Tag = "";
            pb5.Tag = "";
            pb6.Tag = "";
            pb7.Tag = "";
            pb8.Tag = "";
            pb9.Tag = "";
        }

        private void _clearWinnerBoxes()
        {
            player1.boxes.Clear();
            player2.boxes.Clear();  
        }

        private void _restartGame()
        {
            leftTries=9;
            _enableAlltheMap();
            _initTags();
            _clearWinnerBoxes();
            currentPlayer = player1;
            gameOverLabel.Text = player1.name;
            winnerLabel.Text = "In Progress";
            _initMap();
            


        }

      

        void _changeGameStats(PictureBox pb,ushort pbNumber)
        {
            leftTries--;
            pb.Tag = currentPlayer.name;
            pb.Enabled = false;
            pb.Image = currentPlayer.image;
            currentPlayer.boxes.Add(pb);
            _changeMapStats(pbNumber);
            if (_chechAllTheMap()||_noMoreTries())
            {
                _GameOver();
                return;
            }
            _getNextPlayer(currentPlayer);
            

        }


        private void Form1_MouseMove(object sender, MouseEventArgs e)
        {
            this.Text = $"X = {e.X} , Y = {e.Y}";
        }

        private class Player
        {
            public string name;
            public System.Drawing.Image image;
            public  HashSet<PictureBox> boxes = new HashSet<PictureBox>();

            public Player(string name,System.Drawing.Image image)
            {
                this.name = name;
                this.image = image;

            }
        }

        private void pb1_Click(object sender, EventArgs e)
        {

            _changeGameStats(pb1,1);
            


        }

        private void pb7_Click(object sender, EventArgs e)
        {
            _changeGameStats(pb7,7);
        }

        private void pb8_Click(object sender, EventArgs e)
        {

            _changeGameStats(pb8,8);

        }

        private void pb6_Click(object sender, EventArgs e)
        {

            _changeGameStats(pb6,6);

        }

        private void pb4_Click(object sender, EventArgs e)
        {

            _changeGameStats(pb4,4);

        }

        private void pb5_Click(object sender, EventArgs e)
        {

            _changeGameStats(pb5,5);

        }

        private void pb3_Click(object sender, EventArgs e)
        {

            _changeGameStats(pb3,3);

        }

        private void pb9_Click(object sender, EventArgs e)
        {
            _changeGameStats(pb9,9);

        }

        private void pb2_Click(object sender, EventArgs e)
        {
            _changeGameStats(pb2,2);

        }

        private void button1_Click(object sender, EventArgs e)
        {
            _restartGame();
        }
    }
}
