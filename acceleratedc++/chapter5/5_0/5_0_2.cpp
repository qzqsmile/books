#include<iostream>
#include<string>
#include<vector>

using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;

vector<string> split (const string& s);

int main()
{
    string s = "who is your daddy";
    vector<string> ret;

    ret = split(s);
    for (vector<string>::const_iterator iter = ret.begin(); iter != ret.end(); iter++)
    {
	cout << (*iter) << endl;
    }

    return 0;
}

vector<string> split (const string& s)
{
    vector<string> ret;
    typedef string::size_type string_size;
    string_size i = 0;

    while (i != s.size()){
	//ignore leading blanks
	// invariant characters in range [original i, current i] are all sppaces

	while (i != s.size() && isspace(s[i]))
	    ++i;

	// find end of the next word
	string_size j = i;

	//invariant:none of the characters in range [original j, current j] is a space
	while (j != s.size() && !isspace(s[j]))
	    ++j;

	if (i != j){
	    ret.push_back(s.substr(i, j - i));
	    i = j;
	}
    }

    return ret;
}
