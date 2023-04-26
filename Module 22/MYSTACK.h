#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int value;
    Node *next;
    Node *prev;

    Node(int value){
        this->value = value;
        this->next = NULL;
        this->prev = NULL;
    }
};

class Stack{

    Node *head;
    Node *top;
    int count = 0;

public:
    Stack(){
        head = NULL;
        top = NULL;
    }
    //PUSH
    void push(int value){

        Node* newNode = new Node(value);

        if(head == NULL){
            head = top = newNode;
            count++;
            return;
        }

        top->next = newNode;
        newNode->prev = top;
        top = newNode;   
        count++;
    }
    //POP
    int pop(){

        Node *delNode = top;
        int chk=-1;
        if(head==NULL){
            cout<<"Stack Underflow"<<endl;
            return chk;
        }

        if(top == head){   //There is only 1 element  
            head = top = NULL;
        }
        else{    //There is More than 1 element
            top = delNode->prev;
            top->next = NULL;
        }
        chk = delNode->value;
        delete delNode;
        count--;
        return chk;

    }
    //EMPTY
    bool empty(){
        if(head==NULL)  return true;
        else    return false;
    }
    //SIZE
    int size(){
        return count;
    }
    //TOP
    int Top(){
        if(top == NULL){
            cout<<"Stack Underflow | There is no Element in Top"<<endl;
            return -1;
        }
        else{
            return top->value;
        }
    }
};