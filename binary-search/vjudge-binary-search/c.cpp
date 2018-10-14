#include <iostream>
#include <cmath>
using namespace std;
int binarySearch(int *a, int el, int size){
	int l = 0;
	int r = size - 1;
	while(l<r){
		int m = (l + r)/2;
		if(a[m] <= el) l = m;
		else r = m - 1; 
		if(r-l==1){
			if(a[r] == el) return r+1;
			else if(a[l] == el) return l+1;
			else return 0;
		}
	}	
	if(a[l] == el) return l+1;
	else return 0;
}
int main(){
	int n, m, el;
	freopen("right.in", "r", stdin);
	freopen("right.out", "w", stdout);
	cin >> n >> m;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 0; i < m; i++){
		cin >> el;
		cout << binarySearch(a, el, n) << endl;
	}

	return 0;
}