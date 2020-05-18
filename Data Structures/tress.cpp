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

void addElement(node * &root, int data){

    if(root == NULL){
        root = new node(data);
        return;
    }
    node * it = root;
    node * prev = NULL;
    while(it != NULL){
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

void Preorder(node * root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    Preorder(root->left);
    Preorder(root->right);
    return;
}

void Inorder(node * root){
    if(root == NULL){
        return;
    }
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
    return;
}

void Postorder(node * root){
    if(root == NULL){
        return;
    }
    Postorder(root->left);
    Postorder(root->right);
     cout<<root->data<<" ";
    return;
}

node * deleteElement(node * root,int data){
    if(!root){
        return NULL;
    }
    if(root->data == data){
        // no child
        if(!root->left && !root->right){
            delete root;
            return NULL;
        }
        // 1 child
        if((!root->left && root->right) || (root->left && !root->right)){
            node * temp;
            if(root->left){
                temp = root->left;
            }else{
                temp = root->right;
            }
            delete root;
            return temp;
        }
        // 2 child
        node * parent = root;
        node * it = root->left;
        while(it->right){
            parent = it;
            it = it->right;
        }
        if(parent!=root){
            parent->right = it->left;
            it->left = root->left;
        }
        it->right = root->right;
        delete root;
        return it;
    }

    if(root->data > data){
        root->left = deleteElement(root->left,data);
    }else{
        root->right = deleteElement(root->right,data);
    }
    return root;
}

int main(){
    node * root = NULL;
    addElement(root,8);addElement(root,3);addElement(root,10);
    addElement(root,1);addElement(root,6);addElement(root,14);
    addElement(root,4);addElement(root,7);addElement(root,13);

    Preorder(root);
    cout<<endl;
    Inorder(root);
    cout<<endl;
    Postorder(root);

    deleteElement(root, 13);

    cout<<endl;

    Inorder(root);
    return 0;

}


