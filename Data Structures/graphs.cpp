#include<bits/stdc++.h>
using namespace std;

class graph{
private:
    map<int , list<int> > AdjList;

public:

    graph(){
    }

    void AddEdge(int u, int v, bool bidir = true){
        AdjList[u].push_back(v);
        if(bidir){
            AdjList[v].push_back(u);
        }
        return;
    }

    void Print(){
        for(auto obj : AdjList){
            cout<<obj.first<<" --> ";
            for(auto data : obj.second){
                cout<<data<<" ";
            }
            cout<<endl;
        }
        return;
    }

    void BFS(int source){
        map<int, bool> visited;
        queue<int> q;
        visited[source] = true;
        q.push(source);

        while(!q.empty()){
            int curr = q.front();
            cout<<curr<<" ";
            q.pop();
            for(auto data : AdjList[curr]){
                if(visited[data] != true){
                    visited[data] = true;
                    q.push(data);
                }
            }
        }
        return;
    }

    void HelperDFS(int source, map<int, bool> &visited){
        visited[source] = true;
        cout<<source<<" ";
        for(auto data : AdjList[source]){
            if(visited[data] != true){
                HelperDFS(data, visited);
            }
        }
        return;
    }

    void DFS(int source){
        map<int, bool> visited;
        HelperDFS(source, visited);
        return;
    }

};

int main(){
     graph g;

     g.AddEdge(1, 2);g.AddEdge(1, 3);g.AddEdge(2, 4);g.AddEdge(3, 4);g.AddEdge(4, 5);
     g.Print();
     cout<<endl;
     cout<<"BFS : ";
     g.BFS(1);
     cout<<endl;
     cout<<"DFS : ";
     g.DFS(1);
     return 0;
}
