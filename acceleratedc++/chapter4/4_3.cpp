#include<iostream>
#include<iomanip>
#include<string>

#define N 10
// M os not including 1000

using std::cout;
using std::endl;
using std::cin;
using std::setw;
using std::to_string;
// g++ must be with the -std=c++11
using std::string;


int main()
{   
    int n_length;
    int result_length;
    string n_string;

    //store the longest length of the string
    n_string = to_string(N);
    n_length = n_string.size();
    n_length += 1;                //add a space in the argument of setw
    n_string = to_string(N*N);
    result_length = n_string.size();
    result_length += 1;
   
    cout << "The result is " << endl;
    for (int i = 1; i != (N + 1); i++)
    {
        cout <<  setw(n_length) << i << setw(result_length) << i * i << endl;
    }
    
    return 0;
}

