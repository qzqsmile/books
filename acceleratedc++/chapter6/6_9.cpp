#include<string>
#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>

using std::accumulate;
using std::string;
using std::cout;
using std::endl;
using std::vector;

int main () {
    string str = "Hello World!";
    vector<string>  vec (10,str);
    string a = accumulate( vec.begin(), vec.end(), string("") );
    cout << a << endl;

    return 0;
}
