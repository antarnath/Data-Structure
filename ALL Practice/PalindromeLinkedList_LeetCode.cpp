#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int value;
    Node *Next;

    Node(int value){
        this->value = value;
        this->Next = NULL;
    }
};

void insertAtTail(Node *&head, int value)
{
    Node *newNode = new Node(value);

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node *temp = head;
    while (temp->Next != NULL)
    {
        temp = temp->Next;
    }

    temp->Next = newNode;
}

void displayLinkedList(Node *&head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->value;

        if (temp->Next != NULL)
        {
            cout << " -> ";
        }

        temp = temp->Next;
    }
}

bool checkPalindromeLinkedList(Node *&head){
    stack<int>st;
    Node *temp = head;

    while(temp != NULL){
        st.push(temp->value);
        temp = temp->Next;
    }

    temp = head;

    while(temp != NULL){
        if(st.top()==temp->value){
            st.pop();
            temp = temp->Next;
        }
        else{
            return false;
        }
    }
    return true;
}
int main(){
    Node *head = NULL;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int value;
        cin>>value;
        insertAtTail(head,value);
    }

    // displayLinkedList(head);

    if(checkPalindromeLinkedList(head)){
        cout<<"This Linked List is Palindrome"<<endl;
    }
    else{
        cout<<"This Linked List is not Palindrome"<<endl;
    }

    return 0;
}