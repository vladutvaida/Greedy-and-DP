#include <iostream>
#include <math.h>
#include<fstream>
#define MAX 1005
#define INF 1LL<<60
using namespace std;

long long P, D, B;
long long t[MAX], nrC[MAX], d[MAX];

int main() {
	ifstream file1("planificare.in");
	ofstream file2("planificare.out");
	file1 >> P >> D >> B;
	for(int i = 1; i <= P; ++i)
		file1 >> t[i];
	long long auxd;
	for(int i = 1; i <= P; ++i) {
		d[i] = d[i - 1] + pow((D - t[i]), 3);
		nrC[i] = nrC[i - 1] + 1;
		long long dur = t[i];
		for(int j = i - 1; j; --j) {
			dur += B + t[j];
			if(dur > D)
				break;
			auxd = d[j - 1] + pow((D - dur), 3);
			if(auxd < d[i]) {
				d[i] = auxd;
				nrC[i] = nrC[j - 1] + 1;
			}
		}
	}

	long long dur = t[P];
	
	for(int i = P-1;i >= 1;i --)
	{
		if(dur + B + t[i] <= D)
		{
			dur += B + t[i];
		}	
		else break;
	}
	auxd = (D - dur) * (D - dur) * (D - dur); 
	d[P] -= auxd;
	file2 << d[P] << " " << nrC[P] << "\n";
	return 0;
}
