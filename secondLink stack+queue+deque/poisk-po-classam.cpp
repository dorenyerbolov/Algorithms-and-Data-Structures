#include <bits/stdc++.h>

using namespace std;

int main(){
	map<int, vector<string> > myMap;
	map<int, vector<string> >::iterator it;
	int cl;
	string name;

	freopen("input.txt", "r", stdin);
	while(cin >> cl >> name){
		myMap[cl].push_back(name);
	}

	for(it = myMap.begin(); it != myMap.end(); it++){
		for(int i = 0; i < (*it).second.size(); i++){
			cout << (*it).first << " " << (*it).second[i] << endl;
		}
	}




	return 0;
}
