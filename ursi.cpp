#include <iostream>
#include <fstream>
#include<string>
using namespace std;
long long dp[2000][2000];
long long d = 1000000000 + 7;	
int main() {
	ifstream file1("ursi.in");
	ofstream file2("ursi.out");
	char msg[2000];
	
	int i,j;
	int length = 0;
	int nr = 0;
	while(!file1.eof())
	{
		length++;
		file1>>msg[length];
		if(msg[length] == '^')
			nr++;
	}
	nr = nr / 2;
	
	dp[1][1] = 1;

	for(i = 2;i < length;i ++)
	{
		for(j = 0;j <= nr;j ++)
		{
			if(msg[i] =='_')
			{	
				dp[i][j] = (dp[i-1][j] * j)%d;
			}
			else
			{
				if(j+1 > nr)
					dp[i][j] = dp[i-1][j-1]%d;	
				else if(j == 0)
					dp[i][j] = dp[i-1][j+1] * (j + 1)%d;
				else dp[i][j] = (dp[i-1][j+1] * (j + 1)%d + dp[i-1][j-1]%d)%d;
				
			}
		}
	}
	file2<<dp[length-1][0];
	return 0;
}
