#include<iostream>
#include<string>
#include<vector>
#include<list>

using std::list;
using std::vector;
using std::endl;
using std::cout;

//typedef vector instead;
typedef vector<int> instead;

void print_num(instead &v);

int main()
{

    instead num; 
    num.resize(5);

    for (instead :: iterator iter = num.begin(); iter != num.end(); iter++)
    {
        *iter = 1;
    }
    print_num(num);

    return 0;
}

void print_num(instead &v)
{
    for (instead::const_iterator iter = v.begin(); iter != v.end(); iter++)
    {
        cout << (*iter) << endl;
    }
}
