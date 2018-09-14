#include <iostream>
#include <string>
#include <queue>
#include <bits/stdc++.h>
using namespace std;
int main(){
	int one, two, cnt = 0;
	queue <int> first, second;

	for(int i = 0; i < 5;i++){
		cin >> one;
		first.push(one);
	}
	for(int i = 0; i < 5;i++){
		cin >> two;
		second.push(two);
	}

	while(true){
		if(cnt==1000000){
			cout << "botva" << endl;
			return 0;
		}		
		if(first.size() == 0){
			cout << "second " << cnt << endl;
			return 0;
		}
		if(second.size() == 0){				
			cout << "first " << cnt << endl; 
			return 0;
		}
		if (first.front() == 9 && second.front() == 0){
			int n = first.front();
			int m = second.front();
			first.pop();
			second.pop();
			second.push(n);
			second.push(m);
			cnt++;
			continue;
		}
		if (first.front() == 0 && second.front() == 9){
			int n = first.front();
			int m = second.front();
			first.pop();
			second.pop();
			first.push(n);
			first.push(m);
			cnt++;
			continue;
		}
		if (first.front()<second.front()){
			int n = first.front();
			int m = second.front();
			first.pop();
			second.pop();
			second.push(n);
			second.push(m);
			cnt++;
			continue;
		}
		if (first.front()>second.front()){
			int n = first.front();
			int m = second.front();
			first.pop();
			second.pop();
			first.push(n);
			first.push(m);
			cnt++;
			continue;
		}
		
	}
	
	return 0;
}
