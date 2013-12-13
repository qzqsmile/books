#include<iostream>
#include<iomanip>

#define N 100

using std::cout;
using std::endl;
using std::setw;

int main(void)
{
    cout << "The result is " << endl;

	for(int i = 1; i != (N+1); i++){
        cout << setw(4) << i << setw(6) << i * i << endl;
    }

	return 0;
}
