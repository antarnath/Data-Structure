#include<bits/stdc++.h>
using namespace std;

void reverseQueue(queue<int>&q){
    if(q.size()==0){
        return;
    }

    int top = q.front();

    q.pop();
    
    reverseQueue(q);

    q.push(top);
}

int main(){
    int n;
    cin>>n;

    queue <int> q;
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        q.push(val);
    }

    reverseQueue(q);

    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    
}