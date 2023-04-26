#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    int arr[21]={0};
    arr[1]=1;
    arr[2]=1;
    arr[3]=2;
    for(int i=4;i<21;i++){
        arr[i] = arr[i-1]*2;
    }

    long long int node = pow(2,n-1);

    long long int sum = node*arr[n];

    cout<<sum<<endl;

    return 0;
}