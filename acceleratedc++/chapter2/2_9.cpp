#include<iostream>

using std::cout;
using std::endl;
using std::cin;

int main()
{
        int a, b;

        cout << "Please input two number a,b (must be integer) " << endl;
        cin >> a >> b; 

        a > b ? (cout << "The larger number is a "):(a == b ?
                        (cout << "Two number is equal") : (cout << "The larger number is b"));
        
        cout << endl;

        return 0;
}
