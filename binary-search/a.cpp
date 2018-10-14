#include <iostream>

using namespace std;
int main(){
    int n,k;
    cin >> n >> k;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < k; i++){
        int x;
        cin >> x;

        int l = 0;
        int r = n - 1;
        while(l<r){
            int mid = (l+r)/2;
            if(a[mid]<x) l = mid+1;
            else r = mid;
        }
        if(a[l] == x) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}