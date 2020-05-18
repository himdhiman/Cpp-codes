#include<bits/stdc++.h>
using namespace std;

template <typename T>
class Graph{
    map<T , list<T> > AdjList;

    void _DFS(T source, map<T, bool> & visited){
        visited[source] = true;
        cout<<source<<" ";
        for(T data : AdjList[source]){
            if(!visited[data]){
                _DFS(data, visited);
            }
        }
        return;
    }

public:
    Graph(){
    }

    void AddEdge(T a, T b, bool bidir = false){
        AdjList[a].push_back(b);
        if(bidir){
            AdjList[b].push_back(a);
        }
        return;
    }

    void Print(){
        for(auto obj : AdjList){
            cout<<obj.first<<" --> ";
            for(T data : obj.second){
                cout<<data<<" ";
            }
            cout<<endl;
        }
    }

    void BFS(T source){
        map<T, bool> visited;
        queue<T> q;
        visited[source] = true;
        q.push(source);
        while(!q.empty()){
            T curr = q.front();
            cout<<curr<<" ";
            q.pop();
            for(T data : AdjList[curr]){
                if(!visited[data]){
                    visited[data] = true;
                    q.push(data);
                }
            }
        }
    }

    void DFS(T source){
        map<T, bool> visited;
        _DFS(source, visited);
        return;
    }

    void SingleSourceShortestPath(T start, T end){
        map<T, int> dist;
        queue<T> q;

        for(auto obj : AdjList){
            dist[obj.first] = INT_MAX;
        }

        dist[start] = 0;
        q.push(start);

        while(dist[end] == INT_MAX){
            T curr = q.front();
            q.pop();
            for(T data : AdjList[curr]){
                if(dist[data] == INT_MAX){
                    dist[data] = dist[curr] + 1;
                    q.push(data);
                }
            }
        }
        cout<<dist[end]<<endl;
        
    }

};

int main(){
    Graph<int> G;
    G.AddEdge(1, 2); G.AddEdge(2, 3); G.AddEdge(3, 4); G.AddEdge(4, 5);
    G.AddEdge(4, 7); G.AddEdge(5, 6); G.AddEdge(3, 6); G.AddEdge(7, 2);
    G.Print();
    cout<<"BFS : "; G.BFS(1); cout<<endl;
    cout<<"DFS : "; G.DFS(1); cout<<endl;
    G.SingleSourceShortestPath(1, 5);
}