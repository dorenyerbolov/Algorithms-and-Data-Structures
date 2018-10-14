#include <iostream>

using namespace std;
int main(){
	int n, cnt = 0, num = 1;
	cin >> n;
	while(true){
		if(num>=n){
			cout << cnt << endl;
			break;
		}
		cnt++;
		num*=2;

	}
	return 0;
}