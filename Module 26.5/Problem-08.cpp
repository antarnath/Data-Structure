#include<bits/stdc++.h>
using namespace std;



int main(){

    int n;
    cin>>n;
    stack<int>st;
    int minvalue = INT_MAX;
    for(int i=0;i<n;i++){
        int value;
        cin>>value;
        minvalue = min(minvalue,value);
        st.push(minvalue);

    }

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }

    return 0;
}