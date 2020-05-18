#include<bits/stdc++.h>
using namespace std;

class node{

public:
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
    queue<node *> q;
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

void VerticalPrint(node * root, map<int, list<int> > & m, int val){
    if(!root){
        return;
    }
    m[val].push_back(root->data);
    VerticalPrint(root->left, m, val - 1);
    VerticalPrint(root->right, m, val + 1);

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

int main(){
    node * root = CreateTree();
    PreOrder(root);

    cout<<endl;

    map<int , list<int> > m;
    VerticalPrint(root, m, 0);

    map<int, list<int> > :: iterator it;

    for(it = m.begin(); it != m.end(); it++){
        cout<<it->first<<" --> ";
        for(int data : it->second){
            cout<<data<<" ";
        }
        cout<<endl;
    }

    return 0;
}

// 1 2 3 4 5 6 -1 -1 -1 -1 -1 -1 -1




