#include <iostream>
#include "Graph.h"
using namespace std;
int main() {
	Graph g(6);
	g.insertEdge(1, 5);
	g.insertEdge(1, 3);
	g.insertEdge(2, 1);
	g.showGraphStructure();
	cout << endl << "BFS Traversal: ";
	g.BFS(1);
	cout << endl;
	cout << "DFS Traversal: ";
	g.DFS(1);
	cout << endl;
}