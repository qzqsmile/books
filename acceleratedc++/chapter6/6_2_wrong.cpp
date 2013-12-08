#include<iostream>
#include<algorithm>
#include<cctype>
#include<string>
#include<vector>

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;

vector<string> find_urls(const string& s);
string::const_iterator url_beg(string::const_iterator b, string::const_iterator e);
bool not_url_char(char c);
string::const_iterator url_end(string::const_iterator b, string::const_iterator e);
void print_string(const vector<string>& url_string);

int main(void)
{
	vector<string> url_string;
	string x;

	cout << "Please input the string" << endl;
	cin >> x;

	url_string = find_urls(x);
	print_string(url_string);

	return 0;
}

vector<string> find_urls(const string& s)
{
	vector<string> ret;
	typedef string::const_iterator iter;
	iter b = s.begin(), e = s.end();

	while(b != e){
		b  = url_beg(b, e);

		if (b != e){
			iter after = url_end(b, e);
			ret.push_back(string(b, after));
			b = after;
		}
	}

	return ret;
} 

bool not_url_char(char c)
{
	static const string url_ch = "~;/?:@=&$-_+!*'(),""";

	return !(isalnum(c) || find(url_ch.begin(), url_ch.end(), c) != url_ch.end());
}

string::const_iterator url_beg(string::const_iterator b, string::const_iterator e)
{
	static const string sep = "://";
	typedef string::const_iterator iter;

	iter i = b;

	while((i = search(i, e, sep.begin(),sep.end())) != e){
		if(i != b && i + sep.size() != e){
			iter beg = i;
			while (beg != b && isalpha(beg[-1]))
				--beg;

			if(beg != i && !not_url_char(i[sep.size()]))
				return beg;
		}
		i += sep.size();
	}

	return e;
}

string::const_iterator url_end(string::const_iterator b,string::const_iterator e)
{
	return find_if(b, e, not_url_char);
}

void print_string(const vector<string>& url_string)
{
	for (vector<string> :: size_type i = 0; i < url_string.size(); i++){
		cout << url_string[i] << endl;
	}
}
