#include<bits/stdc++.h>
using namespace std;


template <typename T>
class graph{
private:
    map<T, list<T> > AdjList;
public:
    graph(){
    }
    void AddEdge(T a, T b, bool bidir = true){
        AdjList[a].push_back(b);
        if(bidir){
            AdjList[b].push_back(a);
        }
        return;
    }
    void Print(){
        for(auto obj : AdjList){
            cout<<obj.first<<" -> ";
            for(auto data : obj.second){
                cout<<data<<" ";
            }
            cout<<endl;
        }
        return;
    }
    void BFS(T source){
        map<T, bool> visited;
        queue<T> q;
        visited[source] = true;
        q.push(source);
        while(!q.empty()){
            T curr = q.front();
            q.pop();
            cout<<curr<<" ";
            for(auto i : AdjList[curr]){
                if(visited[i] != true){
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
        return;
    }


    void BFS_Distance(T source){
        map<T, int> dist;
        queue<T> q;

        for(auto i : AdjList){
            dist[i.first] = INT_MAX;
        }

        q.push(source);
        dist[source] = 0;

        while(!q.empty()){
            T curr = q.front();
            q.pop();

            for(T neighbour : AdjList[curr]){
                if(dist[neighbour] == INT_MAX){
                    q.push(neighbour);
                    dist[neighbour] = dist[curr] + 1;
                }
            }
        }
        for(auto i : AdjList){
            cout<<i.first<<" -> "<<dist[i.first]<<endl;
        }
    }

    void Driver_DFS(T source, map<T, bool> &visited){
        visited[source] = true;
        cout<<source<<" ";
        for(auto i : AdjList[source]){
            if(!visited[i]){
                Driver_DFS(i, visited);
            }
        }
        return;
    }


    void DFS(T source){
        map<T, bool> visited;
        Driver_DFS(source, visited);
        return;
    }
};

int main(){
    graph<int> g;
    g.AddEdge(1, 2);g.AddEdge(1, 4);g.AddEdge(2, 3);g.AddEdge(4, 3);g.AddEdge(4, 5);
    g.Print();
    cout<<endl;
    g.BFS(1);
    cout<<endl;
    g.BFS_Distance(1);
    cout<<endl;
    g.DFS(1);
    return 0;
}

