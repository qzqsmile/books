#include<iostream>
#include<map>
#include<string>
#include<vector>

using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::map;
using std::string;

int main(void)
{
	string s;
	map<string, int> counters;
	
	while(cin >> s)
		++counters[s];

	for (map<string, int>::const_iterator it = counters.begin(); it != counters.end(); ++it){
		cout << it -> first << "/t" << it -> second << endl;
	}

	return 0;
}
