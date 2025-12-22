
abstract class clsCalculatorRequirements
{
    abstract public void Clear();
    abstract public void Add(float number);
    abstract public void Substract(float number);
    
    // if the current number is 0 make it 1
    abstract public void Divide(float number);
    abstract public void Multiply(float number);

    // print result after last operation is : result
    abstract public void PrintResult();
} 



class clsCalculator :  clsCalculatorRequirements
{
    private enum enLastOperation
    {
        ADD, SUBTRACT, MULTIPLY, DIVIDE, CLEAR

    }

    private enLastOperation _lastOperation;
    private float _result;
    private float _lastArgument;



    public clsCalculator()
    {
        _result = 0;
    }

    private float _getLastArgument()
    {
        return _lastArgument;
    }

    private void _updateLastArgument(float argument)
    {
        _lastArgument = argument;
    }

    private void _updateLastOperation(enLastOperation operation) {  _lastOperation = operation; }

    public override void Clear()
    {
        _result = 0;
        _updateLastOperation(enLastOperation.CLEAR);
    }

    public override void Add(float number)
    {
        _result += number;
        _updateLastOperation(enLastOperation.ADD);
        _updateLastArgument(number);
    }

    public override void Substract(float number)
    {
        _result -= number;
        _updateLastOperation(enLastOperation.SUBTRACT);
        _updateLastArgument(number);
    }

    public override void Divide(float number)
    {
        if(number>0)
        {
            _result /= number;
        }
        _updateLastOperation(enLastOperation.DIVIDE);
        _updateLastArgument(number);
    }

    public override void Multiply(float number)
    {
        _result *= number;
        _updateLastOperation(enLastOperation.MULTIPLY);
        _updateLastArgument(number);
    }

    private string getLastOperation()
    {
        switch (_lastOperation)
        {
            case enLastOperation.ADD:
                return "Adding";
            case enLastOperation.SUBTRACT:
                return "Substracting";
            case enLastOperation.DIVIDE:
                return "Dividing";
            case enLastOperation.MULTIPLY:
                return "Multiplying";
            case enLastOperation.CLEAR:
                return "Clearing";
            default:
                return "Clearing";

        }
    }

    public override void PrintResult()
    {

        if (_lastOperation == enLastOperation.CLEAR)
        {
            System.Console.WriteLine("Result After " + getLastOperation() + " is : " + _result);
        }
        else
        {
            System.Console.WriteLine("Result After " + getLastOperation() + " " + _getLastArgument() + " is : " + _result);
        }
            
    }


} 


internal class Program
{
    static void Main(string[] args)
    {
        clsCalculator calculator= new clsCalculator();

        calculator.Clear();

        calculator.Add(10);
        calculator.PrintResult();

        calculator.Add(100);
        calculator.PrintResult();

        calculator.Substract(20);
        calculator.PrintResult();

        calculator.Divide(0);
        calculator.PrintResult();

        calculator.Divide(2);
        calculator.PrintResult();

        calculator.Multiply(3);
        calculator.PrintResult();

        calculator.Clear();
        calculator.PrintResult();



    }
}


