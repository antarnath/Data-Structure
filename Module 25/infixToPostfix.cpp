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

int postfixEvaluation(string chk){
    Stack <int> st;

    for(int i=0;i<chk.length();i++){
        if(chk[i]>='0' && chk[i]<='9'){
            st.push(chk[i]-'0');
        }
        else{
            int b = st.pop();
            int a = st.pop();
             switch (chk[i])
            {
            case '+':
                st.push(a+b);
                break;
            case '-':
                st.push(a-b);
                break;
            
            case '*':
                st.push(a*b);
                break;

            case '/':
                st.push(a/b);
                break;

            case '^':
                st.push(pow(a,b));
                break;
            
            default:
                break;
            }
        }
    }

    return st.Top();
}

string infixToPostfix(string chk){
    string result;
    Stack <char> st;
    for(int i=0;i<chk.length();i++){
        if(chk[i]>='0' && chk[i]<='9'){
            result += chk[i];
        }
        else if(chk[i]=='('){
            st.push(chk[i]);
        }
        else if(chk[i]==')'){
            while(!st.empty() && st.Top()!='('){
                result += st.pop();
            }
            st.pop();
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

    return result;
}
//(4*(3+5))-(2+0)
int main(){
    cout<<infixToPostfix("(5*((6^2)+(7-(2/6))))-((7*(8+1))+(5*4))");

    cout<<endl<<endl<<postfixEvaluation(infixToPostfix("(5*((6^2)+(7-(2/6))))-((7*(8+1))+(5*4))"));
}