#include <iostream>

using namespace std;
int lower_bound(int *a, int el, int size){
	int l = 0;
	int r = size - 1;
	int ans = 0;
	while(l<=r){
		int m = (l+r)/2;

		if(el == a[m]){
			ans = m;
			r = m - 1;
		}
		else if(a[m]>el) r = m - 1;
		else l = m + 1;
	}
	return ans;
}
int upper_bound(int *a, int el, int size){
	int l = 0;
	int r = size - 1;
	int ans = 0;
	while(l<=r){
		int m = (l+r)/2;

		if(el == a[m]){
			ans = m;
			l = m + 1;
		}
		else if(a[m]>el) r = m - 1;
		else l = m + 1;
	}
	return ans;
}
int main(){
	int n, m, el;
	cin >> n >> m;
	int a[n];
	for(int i = 0;i < n; i++){
		cin >> a[i];
	}
	for(int i = 0;i < m; i++){
		cin >> el;
		if(upper_bound(a, el, n)+lower_bound(a, el, n)!=0){
			cout << lower_bound(a, el, n)+1 << " " << upper_bound(a, el, n)+1 << endl;
		}
		else cout << 0 << endl;
	}
	return 0;
}