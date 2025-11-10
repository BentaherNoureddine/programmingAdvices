using System.Linq.Expressions;

namespace PizzaProject
{
    public partial class Form1 : Form
    {


        public Form1()
        {
            InitializeComponent();
            // this.BackgroundImage = Image.FromFile(@"C:\Users\Asus\Downloads\pizza.jpg");

            _initLabelDict();
        }


        //this dct contains items for each label

        Dictionary<dynamic, HashSet<string>> _controlLabelItemsDict = new Dictionary<dynamic, HashSet<string>>();
        

        void _initLabelDict()
        {
            _controlLabelItemsDict.Add(toppingsLabel,new HashSet<string>());
            _controlLabelItemsDict.Add(SizeLabl, new HashSet<string>());
            _controlLabelItemsDict.Add(crustTypeLabel, new HashSet<string>());
            _controlLabelItemsDict.Add(whereToEatLabel, new HashSet<string>());

        }


        void _resetAllFields()
        {
            //reset size group
            rdS.Checked=false;
            rdSizeMedium.Checked=false; 
            rdSizeLarge.Checked=false;

            //reset crust group
            rbCrustThik.Checked=false;
            rbCrustThin.Checked=false;

            //reset Toppings group
            chBExtraCheese.Checked=false;
            chBGreenPepper.Checked=false;
            chBMuchrroms.Checked=false; 
            chBTomatoes.Checked=false;
            chBOnion.Checked=false;
            chBOlives.Checked=false;


            //reset where to eat
            rbEatInside.Checked=false;
            rbTakeOut.Checked=false;

        }



        private void _incrementTotalPrice(object tag)
        {
            ushort price = ushort.Parse(totalPriceLabel.Text);
            price += ushort.Parse(tag.ToString());
            totalPriceLabel.Text = price.ToString();
        }

        private void _decreaseTotalPrice(object tag)
        {
            ushort price = ushort.Parse(totalPriceLabel.Text);
            price -= ushort.Parse(tag.ToString());
            totalPriceLabel.Text = price.ToString();

        }

        private void _changeTotalPrice(dynamic control)
        {
            if (control.Checked)
            {
                _incrementTotalPrice(control.Tag);
            }
            else
            {
                _decreaseTotalPrice(control.Tag);
            }

        }

        void _refreshLabel(Label label)
        {
            /*
      
           HashSet<string> labelItems= new HashSet<string>();
           foreach (var item in _controlLabelItemsDict[label])
           {
                labelItems.Add(item);
           }

           label.Text = "";
           if (labelItems.Count ==1)
           {
                label.Text = labelItems.ElementAt(0);
                return;
           }
            for (ushort i=0;i<labelItems.Count;i++)
            {
                
                if((i % 2) == 0)
                {
                    label.Text += "\n";
                }
                label.Text += labelItems.ElementAt(i)+", ";

            }
            */

            label.Text = string.Join(", ", _controlLabelItemsDict[label]
                                          .Select((item, index) => (index % 2 == 0 ? "\n" + item : item)));

        }

        


        void _addNewItemToLabel(Label label, string newTopping)
        {
            _controlLabelItemsDict[label].Add(newTopping);
            _refreshLabel(label);

        }

        void _removeItemsFromLabel(Label label, string topping)
        {
            _controlLabelItemsDict[label].Remove(topping);
            _refreshLabel(label);
        }
        
        
        private void _changeLablelData(dynamic control, Label label)
        {

            if (control.Checked)
            {
               
                _addNewItemToLabel(label,control.Text);

            }
            else
            {

                _removeItemsFromLabel(label,control.Text);

            }

        }




        private void label1_Click(object sender, EventArgs e)
        {

        }



        private void label2_Click(object sender, EventArgs e)
        {

        }



        private void rdS_CheckedChanged(object sender, EventArgs e)
        {
            _changeTotalPrice(rdS);
            _changeLablelData(rdS, SizeLabl);

        }

        private void rdSizeLarge_CheckedChanged(object sender, EventArgs e)
        {
            _changeTotalPrice(rdSizeLarge);
            _changeLablelData(rdSizeLarge, SizeLabl);

        }

        private void rdSizeMedium_CheckedChanged(object sender, EventArgs e)
        {
            _changeTotalPrice(rdSizeMedium);
            _changeLablelData(rdSizeMedium, SizeLabl);
        }

        private void rbCrustThin_CheckedChanged(object sender, EventArgs e)
        {
            _changeTotalPrice(rbCrustThin);
            _changeLablelData(rbCrustThin, crustTypeLabel);


        }

        private void rbCrustThik_CheckedChanged(object sender, EventArgs e)
        {

            _changeTotalPrice(rbCrustThik);
            _changeLablelData(rbCrustThik, crustTypeLabel);

        }

        private void chBExtraCheese_CheckedChanged(object sender, EventArgs e)
        {
            _changeTotalPrice(chBExtraCheese);
            _changeLablelData(chBExtraCheese, toppingsLabel);

        }

        private void chBMuchrroms_CheckedChanged(object sender, EventArgs e)
        {

            _changeTotalPrice(chBMuchrroms);
            _changeLablelData(chBMuchrroms, toppingsLabel);
        }

        private void chBTomatoes_CheckedChanged(object sender, EventArgs e)
        {

            _changeTotalPrice(chBTomatoes);
            _changeLablelData(chBTomatoes, toppingsLabel);

        }

        private void chBOnion_CheckedChanged(object sender, EventArgs e)
        {

            _changeTotalPrice(chBOnion);
            _changeLablelData(chBOnion, toppingsLabel);

        }

        private void chBOlives_CheckedChanged(object sender, EventArgs e)
        {

            _changeTotalPrice(chBOlives);
            _changeLablelData(chBOlives, toppingsLabel);
        }

        private void chBGreenPepper_CheckedChanged(object sender, EventArgs e)
        {

            _changeTotalPrice(chBGreenPepper);
            _changeLablelData(chBGreenPepper, toppingsLabel);

        }

        private void rbEatInside_CheckedChanged(object sender, EventArgs e)
        {
            _changeLablelData(rbEatInside, whereToEatLabel);
        }

        private void rbTakeOut_CheckedChanged(object sender, EventArgs e)
        {

            _changeLablelData(rbTakeOut, whereToEatLabel);

        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        

        private void REsetForm_Click(object sender, EventArgs e)
        {

            _resetAllFields();

        }
    }
}
