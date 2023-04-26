#include<bits/stdc++.h>
using namespace std;


int main(){
    int n,e;
    cin>>n>>e;

    vector<pair<int,int>>v;
    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        v.push_back(make_pair(a,b));
    }
    int l;
    cin>>l;
    int count = 0;

    queue<int>currq;
    queue<int>nextq;

    currq.push(0);



    while(count <= l){
        if(count==l){
            while(!currq.empty()){
                cout<<currq.front()<<" ";
                currq.pop();
            }
            return 0;
        }

        int value = currq.front();
        currq.pop();

        for(auto i : v){
            if(i.first == value){
                nextq.push(i.second);
            }
        }

        if(currq.empty()){
            swap(currq,nextq);
            count++;
        }
    }

    return 0;
}