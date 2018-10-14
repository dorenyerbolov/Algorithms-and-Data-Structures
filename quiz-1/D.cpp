#include <bits/stdc++.h>

using namespace std;


double first[99999], second[99999], third[99999], four[99999];
int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> first[i] >> second[i] >> third[i] >> four[i];
	}
	for(int i = 0; i < n; i++){
		printf ("Case %d:\n", ++i);	
		double output = first[i] * sqrt(four[i]/(four[i]+1));
		printf("%.6f", output);
	}
	return 0;
}