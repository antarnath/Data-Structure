#include<bits/stdc++.h>
using namespace std;


int vis[1000]={0};

int main(){
    int n,e;
    cin>>n>>e;
    vector<pair<int,int>>v;

    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        v.push_back(make_pair(a,b));
    }

    queue<int>curr;
    queue<int>next;

    curr.push(v[0].first);
    vis[0]=1;

    int l;
    cin>>l;
    if(l==0){
        cout<<curr.front();
        return 0;
    }
    int count = 1;

    while(!curr.empty()){
        int top = curr.front();
        curr.pop();

        for(auto i: v){
            if(top == i.first){
                if(vis[i.second]==0){
                    vis[i.second]=1;
                    next.push(i.second);
                }
            }
        }

        if(l>count ){
            if(curr.empty()){
                count++;
                swap(curr,next);
            }
        }
        else{
            break;
        }
    }

    while(!next.empty()){
        cout<<next.front()<<" ";
        next.pop();
    }

    return 0;

}







/* 
13 12
1 2
1 3
2 4
2 5
3 6
5 7
7 8
7 9
8 10
8 11
9 12
9 13

 */