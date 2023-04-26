#include<bits/stdc++.h>
using namespace std;

void print_vector(vector<int>v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
int main(){

    int n;
    cin>>n;
    vector<int>v(n);
    

    print_vector(v);

    return 0;
}