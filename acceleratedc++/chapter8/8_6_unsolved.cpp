#include<iostream>
#include<string>
#include<map>
#include<algorithm>

using std::copy;
using std::map;
using std::pair;
using std::string;

int main(void)
{
	map<int, string> m;
	vector<int>x;
	x.insert(pair<int,string>(1,"a"));
	m.insert(pair<int,string>(2,"b"));
	m.insert(pair<int,string>(3,"c"));

//	copy(m.begin(), m.end(), back_inserter(x));
//	copy(x.begin(), x.end(), back_inserter(m));

	return 0;
}
