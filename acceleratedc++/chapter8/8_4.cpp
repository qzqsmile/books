#include<iostream>
#include<algorithm>

template <class Bi> void reverse(Bi begin, Bi end)
{
	while (begin != end){
		--end;
		if(begin != end)
			swap(*begin++, *end);
	}
}

//another vesion

template <class Bi> void reverse(Bi begin, Bi end)
{
	while (begin != end){
		--end;
		if(begin != end){
		}
	}
}

int main(void)
{
	return 0;
}
