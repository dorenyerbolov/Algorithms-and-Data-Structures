#include <list>
#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;
struct car{
	int carLength; // car's length
	string bank; // the bank at which the car arrives		
};
int main(){
	int c; // the number of test cases
	cin >> c;
	//freopen("output.txt", "w", stdout);
	for(int i = 0; i < c; i++){
		string curPos = "left"; // curPos - current location of our ferry
		deque<car> rightBank, leftBank; // rightBank - array which store cars on the right bank, the same with leftBank array
		int cnt = 0; // cnt - the number of times the ferry has to cross the river
		int l, m; // l - ferry's length, m - number of cars that arrive
		cin >> l >> m;
		l *= 100; // present in cm
		while(m--){
			car myCar;
			cin >> myCar.carLength >> myCar.bank;
			if(myCar.bank == "left"){
				leftBank.push_back(myCar);
			}
			else {
				rightBank.push_back(myCar);
			}
		}
		while(!leftBank.empty() || !rightBank.empty()){
			if(curPos == "left"){
				if(leftBank.empty()){
					cnt++;
					curPos = "right";
				}
				else {
					int sum = 0;
					while(!leftBank.empty() && sum <= l){
						if(sum + leftBank.front().carLength <= l){
							sum += leftBank.front().carLength;
							leftBank.pop_front();
						}
						else {
							cnt++;
							curPos = "right";
							break;
						}
					}
				}
			}
			else if(curPos == "right"){
				if(rightBank.empty()){
					cnt++;
					curPos = "left";
				}
				else {
					int sum = 0;
					while(!rightBank.empty() && sum <= l){
						if(sum + rightBank.front().carLength <= l){
							sum += rightBank.front().carLength;
							rightBank.pop_front();
						}
						else {
							cnt++;
							curPos = "left";
							break;
						}
					}
				}
			}
		} 
		cout << cnt+1 << endl;
	}
	return 0;
}
