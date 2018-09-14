#include <iostream>
#include <bits/stdc++.h>

using namespace std;
struct Job{
	int priority, position;
	Job(int p, int pos){
		priority = p;
		position = pos;
	}
};
int main(){
	int t;
	cin >> t;
	while(t--){
		queue<Job> myQ;
		int n, m;
		cin >> n >> m;
		int array[n];
		for(int i = 0; i<n; i++){
			int a;
			cin >> a;
			myQ.push(Job(a, i + 1));
			array[i] = a;
			//myPq.push(Job(a, i + 1));	
			}

			int timeCnt = 0;
			sort(array, array + n);
			int tmp = n - 1;
			while(!myQ.empty()){
				Job newJob = myQ.front();
				myQ.pop();
				if(newJob.priority < array[tmp]){
					myQ.push(newJob);
				}
				else {
					timeCnt++;
					if(newJob.position == m + 1){
						cout << timeCnt << endl;
					}
					tmp--;;
				}
			}
		}

		return 0;
	}

