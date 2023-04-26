#include <bits/stdc++.h>
using namespace std;

class treeNode
{
public:
    int data;
    treeNode *leftChild;
    treeNode *rightChild;

    treeNode(int value)
    {
        data = value;
        leftChild = NULL;
        rightChild = NULL;
    }
};

void spacePrint(int level)
{
    for (int i = 0; i < level; i++)
    {
        cout << "   ";
    }
}
int searchInposition(int inOrder[], int current, int start, int end)
{
    for (int i = start; i <= end; i++)
    {
        if (inOrder[i] == current)
        {
            return i;
        }
    }
    return -1;
}
void printTree(treeNode *root, int level)
{
    if (root == NULL)
    {
        return;
    }
    if (root->leftChild == NULL && root->rightChild == NULL)
    {
        cout << root->data << endl;
        return;
    }
    else
    {
        cout << endl;
        spacePrint(level);
        cout << "Root: " << root->data << endl;
    }

    if (root->leftChild != NULL)
    {
        spacePrint(level);
        cout << "Left: ";
        printTree(root->leftChild, level + 1);
    }

    if (root->rightChild != NULL)
    {
        spacePrint(level);
        cout << "Right: ";
        printTree(root->rightChild, level + 1);
    }
}
treeNode *buildTreePreIn(int preOrder[], int inOrder[], int start, int end)
{
    static int id = 0;

    int current = preOrder[id];
    id++;
    treeNode *newNode = new treeNode(current);
    if (start == end)
    {
        return newNode;
    }
    int pos = searchInposition(inOrder, current, start, end);

    newNode->leftChild = buildTreePreIn(preOrder, inOrder, start, pos - 1);

    newNode->rightChild = buildTreePreIn(preOrder, inOrder, pos + 1, end);
}
int height(treeNode *root)
{
    if (root == NULL)
        return 0;
    else
    {
        int leftHeight = height(root->leftChild);
        int rightHeight = height(root->rightChild);
        return max(leftHeight, rightHeight) + 1;
    }
}
void printCurrentLevel(treeNode *root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
    {
        cout << root->data << " ";
    }
    if (level > 1)
    {
        printCurrentLevel(root->leftChild, level - 1);
        printCurrentLevel(root->rightChild, level - 1);
    }
}

void level_Order(treeNode *root){
    if(root==NULL){
        return;
    }
    queue<treeNode*>q;
    q.push(root);
    while (!q.empty())
    {
        treeNode *node = q.front();
        q.pop();
 
        cout<<node->data<<" ";
 
        if(node->leftChild != NULL){
            q.push(node->leftChild);
        }
        if(node->rightChild != NULL){
            q.push(node->rightChild);
        }
    }
   
}


void level_Order_reverse(treeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<treeNode *> q;
    stack<treeNode *> st;
    q.push(root);
    while (!q.empty())
    {
        treeNode *node = q.front();
        q.pop();

        st.push(node);

        if (node->leftChild != NULL)
        {
            q.push(node->leftChild);
        }
        if (node->rightChild != NULL)
        {
            q.push(node->rightChild);
        }
    }
    cout << endl;
    while (!st.empty())
    {
        treeNode *antar = st.top();
        cout << antar->data << " ";
        st.pop();
    }
}

bool isCheck(treeNode *root1, treeNode *root2)
{
    if (root1 == NULL && root2 == NULL)
        return true;
    if (root1 != NULL && root2 != NULL && root1->data == root2->data)
    {
        return (isCheck(root1->leftChild, root2->rightChild) && isCheck(root1->rightChild, root2->leftChild));
    }
    return false;
}
bool isSymmetric(treeNode *root)
{
    return isCheck(root, root);
}

void zigzag_Order(treeNode *root){
    stack<treeNode*>currLevel;
    stack<treeNode*>nexLevel;
    cout<<"Antar"<<endl;

    currLevel.push(root);

    bool leftToRight = true;

    while (!currLevel.empty())
    {
        treeNode *temp = currLevel.top();
        currLevel.pop();
        if(temp){
            cout<<temp->data<<" ";

            if(leftToRight){
                if(temp->leftChild){
                    nexLevel.push(temp->leftChild);
                }
                if(temp->rightChild){
                    nexLevel.push(temp->rightChild);
                }
            }
            else{
                if(temp->rightChild){
                    nexLevel.push(temp->rightChild);
                }
                if(temp->leftChild){
                    nexLevel.push(temp->leftChild);
                }
            }
        }

        if(currLevel.empty()){
            leftToRight = !leftToRight;
            swap(currLevel,nexLevel);
        }
    }
    
}


int main()
{

    int n;
    cin >> n;
    int array[n];
    int preOrder[n], inOrder[n];

    for (int i = 0; i < n; i++)
    {
        cin >> preOrder[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> inOrder[i];
    }

    treeNode *root = buildTreePreIn(preOrder, inOrder, 0, n - 1);
    printTree(root, 0);

    // cout << height(root) << endl;

    // level_Order(root);

//     if(isSymmetric(root)){
//         cout<<"This treeNode is Symmetric"<<endl;
//     }
//     else{
//         cout<<"This treeNode is Not Symmetric"<<endl;
//     }

    zigzag_Order(root);
    return 0;
}

/*
9
0 1 3 4 2 5 7 8 6
3 1 4 0 7 5 8 2 6
 */