#include<bits/stdc++.h>
using namespace std;

class graph{
private:
    map<long long int, list<long long int> > m;
public:

    graph(){

    }

    void AddEdge(long long int u, long long int v){
        m[u].push_back(v);
        m[v].push_back(u);
        return;
    }


    long long int BFS(long long int start, long long int stop, long long int * arr){
        map<long long int , bool> visited;
        map<long long int, long long int> dist;
        queue<long long int> q;
        q.push(start);
        visited[start] = true;
        dist[start] = arr[start - 1];

        while(visited[stop] != true){
            long long int curr = q.front();
            q.pop();
            for(long long int x: m[curr]){
                if(visited[x] == false){
                    q.push(x);
                    visited[x] = true;
                    dist[x] = dist[curr]*arr[x-1];
                }
            }
        }
        return dist[stop];
    }

};

long long int count_divisor(long long int n){
    long long int cnt = 0;
    long long int i = 1;
    while(i <= sqrt(n)){
        if(n % i == 0){
            if(n/i == i){
                cnt++;
            }
            else{
                cnt = cnt + 2;
            }
        }
        i++;
    }
    return cnt;
}

int main(){
    long long int n, q, u, v, t;
    cin>>t;
    for(long long int y = 0; y < t; y++){
        cin>>n;
        long long int * arr = new long long int[n];
        graph g;
        for(long long int i = 0; i < n-1; i++){
            cin>>u>>v;
            g.AddEdge(u, v);
        }
        for(long long int i = 0; i < n; i++){
            cin>>arr[i];
        }
        cin>>q;
        for(long long int i = 0; i < q; i++){
            cin>>u>>v;
            cout<<count_divisor(g.BFS(u, v, arr)) % 1000000007<<endl;
        }
    }
    return 0;
}
