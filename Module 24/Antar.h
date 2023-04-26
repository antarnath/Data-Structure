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
    Node <S> *Mid;
    int Size = 0;
public:
    Stack(){
        head = NULL;
        top = NULL;
        Mid = NULL;
    }

    void push(S value){
        Node <S> *newNode = new Node <S>(value);
        if(head == NULL){
            head = top = Mid = newNode;
            Size++;
            return;
        }

        top->next = newNode;
        newNode->prev = top;
        top = newNode;
        if(Size%2==1){
            Mid = Mid->next;
        }
        Size++;
    }

    S pop(){
        Node <S> *delNode = top;
        S chk;
        if(head == NULL){
            cout<<"Stack Underflow"<<endl;
            return chk;
        }

        if(top == head){
            head = top = Mid = NULL;
        }
        else{
            top = delNode->prev;
            top->next = NULL;
            if(Size%2==0){
                Mid = Mid->prev;
            }
        }
        chk = delNode->value;
        delete delNode;
        Size--;
        return chk;
    }

    S mid(){
        return Mid->value;
    }

    bool empty(){
        if(head == NULL)    return true;
        else return false;
    }

    int size(){
        return Size;
    }

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