#include <iostream>
using namespace std;
int right_bound(int *a, int el, int size){
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
int left_bound(int *a, int el, int size){
	int l = 0;
	int r = size - 1;
	while(l<r){
		int m = (l + r)/2;
		if(a[m] >= el) r = m;
		else l = m + 1; 
		if(r-l==1){
			if(a[l] == el) return l+1;
			else if(a[r] == el) return r+1;
			else return 0;
		}
	}	
	if(a[l] == el) return l+1;
	else return 0;
}
int main(){
	int n, m, value;
	freopen("input.txt", "r", stdin);
	cin >> n >> m;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 0; i < m; i++){
		cin >> value;
		if(left_bound(a, value, n) + right_bound(a, value, n) != 0){
			cout << left_bound(a, value, n) << " " << right_bound(a, value, n) << endl;
		}
		else cout << 0 << endl;
	}
	return 0;
}