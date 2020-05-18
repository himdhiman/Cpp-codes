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

void AddElement(node *& root, int data){

    if(!root){
        root = new node(data);
        return;
    }
    node * it = root;
    node * prev = NULL;

    while(it){
        if(it->data > data){
            prev = it;
            it = it->left;
        }
        else{
            prev = it;
            it = it->right;
        }
    }

    if(prev->data > data){
        prev->left = new node(data);
    }
    else{
        prev->right = new node(data);
    }
    return;
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

void print1(node * root, int a, int b){
    if(root == NULL){
        return;
    }
    if(root->data >= a && root->data <= b){
        cout<<root->data<<" ";
    }
    print1(root->left, a, b);
    print1(root->right, a, b);
    return;
}

int main(){

    int t;
    cin>>t;

    for(int j = 0; j < t; j++){

        node * root = NULL;
        int n;
        cin>>n;
        for(int i = 0; i < n; i++){
            int data;
            cin>>data;
            AddElement(root, data);
        }
        int a, b;
        cin>>a;
        cin>>b;
        cout<<"Preorder : ";
        print(root);
//        cout<<endl;
//        cout<<"Preorder : ";
//        print1(root, a, b);
//        cout<<endl;

    }
    return 0;
}
