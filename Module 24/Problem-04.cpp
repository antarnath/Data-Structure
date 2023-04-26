#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;

    int arr[n][m];
    int b = n*m;
    int arr1[b];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
            int a = (i*m+j);
            arr1[a] = arr[i][j];
        }
    }
    for(int i=0;i<b-1;i++){
        for(int j=i+1;j<b;j++){
            if(arr1[i]==arr1[j]){
                arr1[j] = -1;
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int a = (i*m+j);
            arr[i][j] = arr1[a];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;

}