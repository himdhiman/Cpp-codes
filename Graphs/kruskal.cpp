#include<iostream>
#include<algorithm>
using namespace std;

class Edge{
public:
    int src;
    int dest;
    int weight;
};

class Set{
public:
    int rank;
    int parent;
};

int find(Set * set, int i){
    if(set[i].parent != i){
        set[i].parent = find(set, set[i].parent)
    }
    return parent[i];
}

void Unoin(set * set, int v1, int v2){
    int v1_root = find(set, v1);
    int v2_root = find(set, v2);
    if(set[v1_root].rank < set[v2_root].rank){
        set[v1_root].parent = v2_root;
    } else if(set[v1_root].rank > set[v2_root].rank){
        set[v2_root].parent = v1_root;
    } else{
        set[v2_root].parent = v1_root;
        set[v1_root].rank++;
    }
}

bool cmp(Edge e1, Edge e2){
    return e1.weight < e2.weight;
}

void Kruskals(Edge * input, int v, int e){
    sort(input, input+e, cmp);
    Edge * output = new Edge[v-1];
    Set * set = new Set[v];
    for(int j = 0; j < v; j++){
        set[j].rank = 0;
        set[j].parent = j;
    }
    int counter = 0, j = 0;
    while(counter < v - 1){
        Edge currentEdge = input[j];
        int sourceParent = find(set, currentEdge.src);
        int destParent = find(set, currentEdge.dest);
        if(sourceParent != destParent)
    }
}



int main(){
    int v, e;
    cin>>v>>e;
    Edge * input = new Edge[e];
    for(int i = 0; i < e; i++){
        int s, d, w;
        cin >>s>>d>>w;
        input[i].src = s;
        input[i].dest = d;
        input[i].weight = w;
    }
    return 0;
}
