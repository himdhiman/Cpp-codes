#include<iostream>
using namespace std;


template <typename T>
struct node{
    T data;
    node * next;

    node(T data){
        this->data = data;
        next = NULL;
    }
};

template <typename Y>
struct Stack{
    node<Y> * head;
    int cnt;

    Stack(){
        head = NULL;
        cnt = 0;
    }

    void Push(Y data){
        node * temp = new node(data);
        cnt++;
        temp->next = head;
        head = temp;
        return;
    }

    Y Top(){
        return head->data;
    }

    int Size(){
        return cnt;
    }

    bool isEmpty(){
        if(cnt == 0){
            return true;
        }
        return false;
    }

};

int main(){
    Stack s;
    s.Push(1);s.Push(1);s.Push(2);s.Push(3);s.Push(4);s.Push(5);
    cout<<s.Top()<<endl;
    cout<<s.Size()<<endl;
    cout<<s.isEmpty()<<endl;
}
