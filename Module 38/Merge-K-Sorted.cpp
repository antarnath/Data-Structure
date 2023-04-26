#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> PAIR;

int main(){
    int k;
    cin>>k;

    vector<vector<int>> allValues(k);

    for(int i=0; i<k; i++){
        int size;
        cin>>size;
        allValues[i] = vector<int>(size);
        for(int j=0; j<size; j++){
            cin>>allValues[i][j];
        }
    }   

    vector<int>indexTracker(k,0);
    priority_queue<PAIR, vector<PAIR> ,greater<PAIR>> pq;

    for(int i=0;i<k;i++){
        pq.push(make_pair(allValues[i][0],i));
    }

    vector<int>v;

    while(!pq.empty()){
        PAIR x = pq.top();
        v.push_back(x.first);
        pq.pop();

        if(indexTracker[x.second]+1 < allValues[x.second].size()){
            pq.push(make_pair(allValues[x.second][indexTracker[x.second]+1],x.second));
        }

        indexTracker[x.second]++;
    }

    for(auto element : v){
        cout<<element<<" ";
    }

   
}