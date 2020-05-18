#include<bits/stdc++.h>
#define MAX 10000002
using namespace std;

long long int prime[MAX];

void sieve(){
    memset(prime, 0, sizeof(prime));
    prime[0] = prime[1] = 1;
    for (long long int i = 2; i * i < MAX; i++) {
        if (prime[i] == 0) {
            for (long long int j = i * 2; j < MAX; j += i) {
                if (prime[j] == 0)
                    prime[j] = i;
            }
        }
    }
    for (long long int i = 2; i < MAX; i++) {
        if (prime[i] == 0)
            prime[i] = i;
    }
}

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
        map<long long int, map<long long int, long long int> > dist;
        queue<long long int> q;
        q.push(start);
        visited[start] = true;
        long long int temp = arr[start - 1];
        while(temp != 1){
            dist[start][prime[temp]]++;
            temp = temp / prime[temp];
        }
        while(visited[stop] != true){
            long long int curr = q.front();
            q.pop();
            for(long long int x: m[curr]){
                if(visited[x] == false){
                    q.push(x);
                    visited[x] = true;
                    temp = arr[x - 1];
                    for(auto it = dist[curr].begin(); it != dist[curr].end(); it++){
                        dist[x].insert(make_pair(it->first, it->second));
                    }
                    while(temp != 1){
                        if(dist[x].find(prime[temp]) == dist[x].end()){
                            dist[x][prime[temp]] = dist[curr][prime[temp]] + 1;
                        }
                        else{
                            dist[x][prime[temp]]++;
                        }
                        temp = temp / prime[temp];
                    }
                }
            }
        }
        long long int ans = 1;
        for(auto it = dist[stop].begin(); it != dist[stop].end(); it++){
            ans = ans*(it->second + 1);
        }
        return ans;
    }

};



int main(){
    sieve();
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
            cout<<g.BFS(u, v, arr)% 1000000007<<endl;
        }
    }
    return 0;
}
