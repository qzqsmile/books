#include<iostream>
#include<string>
#include<vector>

using namespace std;

void print_num(const vector<int>& a);

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

void print_num(const vector<int> &a)
{
	for (vector<int>::const_iterator iter = a.begin(); iter != a.end(); iter++)
		cout << *iter << " ";
	cout << endl;
}

int main(void)
{
	int my[] = {1,2,10,7,68,8,5,3,6,4};
	vector<int> a(my,my+sizeof(my) / sizeof(int));
	print_num(a);
	quicksort(a,a.begin(),a.end());
	print_num(a);

	return 0;
}
