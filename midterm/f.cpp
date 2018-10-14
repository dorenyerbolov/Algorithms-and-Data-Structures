#include <bits/stdc++.h>

using namespace std;
void bubbleSort(int arr[], int n){
	bool swapped = true;
	int tmp, j = 0;
	while(swapped){
		swapped = false;
		j++;
		for(int i = 0; i < n - j; i++){
			if(arr[i] > arr[i + 1]){
				tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
				swapped = true;
			}
		}
	}
}
int main(){
	int n, cnt = 1, maxH = 1, curH = 1;
	cin >> n;
	int a[n];

	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	bubbleSort(a, n);

	for(int i = 1; i < n; i++){
		if(a[i] != a[i - 1]){
			cnt++;
			curH = 1;
		}
		else {
			curH++;
			if(curH > maxH) maxH = curH;
		}
	}
	cout << maxH << " " << cnt;
	return 0;
}