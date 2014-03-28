using System;
//using BaseClassNS;

//ex1
//class SomeClass
//{
//    public string Field1 = "base class field";
//    public void Method1(string value) {
//        Console.WriteLine("Base class -- Method1:   {0}",value);
//    }
//}

//class OtherClass : SomeClass
//{
//    public string Field2 = "derived class field";
//    public void Method2(string value) {
//        Console.WriteLine("Derived class--Method2: {0}",value);
//    }
//}

//class Program
//{
//    static void Main() {
//        OtherClass oc = new OtherClass();

//        oc.Method1(oc.Field1);
//        oc.Method1(oc.Field2);
//        oc.Method2(oc.Field1);
//        oc.Method2(oc.Field2);
//    }
//}

//ex2
//class SomeClass
//{
//    public string Field1 = "SomeClass Field1";
//    public void Method1(string value)
//    { Console.WriteLine("SomeClass.Method1: {0}", value); }
//}

//class OtherClass : SomeClass
//{
//    new public string Field1 = "otherClass Field1";
//    new public void Method1(string value)
//    {
//        Console.WriteLine("OtherClass.Method1: {0}",value);
//    }
//}

//class Program
//{
//    static void Main()
//    {
//        OtherClass oc = new OtherClass();
//        oc.Method1(oc.Field1);
//    }
//}

//ex3
//class SomeClass {
//    public string Field1 = "Field1 -- In the base class";
//}

//class OtherClass : SomeClass {
//    new public string Field1 = "Field1 -- In the derived class";

//    public void PrintField1()
//    {
//        Console.WriteLine(Field1);
//        Console.WriteLine(base.Field1);
//    }
//}

//class Program {
//    static void Main()
//    {
//        OtherClass oc = new OtherClass();
//        oc.PrintField1();
//    }
//}

//ex4
//class MyBaseClass
//{
//    public void Print()
//    {
//        Console.WriteLine("This is the base class");
//    }
//}

//class MyDerivedClass : MyBaseClass
//{
//    new public void Print()
//    {
//        Console.WriteLine("This is the derived class");
//    }
//}

//class Program
//{
//    static void Main()
//    {
//        MyDerivedClass derived = new MyDerivedClass();
//        MyBaseClass mybc = (MyBaseClass)derived;

//        derived.Print();
//        mybc.Print();
//    }

//ex5
//class MyBaseClass
//{
//    virtual public void Print()
//    {
//        Console.WriteLine("This is the base class.");
//    }
//}

//class MyDerivedClass : MyBaseClass
//{
//    public override void Print()
//    {
//        Console.WriteLine("This is the derived class.");
//    }
//}

//class Program
//{
//    static void Main()
//    {
//        MyDerivedClass derived = new MyDerivedClass();
//        MyBaseClass mybc = (MyBaseClass)derived;

//        derived.Print();
//        mybc.Print();
//    }
//}

//ex6
//abstract class AbClass
//{
//    public void IdentifyBase()
//    { Console.WriteLine("I am AbClass"); }

//    abstract public void IdentifyDerived();
//}

//class DerivedClass : AbClass
//{
//    override public void IdentifyDerived()
//    { Console.WriteLine("I am DerivedClass"); }
//}

//class Program
//{
//    static void Main()
//    {
//        DerivedClass b = new DerivedClass();
//        b.IdentifyBase();
//        b.IdentifyDerived();
//    }
//}

//ex7
class MyData
{
    private double D1;
    private double D2;
    private double D3;

    public MyData(double d1, double d2, double d3)
    {
        D1 = d1; D2 = d2; D3 = d3;
    }

    public double Sum()
    {
        return D1 + D2 + D3;
    }
}

static class ExtendMyData
{
    public static double Average(MyData md)
    {
        return md.Sum() / 3;
    }
}

class Program
{
    static void Main()
    {
        MyData md = new MyData(3,4,5);
        Console.WriteLine("Average: {0}",ExtendMyData.Average(md));
    }

}