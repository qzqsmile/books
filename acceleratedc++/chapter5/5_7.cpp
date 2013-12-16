#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<ios>

using std::vector;
using std::string;
using std::max;
using std::endl;
using std::cout;
using std::cin;

vector < string > frame(const vector < string > &v);
string::size_type width(const vector < string > &v);

int main(void)
{
//	vector < string > v;
//	vector<string> ret;
//	string x;
//	while(cin >> x)
//	{
//		v.push_back(x);
//	}
//	ret = frame(v);
//	for (vector<string>::size_type i = 0; i < ret.size(); i++)
//	{
//		cout << ret[i] << endl;
//	}
    vector<string> v;
    frame(v);

    for (vector<string>::size_type i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }

return 0;
}


vector < string > frame(const vector < string > &v)
{
	vector < string > ret;
	string::size_type maxlen = width(v);
	string border(maxlen + 4, '*');

	ret.push_back(border);

	for (vector < string >::size_type i = 0; i != v.size(); ++i) {
		ret.push_back("* " + v[i] +
			      string(maxlen - v[i].size(), ' ') + " *");
	}

	ret.push_back(border);

	return ret;
}

string::size_type width(const vector < string > &v)
{
	string::size_type maxlen = 0;
	for (vector < string >::size_type i = 0; i != v.size(); ++i)
		maxlen = max(maxlen, v[i].size());

	return maxlen;
}
