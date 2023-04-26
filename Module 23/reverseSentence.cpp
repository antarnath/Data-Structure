#include<bits/stdc++.h>
#include"MYSTACK.h"
using namespace std;

void reverseSentence(string chk){
    Stack <string> st;
    string word = "";
    for(int i=0;i<chk.length();i++){
        if(chk[i]==' '){
            st.push(word);
            word = "";
        }
        else{
            word = word + chk[i];
        }
    }
    st.push(word);
    while(!st.empty()){
        cout<<st.pop()<<" ";
    }
}
int main(){
    string st;
    getline(cin,st);
    reverseSentence(st);

    return 0;
    

}