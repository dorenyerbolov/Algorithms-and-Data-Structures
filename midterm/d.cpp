#include <bits/stdc++.h>

using namespace std;

int binary_Search(int sum[], int l, int r, int m, int x){
	while(l < r){
		int mid = (l + r) / 2;
		int curSum = sum[mid] - sum[x - 1];
		if(m <= curSum){
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	return r;
}

int main(){
	int n, m, cnt = 0, ans = 1000000;
	cin >> n >> m;
	int a[n];
	int sum[n + 1];
	sum[0] = 0;

	for(int i = 0; i < n; i++){
		cin >> a[i];
		cnt += a[i];
		sum[i + 1] = cnt;
	}

	for(int i = 1; i <= n; i++){
		int index = binary_Search(sum, i, n, m, i);

		if(sum[index] - sum[i - 1] >= m){
			ans = min(ans, index - i + 1);
		}
	}

	cout << ans;
	return 0;
}