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
vector<string> find_urls(const string& s);
bool not_url_char(char c);
string::const_iterator url_beg(string::const_iterator b, string::const_iterator e);
string::const_iterator url_end(string::const_iterator b,string::const_iterator e);

int main(void)
{
	map<string, vector<int> >ret = xref(cin,find_urls);

	for (map<string, vector<int> > :: const_iterator it = ret.begin(); it != ret.end(); ++it){
		cout << it -> first << " occurs on line(s) ";

		vector<int>::const_iterator line_it = it->second.begin();
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

vector<string> find_urls(const string& s)
{
    vector<string> ret;
    typedef string::const_iterator iter;
    iter b = s.begin(), e = s.end();

    //look through the entire input
    while(b != e){
        //look for one or more letters followed by://
        b  = url_beg(b, e);

        //if we found it
        if (b != e){
            // get the rest of the URL
            iter after = url_end(b, e);
            //remember the URL
            ret.push_back(string(b, after));
            //advance and check for more URLs on this line
            b = after;
        }
    }

    return ret;
}

bool not_url_char(char c)
{
    // characters in addition to alphanumerics, that can appear in a URL
    static const string url_ch = "~;/?:@=&$-_.+!*'(),""";

    // see whether c can appear in a URL and return the negative
    return !(isalnum(c) || find(url_ch.begin(), url_ch.end(), c) != url_ch.end());
}

string::const_iterator url_beg(string::const_iterator b, string::const_iterator e)
{
    static const string sep = "://";
    typedef string::const_iterator iter;

    // i marks where the separator was found
    iter i = b;

    while((i = search(i, e, sep.begin(),sep.end())) != e){
        //make sure the separator isn't at the beginning or end of the line
        if(i != b && i + sep.size() != e){

            //beg marks the beginning of the protocaol-name
            iter beg = i;
            while (beg != b && isalpha(beg[-1]))
                --beg;

            // is there at least one appropriate character begor and after the separator
            if(beg != i && !not_url_char(i[sep.size()]))
                return beg;
        }
        //the separtor we found wasn't part of a URL;advance i past this separartor
        i += sep.size();
    }

    return e;
}



string::const_iterator url_end(string::const_iterator b,string::const_iterator e)
{
    return find_if(b, e, not_url_char);
}

