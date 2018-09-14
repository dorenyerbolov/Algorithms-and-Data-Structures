#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; 
	while(true){
		stack<int> sideStreet; 
		int n, enter = 1; //n - the number of love mobiles, enter - the mobile that should enter next
		cin >> n;
		if(n == 0) return 0;
		for(int i = 0;i < n;i++){
			int mob; // mob - input mobile
			cin >> mob;
			if(mob == enter){
				enter++;
				while(!sideStreet.empty() && sideStreet.top() == enter){
					enter++;
					sideStreet.pop();	
				}
				continue;
			}
			sideStreet.push(mob);
		}
		if(sideStreet.empty()){
			cout << "yes" << endl;
		}
		else cout << "no" << endl;
	}
	

	return 0;
}