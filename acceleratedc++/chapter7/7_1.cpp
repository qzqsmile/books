#include<iostream>
#include<algorithm>
#include<map>
#include<string>
#include<vector>

using std::vector;
using std::cout;
using std::cin;
using std::sort;
using std::endl;
using std::map;
using std::transform;
using std::string;

//    template<typename A, typename B>
//std::pair<B,A> flip_pair(const std::pair<A,B> &p)
//{
//    return std::pair<B,A>(p.second, p.first);
//}
//
//    template<typename A, typename B>
//std::map<B,A> flip_map(const std::map<A,B> &src)
//{
//    std::map<B,A> dst;
//    std::transform(src.begin(), src.end(), std::inserter(dst, dst.begin()), 
//            flip_pair<A,B>);
//    return dst;
//}

int main()
{
    string s;
    map<string, int> counters;

    while(cin >> s)
        ++counters[s];

    map <int, vector<string> > reverse;
    for (map<string, int>::const_iterator it = counters.begin(); it != counters.end(); ++it){
        reverse[it->second].push_back(it->first);
    }
    
    for (map<int , vector<string> > :: const_iterator it = reverse.begin(); it != reverse.end(); it++){
        for (vector<string> :: const_iterator str = it->second.begin(); str != it->second.end(); str++){
            cout << *str << "\t" << counters[*str] << endl;
        }

    }

    return 0;
}
