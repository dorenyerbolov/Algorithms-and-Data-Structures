#include <bits/stdc++.h>
#include <stack>
using namespace std;
int main(){
	string str;
	string ans = "yes";
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
		ans = "no";
		cout << ans << endl;
	}


	return 0;
}




	// 	if(!myStack.empty()){
	// 		if(str[i] == ')'){
	// 			if(myStack.top() == '(') myStack.pop();
	// 		}
	// 		else if(str[i] == '}'){
	// 			if(myStack.top() == '{') myStack.pop();
	// 		}
	// 		else if(str[i] == ']'){
	// 			if(myStack.top() == '[') myStack.pop();
	// 		}
	// 		else myStack.push(str[i]);
	// 	}
	// 	else if (myStack.empty()){
	// 		myStack.push(str[i]);
	// 	}
	// 