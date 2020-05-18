#include<iostream>
#include<queue>
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

node * createTree(){
    int data;
    cin>>data;
    queue<node *> q;
    node * root = NULL;
    if(data != -1){
        root = new node(data);
        q.push(root);
    }
    while(q.empty() != true){
        node * curr = q.front();
        q.pop();
        cin>>data;
        if(data != -1){
            curr->left = new node(data);
            q.push(curr->left);
        }
        cin>>data;
        if(data != -1){
            curr->right = new node(data);
            q.push(curr->right);
        }
    }
    return root;
}



void print(node * root){
    if(root == NULL){
        return;
    }
    if(root->left == NULL && root->right == NULL){
        cout<<root->data<<" ";
    }
//    cout<<root->data<<" ";
    print(root->left);
    print(root->right);
    return;
}

int main(){

    node * root = createTree();
    print(root);

    return 0;
}
