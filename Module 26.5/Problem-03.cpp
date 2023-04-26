#include<bits/stdc++.h>
using namespace std;

stack <int> sortedStack(stack<int>st){
    stack <int> tempSt;

    while(!st.empty()){
        int temp = st.top();
        st.pop();


        while(!tempSt.empty() && tempSt.top()>temp){
            st.push(tempSt.top());
            tempSt.pop();
        }   

        tempSt.push(temp);
    }

    return tempSt;
}

int main(){

    int n;
    cin>>n;

    stack <int> st;

    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        st.push(val);
    }

    stack <int> recive = sortedStack(st);
    stack <int> sort;
    for(int i=0;i<n;i++){
        int value = recive.top();
        recive.pop();
        sort.push(value);
    }

    while(!sort.empty()){
        int value = sort.top();
        cout<<value<<" ";
        sort.pop();
    }


    return 0;
}