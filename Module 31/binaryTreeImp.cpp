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

void printTree(treeNode *root,int level);
void spacePrint(int level);
void inorder(treeNode *root,string &chk);
void preorder(treeNode *root,string &chk);
void postorder(treeNode *root,string &chk);
int levelOrderPrint(treeNode *root,string &chk,int k);

int main(){

    int n;
    cin>>n;
    treeNode *allNodes[n];

    for(int i=0; i<n; i++){
        allNodes[i] = new treeNode(-1);
    }

    for(int i=0; i<n; i++){
        int value,left,right;
        cin>>value>>left>>right;
        allNodes[i]->data = value;
        if(left>n-1 || right>n-1){
            cout<<"Invalid Index"<<endl;
            break;
        }
        if(left != -1){
            allNodes[i]->leftChild = allNodes[left];
        }
        if(right != -1){
            allNodes[i]->rightChild = allNodes[right];
        }
    }

     printTree(allNodes[0], 0);

    string inorderTraversal = "";
    string preorderTraversal = "";
    string postorderTraversal = "";
    string levelOrderTraversal = "";
    

    // inorder(allNodes[0],inorderTraversal);
    // cout<<"Inorder : "<< inorderTraversal<<endl; 

    // preorder(allNodes[0],preorderTraversal);
    // cout<<"Preorder : "<<preorderTraversal<<endl;

    // postorder(allNodes[0],postorderTraversal);
    // cout<<"Postorder : "<<postorderTraversal<<endl;

    int maxValue = levelOrderPrint(allNodes[0],levelOrderTraversal,0);
    cout<<"level Order Traversal : "<<levelOrderTraversal<<endl;
    cout<<"maxValue of Level : "<<maxValue<<endl;

    return 0;

}

void spacePrint(int level){
    for(int i=0;i<level;i++){
        cout<<"   ";
    }
}
void printTree(treeNode *root,int level){
    if(root == NULL){
        return;
    }
    if(root->leftChild == NULL && root->rightChild == NULL){
        cout<<root->data<<endl;
        return;
    }
    else{
        cout<<endl;
        spacePrint(level);
        cout<<"Root: "<<root->data<<endl;
    }

    if(root->leftChild != NULL){
        spacePrint(level);
        cout<<"Left: ";
        printTree(root->leftChild,level+1);
    }

    if(root->rightChild != NULL){
        spacePrint(level);
        cout<<"Right: ";
        printTree(root->rightChild,level+1);
    }
}
void inorder(treeNode *root,string &chk){
    if(root == NULL){
        return;
    }

    inorder(root->leftChild,chk);
    chk += to_string(root->data);
    chk += " ";
    inorder(root->rightChild,chk);
}
void preorder(treeNode *root,string &chk){
    if(root == NULL){
        return;
    }
    chk += to_string(root->data);
    chk += " ";
    preorder(root->leftChild,chk);
    preorder(root->rightChild,chk);
}
void postorder(treeNode *root,string &chk){
    if(root == NULL){
        return;
    }
    
    postorder(root->leftChild,chk);
    postorder(root->rightChild,chk);
    chk += to_string(root->data);
    chk += " ";
}
int levelOrderPrint(treeNode *root,string &chk,int k){
    if(root == NULL)    return -1;

    queue<treeNode*>q;
    q.push(root);
    q.push(NULL);
    int level = 0;
    int maxValue = INT_MIN;

    while (!q.empty())
    {
        treeNode *present = q.front();
        q.pop();
        if(present != NULL){
            if(level == k){
                if(present->data > maxValue){
                    maxValue = present->data;
                }
            }
            chk += to_string(present->data);
            chk += " ";
            if(present->leftChild != NULL)  q.push(present->leftChild);
            if(present->rightChild != NULL) q.push(present->rightChild);
        }
        else{
            if(!q.empty()){
                q.push(NULL);
                level++;
            }
        }
    }

    return maxValue;
    
}




/* 
14
0 1 2
1 3 4
2 5 6
3 7 8
4 -1 9
5 10 -1
6 11 12
7 -1 -1
8 -1 -1
9 -1 -1
10 -1 13
11 -1 -1
12 -1 -1
13 -1 -1

 */