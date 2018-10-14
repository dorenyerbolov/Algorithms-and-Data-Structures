#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    int a[100100],b[100100];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<k;i++){
        cin>>b[i];
    }
    for(int i=0;i<k;i++){
        int left=0,right=n-1,m,d;
        while(1){
            m=(left+right)/2;
            if(b[i]<a[m]){
                right=m-1;
            }
            if(b[i]>a[m]){
                left=m+1;
            }
            if(b[i]==a[m]){
                d=a[m];
                break;
            }
            if(left>right){
                if(right<0)
                d=a[left];
                else{
                    if(abs(b[i]-a[right])<=abs(b[i]-a[left]))
                        d=a[right];
                    else
                        d=a[left];
                }
                break;
            }
        }
        cout<<d<<endl;
    }
}
