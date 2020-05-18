#include<iostream>
#include<algorithm>
using namespace std;

class Edge{
public:
    int v1;
    int v2;
    int weight;
};

bool cmp(Edge e1, Edge e2){
    return e1.weight < e2.weight;
}

int Find(map<int, int > * set, int val){
    if(set[i] != i){
        return set[i] = Find(set, set[i]);
    }
    return set[i];
}

void Union(map<int, int> * set, Edge current){

    int v1_sp = Find(set, current.v1);
    int v2_sp = Find(set, current.v2);

    set[]

}

void Kruskal(Edge * e, int edges, int vertices){
    sort(e, e + edges, cmp);
    Edge * output = new Edge[vertices - 1];
    map<int, int> * set = new map<int, int>;
    for(int i = 0; i < n; i++){
        set[i+1] = i+1;
    }
    int counter = 0; i = 0;
    while(counter < n-1){
        Edge current = e[i];
        v1_sup_parent = Find();
        v2_sup_parent = Find();
        if(v1_sup_parent != v2_sup_parent){
            output[counter] = current;
            Union(set, current);
            counter++;
        }
        i++;
    }
}

int main(){

    int vertices = 7, edges = 8;
    Edge * e = new Edge[edges];
    e[0].v1 = 1; e[0].v2 = 2 ; e[0].weight = 1;
    e[1].v1 = 2; e[1].v2 = 3 ; e[1].weight = 3;
    e[2].v1 = 3; e[2].v2 = 4 ; e[2].weight = 2;
    e[3].v1 = 4; e[3].v2 = 1 ; e[3].weight = 3;
    e[4].v1 = 2; e[4].v2 = 5 ; e[4].weight = 2;
    e[5].v1 = 5; e[5].v2 = 6 ; e[5].weight = 6;
    e[6].v1 = 6; e[6].v2 = 7 ; e[6].weight = 4;
    e[7].v1 = 7; e[7].v2 = 5 ; e[7].weight = 1;
}
