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

node * createTree(){
    int data, child;
    cin>>data;
    node * root = new node(data);
    cin>>child;
    if(child == 0){
        return root;
    }
    if(child == 1){
        root->left = createTree();
    }
    if(child == 2){
        root->left = createTree();
        root->right = createTree();
    }
    return root;
}

void print(node * root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    print(root->left);
    print(root->right);
    return;
}

int SumAtK(node * root, int k, int r){
    if(root == NULL){
        return 0;
    }
    int s = 0;
    if(k == r){
        s = s + root->data;
    }
    int l = SumAtK(root->left, k, r+1);
    int ri = SumAtK(root->right, k, r+1);

    return s + l + ri;
}

int main(){
    node * root = createTree();
//    print(root);
    int level;
    cin>>level;
//    cout<<endl;
    cout<<SumAtK(root, level, 0);

    return 0;
}
