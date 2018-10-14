#include <bits/stdc++.h>
using namespace std;
int main(){
	int cnt;
	freopen("input.txt", "r", stdin);
	cin >> cnt;
	while(cnt--){
		string str;
		string ans = "YES";
		stack<char> myStack;
		cin >> str;
		for(int i = 0; i < str.length(); i++){
			if(!myStack.empty() && str[i] == ')' && myStack.top() == '(') myStack.pop();
			else if(!myStack.empty() && str[i] == ']' && myStack.top() == '[') myStack.pop();
			else if(!myStack.empty() && str[i] == '}' && myStack.top() == '{') myStack.pop();
			else myStack.push(str[i]);
		}


		if(myStack.empty()){
			cout << ans << endl;
		}
		else if(!myStack.empty()){
			ans = "NO";
			cout << ans << endl;
		}
	}
	


	return 0;
}
