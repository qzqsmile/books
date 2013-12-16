#include<iostream>
#include<string>
#include<vector>
#include<list>

using std::list;
using std::vector;
using std::cout;

//typedef vector instead;
typedef list<int> instead;
// typedef is different from #define,
//#define only mean replace without checking out the style
//typedef reaplace must be a style,
//for example typedef list instead is illegal

int main()
{

    instead num; 

    for (instead :: iterator iter = num.begin(); iter != num.end(); iter++)
    {
        *iter = 1;
    }

    return 0;
}
