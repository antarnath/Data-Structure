#include<bits/stdc++.h>
#include"MYSTACK.h"

using namespace std;

int prefixEvluation(string chk){
    Stack <int> st;
    for(int i=chk.length()-1;i>=0;i--){
        if(chk[i] >= '0' && chk[i] <='9'){
            st.push(chk[i]-'0');
        }
        else{
            int a = st.pop();
            int b = st.pop();
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
int main(){
    string chk;
    cin>>chk;
    int a = prefixEvluation(chk);
    cout<<a<<endl;
}