#include <iostream>

using namespace std;
int main(){
	int n, sum = 0;
	cin >> n;
	int a[n], sumArray[n + 1];
	sumArray[0] = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		sum += a[i];
		sumArray[1 + i] = sum;
	}
	int m, rq;
	cin >> m;
	for(int i = 0; i < m; i++){
		cin >>	rq;
		int left = 0, right = n;
		while(left <= right){
			int mid = (left + right) / 2;

			if(rq == sumArray[mid]) {
				cout << mid << "\n";
				break;
			}

			if(rq > sumArray[mid] and rq < sumArray[mid + 1]){
				cout << mid + 1 << "\n";
				break;
			}
			else if (rq < sumArray[mid]){
				right = mid;
			}
			else {
				left = mid + 1;
			}
		}
	}
	return 0;
}