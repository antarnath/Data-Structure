#include<bits/stdc++.h>
using namespace std;


bool balancedBracked(string str){
    stack<char>st;
    st.push(str[0]);
    for(int i=1;i<str.length();i++){
        if(st.empty()){
            st.push(str[i]);
        }
        else if(st.top()=='(' && str[i]==')'||
           st.top()=='{' && str[i]=='}'||
           st.top()=='[' && str[i]==']'){

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
    string str;
    cin>>str;


    if(balancedBracked(str)){
        cout<<"Bracked Balaned"<<endl;
    }
    else{
        cout<<"Bracked not Balanced"<<endl;
    }

}