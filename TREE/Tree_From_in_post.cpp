#include<iostream>
#include<vector>
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

int FindIndex(vector<int> v, int element, int start, int end){
    for(int i = start; i <= end; i++){
        if (v[i] == element){
            return i;
        }
    }
    return -1;
}

node * CreateTree(vector<int> in, vector<int> post, int istart, int iend, int pstart, int pend){
    if(pstart > pend){
        return NULL;
    }
    node * root = new node(post[pend]);
    int index = FindIndex(in, post[pend], istart, iend);
    int len = index - istart;
    root->left = CreateTree(in, post, istart, index - 1, pstart, pstart + len - 1);
    root->right = CreateTree(in, post, index + 1, iend, pstart+len, pend - 1);

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

int main(){

    int t, n, var;
    cin>>t;
    while(t--){
        vector<int> in, post;
        int n;
        cin>>n;
        for(int i = 0; i < n; i++){
            cin>>var;
            in.push_back(var);
        }
        for(int i = 0; i < n; i++){
            cin>>var;
            post.push_back(var);
        }
        node * root = CreateTree(in, post, 0, n-1, 0, n-1);
        PreOrder(root);
        cout<<endl;
    }
    return 0;
}
