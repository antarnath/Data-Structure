#include<bits/stdc++.h>
using namespace std;


int main(){

    int n;
    cin >> n;
    int array[n];

    for(int i=0; i<n; i++){
        cin >> array[i];
    }

    map<int, int> M;

    int sort[n];

    for(int i=0; i<n; i++){
        M[array[i]]++;
    }

    map<int,int> :: iterator it;
    int idx=0;
    for(it = M.begin(); it!=M.end(); it++){
        // cout<<(*it).first <<" | "<<(*it).second<<endl;
        for(int i=0;i<(*it).second;i++){
            sort[idx] = it->first;
            idx++;
        }
    }

    for(int i=0;i<n;i++){
        cout<<sort[i]<<" ";
    }

    return 0;
}