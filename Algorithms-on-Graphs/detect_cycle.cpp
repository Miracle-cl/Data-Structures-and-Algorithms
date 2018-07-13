#include <iostream>
#include <list>

using namespace std;

class Graph
{
	int V;
	list<int> *adj;
	bool isCyclicUtil(int v, bool visited[], bool *rs);
public:
	Graph(int V);
	void add_edge(int v, int w);
	bool is_cyclic();
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::add_edge(int v, int w) {
	adj[v].push_back(w);
}

bool Graph::isCyclicUtil(int v, bool visited[], bool *rec_stack) {
	if (!visited[v]) {
		// mark the current node as visited and part of recursion stack
		visited[v] = true;
		rec_stack[v] = true;

		// recur for all the vertices adjacent to this vertex
		list<int> :: iterator i;
		for (i = adj[v].begin(); i != adj[v].end(); ++i) {
			if (!visited[*i] && isCyclicUtil(*i, visited, rec_stack))
				return true;
			else if (rec_stack[*i])
				return true;
		}
	}
	rec_stack[v] = false;
	return false;
}

bool Graph::is_cyclic() {
	bool *visited = new bool[V];
	bool *rec_stack = new bool[V];
	for (int i = 0; i < V; ++i) {
		visited[i] = false;
		rec_stack[i] = false;
	}

	for (int i = 0; i < V; ++i)
		if (isCyclicUtil(i, visited, rec_stack))
			return true;
	return false;
}

int main()
{
	Graph g(5);
	g.add_edge(0,1);
	g.add_edge(1,2);
	g.add_edge(0,2);
	g.add_edge(2,3);
	g.add_edge(0,3);
	g.add_edge(1,4);
	g.add_edge(2,4);

	if (g.is_cyclic())
		cout << "1\n";
	else
		cout << "0\n";

	return 0;
}
