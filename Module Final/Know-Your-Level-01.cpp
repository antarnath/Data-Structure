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

    curr.push(0);
    vis[0]=1;

    int l;
    cin>>l;

    if(l==0){
        cout<<curr.front();
        return 0;
    }
    
    int count = 1;

    bool flag = false;

    while(!curr.empty()){
        int top = curr.front();
        curr.pop();

        for(auto i : v){
            if(i.first==top){
                if(vis[i.second]==0){
                    vis[i.second]=1;
                    next.push(i.second);
                }
            }
        }

        if(curr.empty()){
            if(l==count){
                flag = true;
            }
            else{
                swap(curr,next);
                count++;
            }
        }

        if(flag){
            break;
        }
    }

    while(!next.empty()){
        cout<<next.front()<<" ";
        next.pop();
    }
}


/* 
13 17
0 1
0 2
1 3
1 4
1 5
2 5
2 6
3 10
4 10
5 11
5 7
11 8
8 9
8 13
9 12
13 12
10 8
 */

