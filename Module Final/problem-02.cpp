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

void inorder(Node* root,int *maxi){
    if(root==NULL)  return;
    inorder(root->left,maxi);
    if(root->data > *maxi)   *maxi = root->data;
    inorder(root->right,maxi);
}

Node* deletion(Node* root, int key)
{
    if(root==NULL)
        return NULL;
    if(root->left==NULL && root->right==NULL)
    {
        if(root->data==key)
            return NULL;
        else
            return root;
    }
    Node* key_node=NULL;
    Node* temp;
    Node* last;
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        temp=q.front();
        q.pop();
        if(temp->data==key)
            key_node=temp;
        if(temp->left)
        {
            last=temp;//storing the parent node
            q.push(temp->left);
        }
        if(temp->right)
        {
            last=temp;// storing the parent node
            q.push(temp->right);
        }
             
         
    }
      if(key_node!=NULL)
    {
        key_node->data=temp->data;//replacing key_node's data to deepest node's data
        if(last->right==temp)
            last->right=NULL;
        else
            last->left=NULL;
        delete(temp);
     }
    return root;
}

void deleteandPrint(Node* root){

    int maxi = -1;
    inorder(root,&maxi);
    cout<<maxi<<endl;

    root = deletion(root,maxi);

}

Node* insertValue(Node* root, int data)
{
    Node* newNode = new Node(data);
    if (root == NULL) {
        root = newNode;
        return root;
    }
    queue<Node*> q;
    q.push(root);
 
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
 
        if (temp->left != NULL)
            q.push(temp->left);
        else {
            temp->left = newNode;
            return root;
        }
 
        if (temp->right != NULL)
            q.push(temp->right);
        else {
            temp->right = newNode;
            return root;
        }
    }
}

int main(){
    int a;
    cin>>a;
    Node* root = new Node(a);
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
        if(x!=-1) n1 = new Node(x);
        if(y!=-1) n2 = new Node(y);

        presentRoot->left = n1;
        presentRoot->right = n2;

        if(n1!=NULL) q.push(n1);
        if(n2!=NULL) q.push(n2);
    }

    int Q;
    cin>>Q;
    for(int i=0;i<Q;i++){
        int a,b;
        cin>>a;
        if(a==2){
            deleteandPrint(root);
        }
        else if(a==1){
            cin>>b;
            insertValue(root,b);
        }

    }

    return 0;
    
}