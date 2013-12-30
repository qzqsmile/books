#include<map>
#include<cctype>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using std::cin;
using std::map;
using std::cout;
using std::isspace;
using std::string;
using std::endl;
using std::vector;
using std::istream;

vector<string> split(const string& str);
map<string, vector<int> >xref(istream& in, vector<string> find_words(const string&) = split);
bool space(char c);
bool not_space(char c);

int main(void)
{
	map<string, vector<int> >ret = xref(cin);

	for (map<string, vector<int> > :: const_iterator it = ret.begin(); it != ret.end(); ++it){
		cout << it -> first ;

		vector<int>::const_iterator line_it = it->second.begin();
        if (*line_it == *((it -> second.end()) - 1)){
            cout << " occurs on line ";
        }else {
            cout << " occurs on lines ";
        }
		cout << *line_it;

		++line_it;

		while(line_it != it->second.end()){
			cout << ", " << *line_it;
			++line_it;
		}
		cout << endl;
	}
	return 0;
}

map<string, vector<int> >xref(istream& in, vector<string> find_words(const string&))
{
	string line;
	int line_number = 0;
	map<string, vector<int> >ret;

	while(getline(in, line)){
		++line_number;

		vector<string> words = find_words(line);
		for (vector<string>::const_iterator it = words.begin(); it != words.end(); ++it)
			ret[*it].push_back(line_number);
	}

	return ret;
}


bool space(char c)
{
	return isspace(c);
}

bool not_space(char c)
{
	return !isspace(c);
}

vector<string> split(const string& str)
{
	typedef string::const_iterator iter;
	vector<string> ret;

	iter i = str.begin();
	while(i != str.end()){
		i = find_if(i, str.end(), not_space);
		iter j = find_if(i, str.end(), space);

		if(i != str.end())
			ret.push_back(string(i, j));
		i = j;
	}

	return ret;
}
