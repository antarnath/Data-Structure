#include<bits/stdc++.h>
using namespace std;

void reverseFirstKElement(queue<int>&Queue,int k){
    if(Queue.empty() && k>Queue.size()){
        return;
    }

    if(k<=0){
        return;
    }

    stack<int>st;

    for(int i=0;i<k;i++){
        st.push(Queue.front());
        Queue.pop();
    }

    while(!st.empty()){
        Queue.push(st.top());
        st.pop();
    }

    for(int i=0;i<Queue.size()-k;i++){
        Queue.push(Queue.front());
        Queue.pop();
    }
}

void printQueue(queue<int>Queue){
    while(!Queue.empty()){
        cout<<Queue.front()<<" ";
        Queue.pop();
    }
}

int main(){

    int n,k;
    cin>>n>>k;

    queue <int> Queue;
    for(int i=0;i<n;i++){
        int value;
        cin>>value;
        Queue.push(value);
    }

    reverseFirstKElement(Queue,k);

    printQueue(Queue);

    return 0;
}