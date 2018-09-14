#include <iostream>
#include <queue>
#include <string>
//#include <bits/stdc++.h>
using namespace std;

struct processes{
public:
	string name;
	int time;
};

int main(){
	queue<processes> myQueue;
	int num, quantum;
	cin >> num >> quantum;
	processes procs[num];
	int tm = 0;
	for(int i = 0; i < num; i++){
		cin >> procs[i].name >> procs[i].time;
		myQueue.push(procs[i]);
	}
	while(!myQueue.empty()){
		processes n = myQueue.front();
		myQueue.pop();
		if (n.time > quantum){
			n.time -= quantum;	
			myQueue.push(n);
			tm += quantum;
		}
		else {
			tm += n.time;
			cout << n.name << " " << tm << endl;
		}
	}

return 0;
}