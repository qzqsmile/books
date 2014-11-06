#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int n = 4, W = 5;
int w[4] = {2,1,3,2}, v[4] = {3,2,4,2};
int dp[5][6] = {};

int rec(int i, int j, int sum)
{
	int res;
	if(dp[i][j] >= 0)
	{
		return dp[i][j];
	}
	if(i == n)
	{
		res = sum;
	}else if(j < w[i])
	{
		res = rec(i+1, j ,sum);
	}else
	{
		res = max(rec(i+1, j, sum), rec(i+1, j-w[i], sum + v[i]));
	}
	return dp[i][j] = res;
}

int main(void)
{
	memset(dp,-1,sizeof(dp));
	int result = rec(0,5,0);	

	cout << result << endl;
	return 0;
}
