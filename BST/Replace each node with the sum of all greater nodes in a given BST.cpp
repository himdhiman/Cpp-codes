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
    node * root = NULL;
    int data;
    cin>>data;
    queue<node*> q;
    if(data != -1){
        root = new node(data);
        q.push(root);
    }
    while(data != -1){
        node * curr = q.front();
        q.pop();
        if(data != -1){
            cin>>data;
            if(data != -1){
                node * left = new node(data);
                curr->left = left;
                q.push(left);
            }
        }
        if(data != -1){
            cin>>data;
            if(data != -1){
                node * right = new node(data);
                curr->right = right;
                q.push(right);
            }
        }
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

int FindSum(node * root, int n){
    if(root == NULL){
        return 0;
    }
    int s = 0;
    if(root->data > n){
        s = s + root->data;
    }
    int s1 = FindSum(root->left, n);
    int s2 = FindSum(root->right, n);
    return s+s1+s2;
}

void ReplaceWithMax(node * root1, node * root2){
    if(root1 == NULL){
        return;
    }
    cout<<FindSum(root2, root1->data)<<" ";
    ReplaceWithMax(root1->left, root2);
    ReplaceWithMax(root1->right, root2);
    return;
}
void LevelOrder(node * root){
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node * curr = q.front();
        if(curr == NULL){
            q.pop();
            cout<<endl;
        }
        else{
            if(curr->left != NULL){
                node * left = curr->left;
                q.push(left);

            }
            if(curr->right != NULL){
                node * right = curr->right;
                q.push(right);
            }
            cout<<FindSum(root, curr->data)<<" ";
            q.pop();
            q.push(NULL);
        }
    }
}


int main(){

    node * root = createTree();
    LevelOrder(root);
    return 0;

}
