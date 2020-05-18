#include<bits/stdc++.h>
using namespace std;

template <typename T>
class Graph{
    map<T, list<pair<T, int> > > AdjList;

public:

    void AddEdge(T a, T b, int w, bool bidir = true){
        AdjList[a].push_back(make_pair(b, w));
        if(bidir){
            AdjList[b].push_back(make_pair(a, w));
        }
        return;
    }

    void Dijkstra(T source, T end){
        map<T, bool > visited;
        map<T, int> dist;
        for(auto obj : AdjList){
            dist[obj.first] = INT_MAX;
        }
        dist[source] = 0;
        visited[source] = true;
        set<int, T> s;
        s.insert(make_pair(0,source));
        while(!s.empty()){
            auto p = *s.begin()
            int dis = p.first;
            T node = p.second;
            s.erase(s.begin());

            for(auto nodes : AdjList[node]){
                if(!visited[nodes.first]){
                    
                }
            }
        }
        
    }

    void Print(){
        for(auto obj : AdjList){
            cout<<obj.first<<" --> ";
            for(auto node : obj.second){
                cout<<node.first<<","<<node.second<<"   ";
            }
            cout<<endl;
        }
    }
};

int main(){
    Graph<int> G;
    G.AddEdge(1, 2, 1);
    G.AddEdge(1, 3, 3);
    G.AddEdge(1, 4, 8);
    G.AddEdge(1, 5, 10);
    G.AddEdge(2, 3, 1);
    G.AddEdge(3, 4, 1);
    G.AddEdge(4, 5, 6);
    G.Print();
}