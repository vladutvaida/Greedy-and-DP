#include<iostream>
#include<algorithm>
#include<vector>
#include <fstream>
using namespace std;

int main()
{
	ifstream file1("numaratoare.in");
	ofstream file2("numaratoare.out");
	int s,n;
	file1>>s;
	file1>>n;
	long i;
	file1>>i;
	int nr = 0;
	vector<int> aux(n);
	aux[0] = s - n + 1;

	int k,x;
	for(k = 1;k < n;k ++)
		aux[k] = 1;
	int ok = 0;
	int ok1 = 0;
	int b1 = 0;
	int a1 = 0;
	int a,b;
		while(nr < i)
	{	
		ok1 = 0;
		
		if(aux[0] - aux[n - 1] <= 1)
		{	
			ok = 1;
			break;
		}
		
		a = -1;
		b = -1;
		
		
		for(k = n - 1;k >= 0;k --)
		{	
			
			if(aux[1] == 2 && aux[2] == 1)
			{
				b = 0;
				a = 1;
				ok1 = 1;
				break;
			}
			if(a == -1)
			{	a1 = k;
				a = k;
				continue;
			}
			if(aux[a] == aux[k])
			{	a = k;
				continue;
			}
			
			if(b == -1)
			{	
				if(aux[a] <= aux[k] - 2)
				{       b1 = k;
					b = k;
					continue;			
				}
			}
			else
			{
				if(aux[b] == aux[k])
				{
					b = k;
					continue;
				}
				
				
				break;
				
			}		

		}		for(int j = 1;j < n;j++)
				{
					if((aux[j] == 2 && aux[a1] == 2))
					ok1 = 1;
					if((aux[j] == 3 && aux[a1] == 3))
					ok1 = 1;
				}
				if(aux[b1+1] - aux[a] == 1)
				{	
					ok1 = 1;	
				}	
	
				
					aux[b1]--;
					aux[a]++;
				
			
		int kk;

		while(ok1 == 1)	
		{	
			for(kk = n - 1;kk >= b1 + 2;kk --)
			{
 				while(aux[kk] != 1 && aux[b1+1] < aux[b1])
				{	
					aux[kk] --;
					aux[b1+1] ++;
					if(aux[kk] == 1)
						a1--;
				}
			}
			ok1 = 0;
			
				if(aux[b1+2] - aux[a1 - 1] <= 1)
				{	b1++;
					a1--;	
				
					ok1 = 1;
					
				}	
					
					
				
	
		}
		
		
		nr++;
	}	
		if(ok == 1)
			file2<<"-";
		file2<<s<<"=";			
			for(k = 0;k < n;k ++)
			{	file2<<aux[k];
				if(k != n - 1)
 					file2<<"+";
			}	
		file2<<endl;		
		
			
			
			
	
	
	return 0;
}
