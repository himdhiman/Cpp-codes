#include<iostream>
#include<queue>
#include<map>
#include<list>
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

node * CreateTrre(){
    node * root = NULL;
    int data;
    cin>>data;
    if(data != -1){
        root = new node(data);
    }
    queue<node *>q;
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

void PrintPreorder(node * root){
    if(root == NULL){
        return;
    }
    PrintPreorder(root->left);
    cout<<root->data<<" ";
    PrintPreorder(root->right);
    return;
}

void TopView(node * root, map<int, list<int> > & m, int val){
    if(!root){
        return;
    }
    m[val].push_back(root->data);
    TopView(root->left, m, val - 1);
    TopView(root->right, m, val + 1);
    return;
}



int main(){

    node * root = CreateTrre();
    PrintPreorder(root);
    cout<<endl;
    map<int, list<int> > m;
    TopView(root, m, 0);
    map<int, list<int> > :: iterator it;
    for(it = m.begin(); it != m.end(); it++){
        int i = 0;
        it->second.reverse();
        for(int data : it->second){
            cout<<data<<" ";
            i++;
            if(i == 1){
                break;
            }
        }
    }
    return 0;

}

