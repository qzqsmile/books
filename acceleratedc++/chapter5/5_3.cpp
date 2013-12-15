#include<iostream>
#include<string>
#include<vector>
#include<list>

using std::list;
using std::vector;
using std::cout;

typedef vector instead;

int main()
{
    instead<int> num; 

    for (instead<int> :: iterator iter = num.begin(); iter != num.end(); iter++)
    {
        *iter = 1;
    }

    return 0
}
