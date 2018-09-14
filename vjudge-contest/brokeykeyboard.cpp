#include <list>
#include <algorithm>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
	//freopen("input.txt", "r", stdin);

	string str;
	while(cin >> str){
		list<char> myList;
		list<char>::iterator it = myList.begin();
		for(int i = 0;i < str.length();i++){
			if (str[i] == '['){
				it = myList.begin();
			}
			else if (str[i] == ']'){
				it = myList.end();
			}
			else if (str[i] != ']' && str[i] != '['){
				myList.insert(it, str[i]);
			}

		}
			for(it = myList.begin(); it != myList.end(); it++){
				cout << *it << "";
			}
			cout << endl;
	}





	return 0;
}