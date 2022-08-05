#pragma once
#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node() : next(NULL) {
	}
};


class Graph {
private:
	int vertices;
	Node** AdjList;

	Node* createVertice(int d) {
		Node* temp = new Node;
		temp->data = d;

		return temp;
	}
public:
	Graph(int maxVertices) {
		AdjList = new Node * [maxVertices];
		vertices = maxVertices;
		Node* temp;
		for (int i = 1; i <= maxVertices; ++i) {
			temp = createVertice(i);
			AdjList[i] = temp;
		}
	}

	void insertEdge(int source, int destination) {
		if (source < vertices) {
			Node* temp = AdjList[source];
			Node* temp1 = createVertice(destination);
			while (temp->next) {
				temp = temp->next;
			}
			temp->next = temp1;
		}
		else {
			cout << "Error" << endl;
		}
	}

	void showGraphStructure() {
		Node* temp;
		for (int i = 1; i <= vertices; ++i) {
			temp = AdjList[i];
			cout << "Edges from Node " << temp->data << ": ";
			temp = temp->next;
			while (temp) {
				cout << temp->data;
				if (temp->next) {
					cout << ", ";
				}
				temp = temp->next;
			}
			cout << endl;
		}
	}


	void BFS(int start) {
		bool* visitedNodes = new bool[vertices];
		for (int i = 1; i <= vertices; i++)
			visitedNodes[i] = false;

		queue<int> visits;
		visitedNodes[start] = true;
		visits.push(start);

		while (!visits.empty())
		{
			int s = visits.front();
			cout << s << " ";
			visits.pop();

			for (int i = 1; i <= vertices; ++i)
			{
				if (!visitedNodes[i])
				{
					visitedNodes[i] = true;
					visits.push(i);
				}
			}
		}
	}

	void DFS(int start) {
		bool* visitedNodes = new bool[vertices];
		for (int i = 1; i <= vertices; i++)
			visitedNodes[i] = false;
		stack<int> visits;

		visitedNodes[start] = true;
		visits.push(start);

		while (!visits.empty()) {
			int s = visits.top();
			cout << s << " ";
			visits.pop();


			for (int i = 1; i <= vertices; ++i)
			{
				if (!visitedNodes[i])
				{
					visitedNodes[i] = true;
					visits.push(i);
				}
			}
		}
	}
};