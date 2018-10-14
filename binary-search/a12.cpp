#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n, k;
	cin » n » k;
	int a[n], b[k];
	for(int i = 0; i < n; i++) cin » a[i];
		for(int i = 0; i < k; i++) cin » b[i];

			for(int i = 0; i < k; i++)
			{
				int clst = a[0];
				int l = 0, r = n-1;
				while(l <= r)
				{
					int m = (l + r)/2;
					int clstD = abs(clst - b[i]), midD = abs(a[m] - b[i]);
					if(midD < clstD || (midD == clstD && a[m] < clst)) clst = a[m];
					if(b[i] < a[m]) r = m - 1;
					else if(b[i] > a[m]) l = m + 1;
					else{
						clst = a[m];
						break;
					}
				}
				cout « clst « endl;
			}
		}
		return 0;
	}