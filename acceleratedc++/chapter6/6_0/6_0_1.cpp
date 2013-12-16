#include<iostream>
#include<iterator>
#include<algorithm>
#include<string>
#include<vector>

using std::string;
using std::iterator;
using std::vector;
using std::copy;

bool is_palindrome(const string& s);
bool space(char c);
bool not_space(char c);
vector < string > split(const string & str);

int main(void)
{
	vector < string > bottom, ret;
	//version 1
	for (vector < string >::const_iterator it = bottom.begin();
	     it != bottom.end(); ++it)
		ret.push_back(*it);
	//version 2
	ret.insert(ret.end(), bottom.begin(), bottom.end());
	//verison 3
	copy(bottom.begin(), bottom.end(), back_inserter(ret));

	return 0;
}

bool space(char c)
{
	return isspace(c);
}

bool not_space(char c)
{
	return !isspace(c);
}

vector < string > split(const string & str)
{
	typedef string::const_iterator iter;
	vector < string > ret;

	iter i = str.begin();
	while (i != str.end()) {
		i = find_if(i, str.end(), not_space);
		iter j = find_if(i, str.end(), space);

		if (i != str.end())
			ret.push_back(string(i, j));
		i = j;
	}

	return ret;
}

bool is_palindrome(const string& s)
{
	return equal(s.begin(), s.end(), s.rbegin());
}
