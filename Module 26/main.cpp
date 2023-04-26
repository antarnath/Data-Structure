#include<bits/stdc++.h>
#include"MYQueue.h"
using namespace std;

typedef pair<int ,string> mytype;

int main(){
    int n;
    cin>>n;
    Queue <mytype> q;
    for(int i=0;i<n;i++){
        int c1;
        string c2;
        cin>>c1>>c2;
        q.push(make_pair(c1,c2));
    }

    // while(!q.empty()){
    //     mytype chk;
    //     chk = q.pop();
    //     cout<<chk.first<<" | "<<chk.second <<endl;
    // }

    if(!q.empty()){
        cout<<q.Front().first<<" | "<<q.Front().second <<endl;
    }
    if(!q.empty()){
        cout<<q.Back().first<<" | "<<q.Back().second<<endl;
    }
}