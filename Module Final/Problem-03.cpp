#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int value){
        this->data = value;
        this->left = NULL;
        this->right = NULL;
    }

};

vector<int>v;

void levelOrder(Node* root,int level){
    int count = 0;
    queue<Node*>currLevel;
    queue<Node*>nextLevel;

    if(root == NULL)return;
    currLevel.push(root);

    while(!currLevel.empty()){
        Node* temp = currLevel.front();
        currLevel.pop();

        if(count==level){
            v.push_back(temp->data);
        }

       
        if(temp->left){
            nextLevel.push(temp->left);
        }
        if(temp->right){
            nextLevel.push(temp->right);
        }

        if(currLevel.empty()){
            swap(currLevel,nextLevel);
            count++;
        }
    }
}

void buildTree(Node* root, int a, int b){
    if(root==NULL)  return;
    if(root->data == a){
        if(root->left==NULL){
            root->left = new Node(b);
            return;
        }
        root->right = new Node(b);
        return;
    }
    else{
        buildTree(root->left,a,b);
        buildTree(root->right,a,b);
    }

    
}

int main(){
    int n,e;
    cin>>n>>e;

    Node* root = new Node(0);

    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        buildTree(root,a,b);
    }

    int l;
    cin>>l;

    levelOrder(root,l);

    for(auto i : v){
        cout<<i<<" ";
    }

    return 0;

}

/* 
15 14
0 1
0 2
1 3 
1 4
2 5
2 6
3 7
3 8
4 9
4 10
5 11
5 12
6 13
6 14
 */