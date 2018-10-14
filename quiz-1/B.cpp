#include <bits/stdc++.h>

using namespace std;
int primes[1201];
stack<int> a, b;
void prime(){
	int MAX_PRIME = 9733;
	int k = 1;
	primes[1] = 2;
	for (int i = 3; i <= MAX_PRIME; i++) {
		bool ok = true;
		for (int j = 2; j <= (int)sqrt(i); j++) {
			if (i % j == 0)
				ok = false;
		}
		if (ok) {
			k++;
			primes[k] = i;
		}
	}

}
void solve(int i){
	int x;
	stack<int> a0;
	while(!a.empty()){
		x = a.top();
		a.pop();
		if(x%primes[i] == 0){
			b.push(x);
		}
		else {
			a0.push(x);
		}	
	}
	while(!b.empty()){
		cout << b.top() << endl;
		b.pop();
	}
	a = a0;
}
int main(){
	prime();
	int n, q, val, k = 1;
	cin >> n >> q;
	for(int i = 0; i < n; i++){
		cin >> val;
		a.push(val);
	}
	while(q--){
		solve(k++);
	}
	while(!a.empty()){
		cout << a.top() << endl;
		a.pop();
	}
	return 0;
}