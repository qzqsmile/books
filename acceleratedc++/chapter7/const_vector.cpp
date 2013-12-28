#include<iostream>
#include<vector>
#include<map>
#include<string>

using std::vector;
using std::cout;
using std::endl;
using std::map;
using std::string;

void example(const map<string, vector<int> > & num);

int main()
{
    map<string, vector<int> >num;

    num["A"].push_back(1);

    return 0;
}

void example(const map<string, vector<int> > & num)
{
    cout <<  num["A"].size() << endl;
}

