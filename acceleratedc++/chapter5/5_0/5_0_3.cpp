#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using std::max;
using std::cout;
using std::endl;
using std::string;
using std::vector;


string :: size_type width(const vector<string>& v);
vector<string> frame(const vector<string>& v);
vector<string> vcat(const vector<string>& top , const vector<string>& bottom);
vector<string> hcat(const vector<string> & left, const vector<string>& right);
void print_string(const vector<string> & v);

int main()
{
    vector<string> frame_result, split_result;
    vector<string> vcat_string, hcat_string;
   //string n_string = "this is an example to illustrate framing";
    
    vector<string> n_string;
    n_string.push_back("this is an");
    n_string.push_back("example");
    n_string.push_back("to");
    n_string.push_back("illustrate");
    n_string.push_back("framing");

    frame_result = frame(n_string);
    print_string(frame_result);
    vcat_string = vcat(n_string, frame_result);
    hcat_string = hcat(n_string, frame_result);
    print_string(vcat_string);
    print_string(hcat_string);

    return 0;
}


string :: size_type width(const vector<string>& v)
{
    string :: size_type maxlen = 0;
    for (vector<string> :: size_type i = 0; i != v.size(); ++i)
	maxlen = max(maxlen, v[i].size());
    return maxlen;
}

vector<string> frame(const vector<string>& v)
{
    vector<string> ret;
    string::size_type maxlen = width(v);
    string border(maxlen + 4, '*');

    //write the top border
    ret.push_back(border);

    //write each interior row, bordered by an asterisk and a space
    for (vector<string> :: size_type i = 0; i != v.size(); i++){
	ret.push_back("* " + v[i] + string(maxlen - v[i].size(), ' ') + " *");
    }

    ret.push_back(border);

    return ret;
}

vector<string> vcat(const vector<string>& top , const vector<string>& bottom)
{
    //copy the top picture
    vector<string> ret = top;

    //copy entire bottom picture
    for (vector<string>::const_iterator it = bottom.begin(); it != bottom.end(); ++it)
    {
	ret.push_back(*it);
    }

    return ret;
}

vector<string> hcat(const vector<string> & left, const vector<string>& right)
{
    vector<string> ret;

    //add 1 to leave a space between picture
    string::size_type width1 = width(left) + 1;

    //indices to look at elements from left and right respectively
    vector<string> :: size_type i = 0, j = 0;

    while (i != left.size() || j != right.size()){
        //construct new string to hold characters from both pictures
        string s;

        //cooy a row from the left hand side, if there is one
        if (i != left.size())
            s = left[i++];

        //pad to full width
        s += string(width1 - s.size(), ' ');

        //copy a row from the right-hand side, if there is one
        if (j != right.size())
            s += right[j++];

        //add s to the picture we're creating
        ret.push_back(s);
    }
    return ret;
}


void print_string(const vector<string> & v)
{
    for (string::size_type i = 0; i != v.size(); i++)
    {
        cout << v[i] << endl;
    }
}
