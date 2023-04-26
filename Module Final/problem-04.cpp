#include<bits/stdc++.h>
using namespace std;
int antar= 0;

class Node{
public:
    pair<int,char>data;
    Node* left;
    Node* right;

    Node(int value,char ch){
        this->data.first = value;
        this->data.second = ch;
        this->left = NULL;
        this->right = NULL;
    }

};

void printstring(char s[], int len){
    
    for(int i=0,j=len-1;i<j;i++,j--){
        if(s[i]!=s[j])return;
    }
    // for(int i=0;i<len;i++){
    //     cout<<s[i];
    // }
    // cout<<endl;

    antar++;
}

void allstring(Node* root,char s[],int idx){
    if(root==NULL)  return;
    s[idx] = root->data.second;
    idx++;
    if(root->left==NULL && root->right==NULL){
        printstring(s,idx);
    }
    else{
        allstring(root->left,s,idx);
        allstring(root->right,s,idx);
    }
}

int main(){
    string s;
    cin>>s;
    int a;
    cin>>a;
    Node* root = new Node(a,s[a]);
    queue<Node*>q;
    q.push(root);

    while (!q.empty())
    {
        Node* presentRoot = q.front();
        q.pop();
        int x,y;
        cin>>x>>y;

        Node* n1 = NULL;
        Node* n2 = NULL;

        if(x!=-1){
            n1 = new Node(x,s[x]);
        }
        if(y!=-1){
            n2 = new Node(y,s[y]);
        }

        presentRoot->left = n1;
        presentRoot->right = n2;

        if(n1!=NULL) q.push(n1);
        if(n2!=NULL) q.push(n2);
    }

    if(root==NULL)  return 0;
    char st[30]="";
    allstring(root,st,0);


    cout<<antar;

}


/* 
Rahat Khan Pathan
ABABDBACBBCDBAEBDBAA
0
1 3
4 8 2 7
14 -1 5 -1 -1 -1 11 9
-1 16 -1 6 10 -1 -1 19
17 15 -1 -1 -1 12 -1 -1
18 -1 -1 -1 13 -1
-1 -1 -1 -1
output: 5
 */
