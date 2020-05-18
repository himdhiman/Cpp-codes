#include<iostream>
using namespace std;

struct node{
    int data;
    node * left;
    node * right;

    node(int data){
        this->data = data;
        left = right = NULL;
    }
};

node * createTree(int n){
    int data;
    int i = 0;
    cin>>data;
    node * root = new node(i);
    node * curr = root
    i++;
    while(i < n){
        cin>>data;
        if()
    }

}
