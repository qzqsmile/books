#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int dp[5][6] = {};
int n = 4;
int w[4] = {2,1,3,2}, v[4]={3,2,4,2};

int rec(int i, int j)
{
	if(dp[i][j] >= 0)
	{
		return dp[i][j];
	}

	int res;
	if(i == n)
		res = 0;
	else if(j < w[i])
		res = rec(i+1, j);
	else{
		res = max(rec(i+1, j - w[i]) + v[i], rec(i+1,j));
	}
	dp[i][j] = res;

	return res;
}

int main(void)
{
	memset(dp, -1, sizeof(dp));
	int result = rec(0,5);

	//printf("%d\n", result);
	cout << result << endl;
	return 0;
}
