#include<bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin>>t;
    for(int j=0;j<t;j++){
        int n;
        cin>>n;
        char st[n];
        cin>>st;

        queue<char>curr;
        queue<char>next;
        for(int i=0;i<n;i++){
            curr.push(st[i]);
        }

        long unsigned int size = curr.size();
        bool flag = false;

        while(!curr.empty()){
            char top = curr.front();
            curr.pop();
            if(curr.empty()){
                next.push(top);
            }
            else if(top == curr.front()){
                curr.pop();
            }
            else if((top=='R' && curr.front()=='B')||(top=='B' && curr.front()=='R')){
                next.push('P');
                curr.pop();
            }
            else if((top=='R' && curr.front()=='G')||(top=='G' && curr.front()=='R')){
                next.push('Y');
                curr.pop();
            }
            else if((top=='B' && curr.front()=='G')||(top=='G' && curr.front()=='B')){
                next.push('C');
                curr.pop();
            }
            else{
                next.push(top);
            }

            if(curr.empty()){
                swap(curr,next);
                if(size == curr.size()){
                    flag = true;
                }
                else{
                    size = curr.size();
                }
                
            }

            if(flag==true){
                break;
            }
        }

        while(!curr.empty()){
            cout<<curr.front();
            curr.pop();
        }
        cout<<endl;

    }

    return 0;
}