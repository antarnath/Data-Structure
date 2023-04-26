#include<bits/stdc++.h>
using namespace std;
int vis[1000] = {0};
int antar=0;

void finddirection(vector<int>v[],int i){
    for(auto j=v[i].begin();j!=v[i].end();j++){
        if(vis[*j]==0){
            vis[*j]=1;
            antar++;
            finddirection(v,*j);
        }
    }
}


int main(){
    int n,e;
    cin>>n>>e;

    vector<int>v[n];
    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
    }

    int k;
    cin>>k;
    vis[k]=1;

    finddirection(v,k);

    cout<<antar<<endl;
    return 0;
}