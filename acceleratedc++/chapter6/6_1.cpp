#include<vector>
#include<string>

using std::string;
using std::vector;

vector<string> frame(const vector<string>& v);
vector<string> hcat(const vector<string>& left, const vector<string>& right);
string :: size_type width(const vector<string>& s);

int main(void)
{
	return 0;
}

vector<string> frame(const vector<string>& v)
{
	vector<string> ret;
	typedef vector<string>::const_iterator iter;
	string::size_type maxlen = width(v);
	string border(maxlen + 4, '*');

	ret.push_back(border);


	for(iter i = v.begin(); i != v.end(); i++ ){
		ret.push_back("* " + *i + string(maxlen - i.size() ,' ' + " *"));
	}

	ret.push_back(border);

	return ret;
}

vector<string> hcat(const vector<string>& left, const vector<string>& right)
{
	vector<string> ret;
	typedef vector<string>::const_iterator iter;

	string::size_type width1 = width(left) + 1;
	iter i = left.begin(), j = right.begin();

	while(i != left.end() || j != right.end()){
		string s;

		if (i != left.end()){
			s = *i;
			i++;
		}

		s += string(width1 - s.size(), ' ');

		if (j != right.end()){
			s += *j;
			j++;
		}

		ret.push_back(s);
	}
	
	return ret;
}

string :: size_type width(const vector<string>& s)
{
	;
}
