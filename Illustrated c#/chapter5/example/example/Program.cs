using System;

//ex_1
//class MyClass
//{
//    public int Sum(int x, int y)
//    {
//        return x + y;
//    }

//    public float Avg(float input1, float input2)
//    {
//        return (input1 + input2) / 2.0F;
//    }
//}

//class Program
//{
//    static void Main()
//    {
//        MyClass myT = new MyClass();
//        int someInt = 6;

//        Console.WriteLine("Newflash: Sum: {0} andf {1} is {2}",5, someInt, myT.Sum(5, someInt));
//        Console.WriteLine("Newflash: Sum: {0} andf {1} is {2}",5, someInt, myT.Avg(5, someInt));
//    }
//}

//ex_2
//class MyClass
//{
//    public int Val = 20;
//}

//class Program
//{
//    static void MyMethod(MyClass f1, int f2)
//    {
//        f1.Val = f1.Val + 5;
//        f2 = f2 + 5;
//        Console.WriteLine("f1.Val:{0}, f2: {1}", f1.Val, f2);
//    }
//    static void Main()
//    {
//        MyClass a1 = new MyClass();
//        int a2 = 10;

//        MyMethod(a1, a2);
//        Console.WriteLine("f1.Val: {0}, f2: {1}",a1.Val, a2);
//    }
//}

//ex_3
//class MyClass
//{
//    public int Val = 20;
//}

//class Program
//{
//    static void MyMethod(ref MyClass f1, ref int f2)
//    {
//        f1.Val = f1.Val + 5;
//        f2 = f2 + 5;
//        Console.WriteLine("f1.Val:{0},f2:{1}", f1.Val, f2);
//    }

//    static void Main()
//    {
//        MyClass a1 = new MyClass();
//        int a2 = 10;

//        MyMethod(ref a1, ref a2);
//        Console.WriteLine("f1.Val: {0}, f2: {1}",a1.Val, a2);
//    }
//}

//ex_4
//class MyClass { public int Val = 20;}

//class Program
//{
//    static void RefAsParameter(ref MyClass f1)
//    {
//        f1.Val = 50;
//        Console.WriteLine("After member assignment: {0}",f1.Val);
//        f1 = new MyClass();
//        Console.WriteLine("After new object creation: {0}",f1.Val);
//    }

//    static void Main()
//    {
//        MyClass a1 = new MyClass();

//        Console.WriteLine("Before method call: {0}",a1.Val);
//        RefAsParameter(ref a1);
//        Console.WriteLine("After method call:  {0}",a1.Val);
//    }
//}

//ex_5
//class MyClass
//{
//    public int Val = 20;
//}
//class Program {
//    static void MyMethod(out MyClass f1, out int f2)
//    {
//        f1 = new MyClass();
//        f1.Val = 25;
//        f2 = 15;
//    }

//    static void Main()
//    {
//        MyClass a1 = null;
//        int a2;

//        MyMethod(out a1, out a2);
//        Console.WriteLine("The value a1 is {0} a2 is {1}",a1.Val, a2);
//    }
//}

//ex_6
class MyClass
{
    public void ListInts(params int[] inVals)
    {
        if ((inVals != null) && (inVals.Length != 0))
            for (int i = 0; i < inVals.Length; i++)
            {
                inVals[i] = inVals[i] * 10;
                Console.WriteLine("{0}", inVals[i]);
            }
    }
}

//class Program
//{
//    static void Main()
//    {
//        int first = 5, second = 6, third = 7;

//        MyClass mc = new MyClass();
//        mc.ListInts(first, second, third);

//        Console.WriteLine("{0}, {1}, {2}", first, second, third);
//    }
//}

class Program
{
    static void Main()
    {
        int[] myArr = new int[] { 5, 6, 7 };

        MyClass mc = new MyClass();
        mc.ListInts(myArr);

        foreach (int x in myArr)
            Console.WriteLine("{0}", x);

    }
}