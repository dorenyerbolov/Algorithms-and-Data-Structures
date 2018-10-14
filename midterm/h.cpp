#include <iostream>
#define RANGE 52
using namespace std;

void countingSort(int arr[],int n){
    int count[RANGE]={0};
    int i;
    int out[n];
    
    
    for(i=0;i<n;i++)
    ++count[arr[i]];
    
    for(i=1;i<RANGE;i++)
    count[i]+=count[i-1];		
    
    for(i=n-1;i>=0;i--){
        out[count[arr[i]]-1]=arr[i];
        --count[arr[i]];
    }
    
    for(i=0;i<n;i++)
    arr[i]=out[i];

}
void print(int arr[],int n){
    for(int i=0;i<n;i++){
    	cout << arr[i];
    	if(i != n-1) cout << '+';
    }
}

int main() {
	int cnt = 0;
	string s;
	cin >> s;
	for(int i = 0; i < s.size(); i++){
		if(s[i] != '+'){
			cnt++;
		}
	}

	int arr[cnt];
	cnt = 0;
	for(int i = 0; i < s.size(); i++){
		if(s[i] != '+'){
			arr[cnt] = s[i] - '0';
			cnt++;
		}
	}
	countingSort(arr,cnt);
	
    print(arr,cnt);
	
	return 0;
}