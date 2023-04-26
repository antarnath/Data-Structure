#include<bits/stdc++.h>
using namespace std;


void print_list(list<int>l){
    list<int>::iterator it;

    for(it=l.begin();it!=l.end();it++){
        cout<<*it<<endl;
    }
}
int main(){
    list<int>l;

    l.push_back(10);
    l.push_back(5);
    l.push_front(15);

    
    print_list(l);
}