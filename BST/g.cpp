#include<iostream>
#include<map>
#include<list>
using namespace std;


class graph{

private:

	int v;
	list<int> *l;

public:

	graph(int v){
		this->v = v;
		l = new list<int>[v];
	}

	void addEdge(int a, int b, bool bidir = true){
		l[a].push_back(b);
		if(bidir){
			l[b].push_back(a);
		}
		return;
	}

	void PrintAdjList(){
		for(int i = 0; i < v; i++){
			cout<<i<<" -> ";
			for(int vertex : l[i]){
				cout<<vertex<<" ";
			}
			cout<<endl;
		}
		return;
	}
};

int main(){

	graph g(5);
	g.addEdge(1, 2);
	g.addEdge(1, 3);
	g.addEdge(2, 4);
	g.addEdge(3, 4);
	g.addEdge(4, 3);

	g.PrintAdjList();

	return 0;

}
