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

node * CreateTree(){
    node * root = NULL;
    int data;
    cin>>data;
    if(data != -1){
        root = new node(data);
    }
    queue<node * >q;
    q.push(root);
    while(!q.empty()){
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

void PreOrder(node * root){
    if(!root){
        return;
    }
    PreOrder(root->left);
    cout<<root->data<<" ";
    PreOrder(root->right);
    return;
}

node * GetAddress(node * root, int target){
    if(!root){
        return NULL;
    }
    if(root->left->data == target){
        return root->left;
    }
    if(root->right->data == target){
        return root->right;
    }
    if(root->data == target){
        return root;
    }
    GetAddress(root->left, target);
    GetAddress(root->right, target);
    return NULL;
}

void PrintDownWards(node * root, int k){
    if(!root || k < 0){
        return;
    }
    if(k == 0){
        cout<<root->data<<" ";
    }
    PrintDownWards(root->left, k-1);
    PrintDownWards(root->right, k-1);
    return;
}

int PrintAtDistanceK(node * root, node * target, int k){
    if(!root){
        return -1;
    }
    if(root == target){
        PrintDownWards(root, k);
        return 1;
    }

    // For Left Subtree

    int l = PrintAtDistanceK(root->left, target, k);
    if(l != -1){
        if(l == k){
            cout<<root->data<<" ";
        }
        else{
            PrintDownWards(root->right, k-l-1);
        }
        return l;
    }

    // For right Subtree
    int r = PrintAtDistanceK(root->right, target, k);
    if(r != -1){
        if(r == k){
            cout<<root->data<<" ";
        }
        else{
            PrintDownWards(root->left, k-r-1);
        }
        return r;
    }
    return -1;
}

int main(){

    node * root = CreateTree();
    node * nroot = GetAddress(root, 25);
    PrintAtDistanceK(root, nroot, 2);

    return 0;


}

//14 11 25 8 -1 21 31 -1 -1 16 26 -1 37 -1 -1 -1 -1 -1 -1
