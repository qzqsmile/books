#include<iterator>
#include<iostream>
#include<algorithm>
#include<vector>

using std::vector;
using std::cin;
using std::cout;
using std::copy;
using std::istream_iterator;
using std::ostream_iterator;

struct Student
{
    int midterm, name, final;
};

int main()
{
    vector<int> v;
    Student s;
    cin >> s.name >> s.midterm >> s.final;

    copy(istream_iterator<int> (cin), istream_iterator<int>(),back_inserter(    v));
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    copy(v.begin(), v.end(), ostream_iterator<int>(cout));

    return 0;
}
