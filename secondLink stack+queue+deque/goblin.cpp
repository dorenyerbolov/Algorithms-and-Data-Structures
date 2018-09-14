#include <iostream>
#include <deque>
#include <string>
using namespace std;

deque<int> first, second;
void check(){
	if(first.size()<second.size()){
		first.push_back(second.front());
		second.pop_front();
	}
}
int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		char c;
		int number;
		cin >> c;
		switch(c){
			case '+':
			cin >> number;	
			second.push_back(number);
			check();
			break;
			case '*':
			cin >> number;
			second.push_front(number);
			check();
			break;
			case '-':
			int output = first.front();
			first.pop_front();
			check();
			cout << output << endl;
			break;
		}
	}
	
	return 0;
}