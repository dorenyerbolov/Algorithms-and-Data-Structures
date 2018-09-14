#include <list>
#include <iostream>
#include <string>

using namespace std;
int main(){
	int cases = 0, p, c;
	//freopen("output1.txt","w", stdout);
	while(cin >> p >> c){
		list<int> myL;
		if(p == 0 && c == 0){
			return 0;
		}
		printf ("Case %d:\n", ++cases);
		for(int i = 1; i <= p && i <= 1000; i++){
			myL.push_back(i);
		}
		for(int i = 0; i < c ; i++){
			char s;
			cin >> s;
			if(s == 'N'){
				int n = myL.front();
				myL.pop_front();
				myL.push_back(n);
				printf("%d\n", n);
			}	
			else {
				int x;
				cin >> x;
				myL.remove(x);
				myL.push_front(x);
			}	
		}


	}
	return 0;
}