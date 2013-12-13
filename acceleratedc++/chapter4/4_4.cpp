#include<iostream>
#include<iomanip>
#include<string>
#include<ios>

#define N 100

using std::cout;
using std::endl;
using std::cin;
using std::setw;
using std::to_string;
// g++ must be with the -std=c++11
using std::string;
using std::setprecision;
using std::streamsize;


int main()
{   
    int n_length;
    int result_length;
    string n_string;
    streamsize prec = 5;

    //step1 calculate the n_length of the integer
    n_length = prec + 3;         //consider the demical point and the prec that needed
    result_length = prec + 3;
   
    cout << "The result is " << endl;
    for (double i = 1.1; i < (N + 1); i++)
    {
        cout << setw(n_length) << setprecision(prec) << i 
            << setw(result_length) << setprecision(prec) << i * i << endl;
    }
    
    return 0;
}

