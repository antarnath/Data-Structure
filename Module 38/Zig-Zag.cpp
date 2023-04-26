// Zig-Zag order print in binary search tree

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

Node* insertBST(Node* root, int value){
    
    if(root == NULL){
        return new Node(value);
    }

    if(value < root->data){
        root->left = insertBST(root->left,value);
    }
    else if(value > root->data){
        root->right = insertBST(root->right, value);
    }
}

void zigzagTraversal(Node* root){
    stack<Node*>currLevel;
    stack<Node*>nextLevel;

    if(root == NULL)return;
    currLevel.push(root);
    bool leftToRight = true;
    while(!currLevel.empty()){
        Node* temp = currLevel.top();
        currLevel.pop();

        if(temp){
            cout<<temp->data<<" ";
        }

        if(leftToRight){
            if(temp->left){
                nextLevel.push(temp->left);
            }
            if(temp->right){
                nextLevel.push(temp->right);
            }
        }
        else{
            if(temp->right){
                nextLevel.push(temp->right);
            }
            if(temp->left){
                nextLevel.push(temp->left);
            }
        }
        if(currLevel.empty()){
            swap(currLevel,nextLevel);
            leftToRight = !leftToRight;
        }
    }
}

void inorder(Node* root){
    if(root==NULL)return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}


int main(){
    Node* root = NULL;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int value;
        cin>>value;
        root = insertBST(root,value);
    }

    inorder(root);
    cout<<endl;

    zigzagTraversal(root);
}