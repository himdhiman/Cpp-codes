#include<bits/stdc++.h>
using namespace std;


template<typename T>
class Graph{

private:
	map<T, list<T> > AdjList;

public:

	Graph(){

	}

	void AddEdge(T a, T b, bool bidir = true){
		AdjList[a].push_back(b);
		if(bidir){
			AdjList[b].push_back(a);
		}
		return;
	}

	void Print(){
		for(auto object : AdjList){
			cout<<object.first<<" -> ";
			for(auto data : object.second){
				cout<<data<<" ";
			}
			cout<<endl;
		}
		return;
	}

};


int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	Graph<int> g;
	int n,a,b;
	bool bidir;
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>a;
		cin>>b;
		cin>>bidir;
		cout<<a<<" "<<b<<" "<<bidir<<endl;
		g.AddEdge(a, b, bidir);
	}

	// g.Print();

	return 0;

}