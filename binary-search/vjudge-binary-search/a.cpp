#include <iostream>

using namespace std;
string binarySearch(int *a, int el, int size){
	int l = 0;
	int r = size - 1;
	while(l<r){
		int m = (l+r)/2;
		if(a[m] < el) l = m + 1;
		else r = m;
	}
	if(a[l] == el) return "YES";
	else return "NO";
}
int main(){
	int n, m, el;
	
	freopen("collect.in", "r", stdin);
	freopen("collect.out", "w", stdout);
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	cin >> m;
	for(int i = 0; i < m; i++){
		cin >> el;
		cout << binarySearch(a, el, n) << endl;
	}
	return 0;
}