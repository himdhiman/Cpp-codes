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

node * builtBST(int arr[], int start, int end){
    if(start > end){
        return NULL;
    }
    int mid = (start + end)/2;
    node * root = new node(arr[mid]);
    root->left = builtBST(arr, start, mid - 1);
    root->right = builtBST(arr, mid + 1, end);
    return root;

}

int PrintSUM(node * root, int s){
    if(root == NULL){
        return 0;
    }
    s = s + root->data;
    int left = PrintSUM(root->left, s);
    int right = PrintSUM(root->right, s);
    return left + right + root->data;
}

int main(){
//    int t;
//    cin>>t;
//    for(int j = 0; j < t; j++){
        int arr[1000];
        int n;
        cin>>n;
        for(int i = 0; i < n; i++){
            cin>>arr[i];
        }
        node * root = builtBST(arr, 0, n-1);
        cout<<PrintSUM(root, 0);
//    }
}
