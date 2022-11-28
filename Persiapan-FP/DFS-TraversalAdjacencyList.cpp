// C++ program to print DFS traversal from
// a given vertex in a given graph
#include <bits/stdc++.h>
using namespace std;

// Graph class represents a directed graph
// using adjacency list representation
class Graph
{
public:
    map<int, bool> visited;
    map<int, list<int>> adj;

    // function to add an edge to graph
    void addEdge(int v, int w);

    // DFS traversal of the vertices
    // reachable from v
    void DFS(int v);
};

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}

void Graph::DFS(int v)
{
    // Mark the current node as visited and
    // print it
    visited[v] = true;
    cout << "(V" << v << ") ";

    // Recur for all the vertices adjacent
    // to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFS(*i);
}

// Driver's code
int main()
{
    // Create a graph given in the above diagram
    Graph g;
    g.addEdge(0, 17);
    g.addEdge(0, 2);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 5);
    g.addEdge(3, 4);
    g.addEdge(4, 6);
    g.addEdge(5, 6);
    g.addEdge(5, 6);
    g.addEdge(6, 8);
    g.addEdge(6, 7);
    g.addEdge(7, 11);
    g.addEdge(8, 10);
    g.addEdge(8, 9);
    g.addEdge(9, 13);
    g.addEdge(9, 10);
    g.addEdge(11, 9);
    g.addEdge(12, 11);
    g.addEdge(13, 14);
    g.addEdge(14, 15);
    g.addEdge(15, 17);
    g.addEdge(15, 16);
    g.addEdge(16, 19);
    g.addEdge(17, 18);
    g.addEdge(19, 20);
    g.addEdge(20, 17);

    // Function call
    g.DFS(0);

    return 0;
}

// improved by Vishnudev C
