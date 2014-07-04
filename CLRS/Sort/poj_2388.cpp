#include<iostream>
#include<string>
#include<vector>

using namespace std;

void quicksort(vector<int>& a, vector<int>::iterator begin ,vector<int>::iterator end)
{
	int temp = 0;
	vector<int> :: iterator index_end = begin + 1;
	if ((end - begin) > 2){ 
		for (vector<int> :: iterator iter = (begin + 1); iter != end; iter++){
			if (*iter < *begin) 
			{   
				int temp = *index_end;
				*index_end = *iter;
				*iter = temp;
				index_end++;
			}   
		}   
		temp = *begin;  
		*begin = *(index_end - 1); 
		*(index_end - 1) = temp;
		quicksort(a,begin,index_end);
		quicksort(a,index_end,end);
	}   
}

int main(void)
{
	int x  = 0, result = 0, count = 0;
	vector<int> a;
	cin >> x;
	count = x;
	while (cin >> x)
		a.push_back(x);
	quicksort(a, a.begin(), a.end());
	result = a[count / 2];
	cout << result << endl;
	
	return 0;
}
