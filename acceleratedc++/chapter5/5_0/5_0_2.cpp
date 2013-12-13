#include<iostream>
#include<string>
#include<vector>

using std::string;
using std::vector;

vector<string> split (const string& s);

int main()
{
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
        
        string_size j = i;

        while (j != s.size() && !isspace(s[j]))
            ++j;

        if (i != j){
            ret.push_back(s.substr(i, j - i));
            i = j;
        }
    }
}
