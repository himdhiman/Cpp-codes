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

int FindIndex(vector<int> v, int element, int start, int stop){
    for(int i = start, i <= stop; i++){
        if(v[i] == element){
            return i;
        }
    }
    return -1;
}

node * TreeFromPreIn(vector<int> pre, vector<int> in, int pstart, int pend, int istart, int iend){
    if(pstart > pend){
        return NULL;
    }
    node * root = new node(pre[pstart]);
    int Index = FindIndex(in, pre[pstart], istart, iend);
    int len = Index - istart;

}



int main(){

    vector<int>inorder{8, 11, 14, 16, 21, 26, 25, 31, 37};
    vector<int>postorder{14, 11, 8, 25, 21, 16, 26, 31, 37};

    return 0;


}

//14 11 25 8 -1 21 31 -1 -1 16 26 -1 37 -1 -1 -1 -1 -1 -1
