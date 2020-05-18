#include<bits/stdc++.h>
using namespace std;

class Edge{
private:
    vector<int> v;
    bool isCycle;
public:
    Edge(int n){
        v.resize(n+1);
        for(int i = 1; i <= n; i++){
            v[i] = i;
        }
        isCycle = false;
    }

    int find(int i){
        if(v[i] != i){
            return v[i] = find(v[i]);
        }
        return v[i];
    }

    void Union(int v1, int v2){
        int v1_sp = find(v1);
        int v2_sp = find(v2);
        if(v1_sp != v2_sp){
            v[v2_sp] = v1_sp;
        }
        else{
            isCycle = true;
        }
        return;
    }

    bool cycle(){
        return isCycle;
    }

};


int main(){

    Edge E(3);
    E.Union(1, 2);E.Union(2, 3);E.Union(1, 3);

    E.cycle() ? cout<<"YES" : cout<<"NO";
    return 0;
}
