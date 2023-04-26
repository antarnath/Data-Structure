#include<bits/stdc++.h>
using namespace std;

template<typename N> class Node{
public:
    N value;
    Node *next;
    Node *prev;

    Node(N value){
        this->value = value;
        this->next = NULL;
        this->prev = NULL;
    }
};

template <typename S> class Stack{

    Node <S> *head;
    Node <S> *top;
    int count = 0;

public:
    Stack(){
        head = NULL;
        top = NULL;
    }
    //PUSH
    void push(S value){

        Node <S> *newNode = new Node <S>(value);

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
    S pop(){

        Node <S> *delNode = top;
        S chk;
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
    S Top(){
        S chk;
        if(top == NULL){
            cout<<"Stack Underflow | There is no Element in Top"<<endl;
        }
        else{
            return top->value;
        }

        return chk;
    }
};