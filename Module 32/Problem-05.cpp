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


treeNode *invert_tree(treeNode *root){
    if(root==NULL){
        return root;
    }

    treeNode *left =  invert_tree(root->leftChild);
    treeNode *right = invert_tree(root->rightChild);

    root->rightChild =left;
    root->leftChild = right;

    return root;
}
int tilt = 0;
int findTilt(treeNode* root) {
    
    if(root == NULL)
        return 0;
    int left = findTilt(root->leftChild);
    int right = findTilt(root->rightChild);

    tilt  += abs(left-right);
    return (left + right + root->data);
}
void average_level(treeNode *root){
    if(root == NULL)    return;
    queue<treeNode*>q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {   
        int count = 0;
        int sum = 0;
        if(q.front()==NULL){
            break;
        }
        while(q.front()!=NULL){
            count++;
            treeNode *temp = q.front();
            sum += temp->data;
            q.pop();
            if(temp->leftChild != NULL){
                q.push(temp->leftChild);
            }
            if(temp->rightChild != NULL){
                q.push(temp->rightChild);
            }

        }
        float avg = (float) sum / count;
        cout<<avg<<" ";
        q.pop();
        q.push(NULL);
    }
    
}

bool is_unival(treeNode* root){
    if(root == NULL)    return true;
    
    if(root->leftChild!=NULL){
        if(root->data != root->leftChild->data){
            return false;
        }
    }

    if(root->rightChild != NULL){
        if(root->data != root->rightChild->data){
            return false;
        }
    }

    return is_unival(root->leftChild) && is_unival(root->rightChild);

}

vector<int> ans;
void inorderTraversal(treeNode* root)
{
    if (root != NULL) {
        inorderTraversal(root->leftChild);
        ans.push_back(root->data);
        inorderTraversal(root->rightChild);
    }
}
int second_minimum(treeNode* root)
{
    inorderTraversal(root);
    sort(ans.begin(), ans.end());

    for (int i = 0; i < ans.size() - 1; i++){
        if (ans[i] != ans[i + 1]){
            return ans[i + 1];
        }
    }
    return -1;
}

int main(){
    treeNode * root = new treeNode(2);
    root->leftChild = new treeNode(2);
    root->rightChild = new treeNode(2);

    // treeNode *root = new treeNode(3);
    // root->leftChild = new treeNode(9);
    // root->rightChild = new treeNode(20);
    // root->rightChild->leftChild = new treeNode(15);
    // root->rightChild->rightChild = new treeNode(7);

    

    // treeNode *ans = invert_tree(root);
    printTree(root,0);
    // findTilt(root);
    // cout<<tilt<<endl;

    // average_level(root);

    // if(is_unival(root)){
    //     cout<<"This binary tree is Uni-Valued"<<endl;
    // }
    // else{
    //     cout<<"This binary tree is not Uni-Valued"<<endl;
    // }
    int secondMinimumValue = second_minimum(root);
    cout<<secondMinimumValue<<endl;

}
/* 
11
4 2 8 5 9 1 10 6 11 3 7
1 2 4 5 8 9 3 6 10 11 7
 */