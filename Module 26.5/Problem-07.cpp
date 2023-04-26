#include<bits/stdc++.h>
using namespace std;


void reverseString(string str){
    stack<char>st;

    for(int i=0;i<str.length();i++){
        if(str[i]!='.'){
            st.push(str[i]);
        }
        else{
            while(!st.empty()){
                cout<<st.top();
                st.pop();
            }
            cout<<".";
        }
    }

    while (!st.empty())
    {
        cout<<st.top();
        st.pop();
    }
    
}

int main(){

    string st;
    cin>>st;

    reverseString(st);
}