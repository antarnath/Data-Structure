#include<bits/stdc++.h>
#include"MYSTACK.h"
using namespace std;

void insertAtBottom(Stack <int> &st, int chkElement){
    if(st.empty()){
        st.push(chkElement);
        return;
    }

    int topElement = st.Top();
    st.pop();
    insertAtBottom(st,chkElement);

    st.push(topElement);


}
void reverseStack(Stack <int> &st){
    if(st.empty())  return;

    int topElement = st.Top();
    st.pop();

    reverseStack(st);
    insertAtBottom(st,topElement);
}
int main(){

    Stack <int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    reverseStack(st);

    while(!st.empty()){
        cout<<st.pop()<<endl;
    }
    return 0;
}