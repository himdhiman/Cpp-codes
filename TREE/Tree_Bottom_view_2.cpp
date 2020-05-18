#include<iostream>
#include<queue>
#include<map>
#include<list>
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
    queue<node*> q;
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
    cout<<root->data<<" ";
    PreOrder(root->left);
    PreOrder(root->right);
    return;
}

void BottomView(node * root, int k, map<int, list<int> > & m){
    if(!root){
        return;
    }
    BottomView(root->left, k-1, m);
    m[k].push_back(root->data);
    BottomView(root->right, k+1, m);
    return;
}



int main(){

    node * root = CreateTree();
    PreOrder(root);
    cout<<endl;
    map<int, list<int> >m;
    BottomView(root, 0, m);
    for(auto i : m){
        int size = i.second.size() - 1;
        int var = 0;
        for(auto it = i.second.begin(); it != i.second.end(); it++){
            if(var == size){
                cout<<*(it)<<" ";
            }
            var++;
        }
    }
    return 0;

}

// 1 2 3 4 5 6 -1 -1 -1 -1 -1 -1 -1
// 1 2 3 4 5 6 7 8 -1 -1 -1 -1 -1 -1 -1 -1 -1
// 20 8 22 5 3 4 25 -1 -1 10 14 -1 -1 -1 -1 -1 -1 -1 -1