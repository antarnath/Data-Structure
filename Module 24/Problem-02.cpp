#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int m;
    cin>>m;
    int b[m];
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(b[i]==a[j]){
                a[j]=-1;
                break;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(a[i]>=0){
            cout<<a[i]<<" ";
        }
    }
    return 0;
}