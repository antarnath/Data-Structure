#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> PAIR;

int main(){
    vector<int> v(3,-1);
    
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    v.push_back(4);

    cout<<endl;
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }

    cout<<endl;
    v.push_back(100);
    for(auto i:v){
        cout<<i<<" ";
    }

    cout<<endl<<endl<<endl;

    priority_queue<PAIR, vector<PAIR>, greater<PAIR>> pq;

    pq.push(make_pair(1,5));
    pq.push(make_pair(7,6));
    pq.push(make_pair(3,2));
    pq.push(make_pair(0,58));

    while(!pq.empty()){
        cout<<pq.top().first<<" | "<<pq.top().second<<endl;
        pq.pop();
    }

}