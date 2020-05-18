#include <bits/stdc++.h>
using namespace std;

void My_Function(int n, int m, int k){
    int b = n;
    for(int i = 0; i < b; i++){
        int v = k;
        for(int m = 0; m < v; m++){
            int j;
            cin>>j;
            mymap[j]++;
        }
        int max_count = 0;
        int res = -1;
        for(auto obj : mymap){
            if(max_count < obj.second){
                res = obj.first;
                max_count = obj.second;
            }
        }
        mymap.clear;
        cost.push_back(res);
    }
    for(int i = 0; i < cost.size(); i++){
        cout<<cost[i]<<" ";
    }
    cost.clear();
    cout<<endl;
}

int main() {
    int t;
    cin>>t;
    unordered_map<int,int> mymap;
    vector<long long int> cost;
    for(int q = 0; q < t; q++){
        int n,m,k;
        cin>>n>>m>>k;
        My_Function(n, m, k);
    }
}
