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


void verticalOrder(Node* root,int idx,map<int,vector<int>>&m){
    if(root==NULL) return;

    m[idx].push_back(root->data);

    verticalOrder(root->left,idx-1,m);
    verticalOrder(root->right,idx+1,m);

}

int main(){
    Node* root = new Node(0);
    root->left = new Node(1);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(8);

    map<int,vector<int>>m;

    verticalOrder(root,0,m);

    for(auto i : m){
        cout<<i.first<<": ";
        for(int j=0;j<(i.second).size();j++){
            cout<<(i.second)[j]<<" ";
        }
        cout<<endl;
    }
}