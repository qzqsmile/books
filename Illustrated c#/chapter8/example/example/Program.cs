using System;

//ex1
//class LimitedInt
//{
//    const int MaxValue = 100;
//    const int MinValue = 0;

//    public static implicit operator int(LimitedInt li)
//    {
//        return li.TheValue;
//    }

//    public static implicit operator LimitedInt(int x)
//    {
//        LimitedInt li = new LimitedInt();
//        li.TheValue = x;
//        return li;
//    }

//    private int _theValue = 0;
//    public int TheValue
//    {
//        get { return _theValue; }
//        set {
//            if (value < MinValue)
//                _theValue = 0;
//            else
//                _theValue = value > MaxValue ? MaxValue : value;
//        }
//    }
//}

//class Program
//{
//    static void Main()
//    {
//        LimitedInt li = 500;
//        int value = li;

//        Console.WriteLine("li: {0}, value: {1}",li.TheValue, value);
//    }
//}

//ex2
//class LimitedInt {
//    const int MaxValue = 100;
//    const int MinValue = 0;

//    public static LimitedInt operator -(LimitedInt x)
//    {
//        LimitedInt li = new LimitedInt();
//        li.TheValue = 0;
//        return li;
//    }

//    public static LimitedInt operator -(LimitedInt x, LimitedInt y)
//    {
//        LimitedInt li = new LimitedInt();
//        li.TheValue = x.TheValue - y.TheValue;
//        return li;
//    }

//    public static LimitedInt operator +(LimitedInt x, double y)
//    {
//        LimitedInt li = new LimitedInt();
//        li.TheValue = x.TheValue + (int)y;
//        return li;
//    }

//    private int _theValue = 0;
//    public int TheValue
//    {
//        get { return _theValue; }
//        set
//        {
//            if (value < MinValue)
//                _theValue = 0;
//            else
//                _theValue = value > MaxValue ? MaxValue : value;
//        }
//    }
//}

//class Program {
//    static void Main(){
//        LimitedInt li1 = new LimitedInt();
//        LimitedInt li2 = new LimitedInt();
//        LimitedInt li3 = new LimitedInt();
//        LimitedInt li4 = new LimitedInt();
//        li1.TheValue = 10;
//        li2.TheValue = 26;
//        Console.WriteLine("li1:{0}, li2:{1}",li1.TheValue,li2.TheValue);

//        li3 = -li1;
//        Console.WriteLine("-{0} = {1}",li1.TheValue, li3.TheValue);
//        li3 = li2 - li1;
//        Console.WriteLine("{0} - {1} = {2}",li2.TheValue, li1.TheValue, li3.TheValue);
//        li3 = li1 - li2;
//        Console.WriteLine("{0} - {1} = {2}", li1.TheValue, li2.TheValue, li3.TheValue);
//    }
//}

//ex3
//using System.Reflection;

//class SomeClass
//{
//    public int Field1;
//    public int Field2;

//    public void Method1(){ }
//    public int Method2() { return 1;}
//}

//class Program
//{
//    static void Main()
//    {
//        Type t = typeof(SomeClass);
//        FieldInfo[] f1 = t.GetFields();
//        MethodInfo[] mi = t.GetMethods();
//        
//        foreach(FieldInfo f in f1)
//            Console.WriteLine("Field : {0}", f.Name);
//        foreach(MethodInfo m in mi)
//            Console.WriteLine("Method: {0}", m.Name);
//    }
//}

class SomeClass
{ 
}

class Program
{
    static void Main()
    {
        SomeClass s = new SomeClass();

        Console.WriteLine("Type s: {0}",s.GetType().Name);
    }
}