#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int k=0; k<t; k++){
        int n;
        cin>>n;
        int earn[n];
        int spend[n];
        for(int i=0; i<n; i++){
            cin>>earn[i];
        }
        for(int i=0; i<n; i++){
            cin>>spend[i];
        }

        int earnSum[n];
        earnSum[0]=earn[0];
        for(int i=1;i<n;i++){
            earnSum[i] = earnSum[i-1]+earn[i];
        }

        int spendSum[n];
        spendSum[0]=spend[0];
        for(int i=1;i<n;i++){
            spendSum[i] = spendSum[i-1]+spend[i];
        }

        int q;
        cin>>q;
        string s="";
        for(int i=0;i<q;i++){
            int index;
            cin>>index;
            int a = earnSum[index]-spendSum[index];
            if(a>=0){
                s = s+ "1 ";
            }
            else{
                s = s+ "0 ";
            }

        }
        cout<<s;
        cout<<endl;
    }
}