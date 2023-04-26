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
int searchInposition(int inOrder[],int current,int start,int end);
treeNode* buildTreePreIn(int preOrder[],int inOrder[],int start,int end);
void printLeaves(treeNode *root);
void printRightNonLeaves(treeNode *root);
void printLeftNonLeaves(treeNode *root);
void boundaryTraversal(treeNode *root);

treeNode* insertionBST(treeNode* root, int value){
    treeNode* newNode = new treeNode(value);
    if(root==NULL){
        root = newNode;
        return root;
    }
    // value < root->data;
    if(value < root->data){
        root->leftChild = insertionBST(root->leftChild,value);
    }
    // value > root->data 
    else if(value > root->data){
        root->rightChild = insertionBST(root->rightChild,value);
    }
    return root;
}

treeNode* searchBST(treeNode* root,int value){
    if(root==NULL)return root;
    
    if(root->data == value){
        cout<<root->data;
        return root;
    }

    if(root->data > value){
        cout<<root->data<<" ";
        return searchBST(root->leftChild,value);
    }
    if(root->data < value){
        cout<<root->data<<" ";
        return searchBST(root->rightChild,value);
    }
}

treeNode* inordersucc(treeNode* root){
    treeNode* curr = root;
    while(curr->leftChild != NULL){
        curr = curr->leftChild;
    }
    return curr;
}

treeNode* deletionBST(treeNode* root, int value){
    if(root==NULL)return  root;
    if(root->data > value){
        root->leftChild = deletionBST(root->leftChild,value);
    }
    else if(root->data < value){
        root->rightChild = deletionBST(root->rightChild,value);
    }
    else{
        if(root->leftChild==NULL){
            treeNode* temp = root->rightChild;
            free(root);
            return temp;
        }
        else if(root->rightChild==NULL){
            treeNode* temp = root->leftChild;
            free(root);
            return temp;
        }
        else{
            treeNode* temp = inordersucc(root->rightChild);
            root->data = temp->data;
            root->rightChild = deletionBST(root->rightChild,temp->data);
        }
    }
    return root;
}

int main(){
    treeNode* root = NULL;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int value;
        cin>>value;
        root = insertionBST(root,value);
    }

    string s="";
    inorder(root,s);
    cout<<s<<endl;

    int key;
    cin>>key;

    // if(!searchBST(root,key)){
    //     cout<<endl;
    //     cout<<"Value does not exits in the BST"<<endl;
    // }
    // else{
    //     cout<<endl;
    //     cout<<"Value exits in the BST"<<endl;
    // }

    root = deletionBST(root,key);
    s = "";
    inorder(root,s);
    cout<<s<<endl;

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
int searchInposition(int inOrder[],int current,int start,int end){
    for(int i=start;i<=end;i++){
        if(inOrder[i]==current){
            return i;
        }
    }
    return -1;
}
treeNode* buildTreePreIn(int preOrder[],int inOrder[],int start,int end){
    static int id = 0;

    int current = preOrder[id];
    id++;
    treeNode *newNode = new treeNode(current);
    if(start == end){
        return newNode;
    }
    int pos = searchInposition(inOrder,current,start,end);

    newNode->leftChild = buildTreePreIn(preOrder,inOrder,start,pos-1);

    newNode->rightChild = buildTreePreIn(preOrder,inOrder,pos+1,end);
}
void printLeaves(treeNode *root){
    if(root == NULL) return;
    if(root->rightChild == NULL && root->leftChild == NULL){
        cout<<root->data<<" ";
        return;
    }
    printLeaves(root->leftChild);
    printLeaves(root->rightChild);
}
void printRightNonLeaves(treeNode *root){
    if(root == NULL) return;

    if(root->rightChild != NULL){
        cout<<root->data<<" ";
        printRightNonLeaves(root->rightChild);
    }
    else if(root->leftChild != NULL){
        cout<<root->data<<" ";
        printRightNonLeaves(root->leftChild);
    }

}
void printLeftNonLeaves(treeNode *root){
    if(root == NULL) return;
    if(root->leftChild != NULL){
        cout<<root->data<<" ";
        printLeftNonLeaves(root->leftChild);
    }
    else if(root->rightChild != NULL){
        cout<<root->data<<" ";
        printLeftNonLeaves(root->rightChild);
    }
}
void boundaryTraversal(treeNode *root){
    if(root==NULL)  return;
    cout<<root->data<<" ";

    //LB Non-Leaves
    printLeftNonLeaves(root->leftChild);
    //LB Leaves
    printLeaves(root->leftChild);
    //RB Leaves
    printLeaves(root->rightChild);
    //RB Non-Leaves
    printRightNonLeaves(root->rightChild);

}
