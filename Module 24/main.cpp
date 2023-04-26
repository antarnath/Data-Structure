#include<bits/stdc++.h>
#include"Antar.h"
using namespace std;

int main(){
    Stack <char> st;
    st.push('a');
    st.push('b');
    st.push('c');
    st.push('d');
    st.push('e');
    st.push('f');

    cout<<st.mid()<<endl;
    cout<<st.size()<<endl;

    while(!st.empty()){
        cout<<st.pop()<<endl;
    }
}