#include<bits/stdc++.h>
using namespace std;

class treeNode{
public:
    int data;
    treeNode *leftChild;
    treeNode *rightChild;

    treeNode(int value){
        data = value;
        leftChild = NULL;
        rightChild = NULL;
    }
};

void findKthNodeInorder(treeNode *root,int k){
    static int count = 0;
    if(root == NULL){
        return;
    }
    findKthNodeInorder(root->leftChild,k);
    findKthNodeInorder(root->rightChild,k);
    count++;
    if(count==k){
        cout<<root->data<<endl;
    }

}
void levelOrderPrint(treeNode *root){
    queue<treeNode *>q;
    if(root != NULL){
        q.push(root);
        q.push(NULL);
    }
    while (!q.empty())
    {
        treeNode *present = q.front();
        while (!q.empty())
        {
            if(q.front()!=NULL){
                cout<<q.front()<<endl;
                q.pop();
            }
        }
        while (q.empty())
        {
            /* code */
        }
        
        if(present->leftChild != NULL) q.push(present->leftChild);
        if(present->rightChild != NULL) q.push(present->rightChild);
        
    }
    


}

int main(){
    int n;
    cin>>n;
    int k;
    cin>>k;

    treeNode *root = NULL;
    int a;
    cin>>a;
    root = new treeNode(a);
    queue<treeNode *>q;
    q.push(root);
    while(!q.empty()){
        treeNode *presentNode = q.front();
        q.pop();
        int x,y;
        cin>>x>>y;
        treeNode *n1 = NULL;
        treeNode *n2 = NULL;
        if(x!=-1)   n1 = new treeNode(x);
        if(y!=-1)   n2 = new treeNode(y);

        presentNode->leftChild = n1;
        presentNode->rightChild = n2;

        if(n1 != NULL)  q.push(n1);
        if(n2 != NULL)  q.push(n2);
    }

    // findKthNodeInorder(root,k);


}