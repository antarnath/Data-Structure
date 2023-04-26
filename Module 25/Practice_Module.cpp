#include<bits/stdc++.h>
#include"MYSTACK.h"

using namespace std;

int precisionCalculate(char c){
    if(c=='^'){
        return 3;
    }
    else if(c=='*' || c=='/'){
        return 2;
    }
    else if(c=='+' || c=='-'){
        return 1;
    }
    else return -1;
}

string infixToPrefix(string chk){
    reverse(chk.begin(),chk.end());
    Stack <char> st;

    string result;

    for(int i=0;i<chk.length();i++){
        if((chk[i]>='a' && chk[i]<='z') || (chk[i]>='A' && chk[i]<='Z')){
            result += chk[i];
        }
        else if(chk[i]==')'){
            st.push(chk[i]);
        }
        else if(chk[i]=='('){
            while(!st.empty() && st.Top()!=')'){
                result += st.pop();
            }
            if(!st.empty()){
                st.pop();
            }
        }
        else{
            while(!st.empty() && precisionCalculate(st.Top())>=precisionCalculate(chk[i])){
                result += st.pop();
            }
            st.push(chk[i]);
        }
    }

    while(!st.empty()){
        result += st.pop();
    }

    reverse(result.begin(),result.end());
    return result;
}


int main(){
    string infix,prefix;
    cin>>infix;

    prefix = infixToPrefix(infix);

    cout<<endl<<prefix<<endl;
}