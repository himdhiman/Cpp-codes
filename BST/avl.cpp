#include<bits/stdc++.h>
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

void AddElement(int data, node *& root){
    if(root == NULL){
        root = new node(data);
        return;
    }
    node * it = root;
    node * prev = NULL;
    while(it){
        if(data > it->data){
            prev = it;
            it = it->right;
        } else{
            prev = it;
            it = it->left;
        }

        if(prev->data < data){
            prev->right = new node(data);
        }else{
            prev->left = new node(data);
        }
    }
    return;
}

void Print_Level_order(node * root){
    queue<node *> q;
    q.push(root);
    while(!q.empty()){
        node * curr = q.front();
        cout<<curr<<" ";
        q.pop();
        if(curr->left){
            q.push(curr->left);
        }
        if(curr->right){
            q.push(curr->right);
        }
    }
}


int main(){

    node * root = NULL;
    AddElement(40, root);AddElement(23, root);AddElement(58, root);AddElement(19, root);AddElement(32, root);
    AddElement(64, root);AddElement(73, root);
    Print_Level_order(root);
    return 0;
}
