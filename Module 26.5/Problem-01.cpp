#include<bits/stdc++.h>
using namespace std;

bool areBracketsBalanced(string str){
    stack <char> st;

    for(int i=0;i<str.length();i++){
        if(st.empty()){
            st.push(str[i]);
        }
        else if(st.top()=='(' && str[i]==')'
            ||st.top()=='{' && str[i]=='}'
            ||st.top()=='[' && str[i]==']'){

                st.pop();
        }
        else{
            st.push(str[i]);
        }

    }
    if(st.empty()){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    string st;
    cin>>st;

    if(areBracketsBalanced(st)){
        cout<<"Balanced"<<endl;
    }
    else{
        cout<<"Not Balanced"<<endl;
    }
}