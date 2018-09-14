	#include <iostream>
	#include <list>
	#include <algorithm>
	#include <bits/stdc++.h>
	using namespace std;
	int main(){
		list<int> myList;
		int n, x;
		string str;
		cin >> n;
		for(int i = 0; i < n; i++){
			cin >> str;
			if(str == "insert"){
				cin >> x;
				myList.push_front(x);
			}
			else if (str == "delete"){
				cin >> x;
				for(list<int>::iterator it = myList.begin(); it!=myList.end();it++){
					if(*it == x){
						myList.erase(it);
						break;
					}
				}
			}
			else if (str == "deleteFirst"){
				myList.pop_front();
			}
			else if (str == "deleteLast"){
				myList.pop_back();
			}
		}	

		for(list<int>::iterator it = myList.begin(); it != myList.end(); it++){
			if(it != myList.begin()){
				cout << ' ';	
			}
			cout << *it;
		}
		cout << endl;
		return 0;
	}