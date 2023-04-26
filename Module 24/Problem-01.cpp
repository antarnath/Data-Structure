#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int maximum=INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]>maximum){
            maximum = arr[i];
        }
    }
    int count[maximum+1]={0};
    for(int i=0;i<n;i++){
        int a = arr[i];
        count[a]++;
    }
    for(int i=0;i<maximum+1;i++){
        if(count[i] != 0){
            cout<<i<< " => " <<count[i]<<endl;
        }
    }

    return 0;
}


