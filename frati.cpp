#include<iostream>
#include<algorithm>
#include<vector>
#include <fstream>
using namespace std;

bool sortbysum(pair<int,int> &a,
              pair<int,int> &b)
{	if(a.first + a.second == b.first + b.second)
	{
		return a.first > b.first;
	}
			
    return (a.first + a.second > b.first + b.second);
}
int main()
{
	ifstream file1("frati.in");
	ofstream file2("frati.out");
	int n;
	file1>>n;
	int i;
	int a = 0,b = 0;
	pair<int,int> x,y;
	int x1,y1,x2,y2,x3,y3;
	std::vector< std::pair<int,int> > array;   
	int current = 1;
	for(i = 0;i < n;i ++)
	{
		while(file1>>x1>>y1)
		{
			array.push_back(make_pair(x1,y1));
			
		}
	}
	
	sort(array.begin(),array.end(),sortbysum);
	
	int ok = 0;
	while(n)
		{
			n--;
			if(n == 0)
			{
				if(current == 1)
					a += array[0].first;
				else
					b += array[0].second;
				
				break;		
			}
			if(current == 1)
			{
				a += array[0].first;
			
				array.erase(array.begin());
				current = 2;
				
			}
			else
			{
				i = 0;
				while(array[0].first + array[0].second == array[i+1].first +array[i+1].second)
				{	
					i++;
				}
			
				current = 1;
				b += array[i].second;
				array.erase(array.begin() + i);
			
				
			}
			
		}
	
	file2<<a<<" "<<b;	
				
	return 0;
	

}
