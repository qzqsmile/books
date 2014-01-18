#include<vector>
#include<iostream>
#include<iterator>

using std::vector;
using std::cout;
using std::endl;
using std::cin;

int main()
{
    vector<int> num;
    num.push_back(3);

    cout << num.begin() << num.end();
    cout << endl;

    return 0;
}
