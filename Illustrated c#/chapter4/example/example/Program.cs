using System;

//class DaysTemp
//{
//    public int High = 74;
//    public int Low = 45;
//}

//class Program
//{
//    static void Main()
//    {
//        DaysTemp temp = new DaysTemp();
//        temp.High = 85;
//        temp.Low = 60;

//        Console.WriteLine("High: {0}", temp.High);
//        Console.WriteLine("Low: {0}", temp.Low);
//    }
//}

class DaysTemp
{
    public int High, Low;
    public int Average()
    {
        return (High + Low) / 2;
    }
}

class Program
{
    static void Main()
    {
        DaysTemp t1 = new DaysTemp();
        DaysTemp t2 = new DaysTemp();

        t1.High = 76;   t1.Low = 57;
        t2.High = 75;   t2.Low = 53;

        Console.WriteLine("t1: {0}, {1}, {2}", t1.High, t1.Low, t1.Average());
        Console.WriteLine("t2: {0}, {1}, {2}", t2.High, t2.Low, t2.Average());
    }
}