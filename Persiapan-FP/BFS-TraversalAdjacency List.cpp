// Program to print BFS traversal from a given
// source vertex. BFS(int s) traverses vertices
// reachable from s.
#include <bits/stdc++.h>
using namespace std;

// This class represents a directed graph using
// adjacency list representation
class Graph
{
    int V; // No. of vertices

    // Pointer to an array containing adjacency
    // lists
    vector<list<int>> adj;

public:
    Graph(int V); // Constructor

    // function to add an edge to graph
    void addEdge(int v, int w);

    // prints BFS traversal from a given source s
    void BFS(int s);
};

Graph::Graph(int V)
{
    this->V = V;
    adj.resize(V);
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}

void Graph::BFS(int s)
{
    // Mark all the vertices as not visited
    vector<bool> visited;
    visited.resize(V, false);

    // Create a queue for BFS
    list<int> queue;

    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);

    while (!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        s = queue.front();
        cout << "(V" << s << ") ";
        queue.pop_front();

        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited,
        // then mark it visited and enqueue it
        for (auto adjecent : adj[s])
        {
            if (!visited[adjecent])
            {
                visited[adjecent] = true;
                queue.push_back(adjecent);
            }
        }
    }
}

// Driver program to test methods of graph class
int main()
{
    // Create a graph given in the above diagram
    Graph g(21);
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

    cout << "Following is Breadth First Traversal "
         << "Starting from vertex 0 (Rumah) \n";
    g.BFS(0);

    return 0;
}
