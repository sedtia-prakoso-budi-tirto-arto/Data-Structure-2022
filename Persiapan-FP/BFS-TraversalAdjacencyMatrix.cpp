// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;

// function to add edge to the graph
void addEdge(int x, int y)
{
    adj[x][y] = 1;
}

// Function to perform BFS on the graph
void bfs(int start)
{
    // Visited vector to so that
    // a vertex is not visited more than once
    // Initializing the vector to false as no
    // vertex is visited at the beginning
    vector<bool> visited(adj.size(), false);
    vector<int> q;
    q.push_back(start);

    // Set source as visited
    visited[start] = true;

    int vis;
    while (!q.empty())
    {
        vis = q[0];

        // Print the current node
        cout << "(V" << vis << ") ";
        q.erase(q.begin());

        // For every adjacent vertex to the current vertex
        for (int i = 0; i < adj[vis].size(); i++)
        {
            if (adj[vis][i] == 1 && (!visited[i]))
            {

                // Push the adjacent node to the queue
                q.push_back(i);

                // Set
                visited[i] = true;
            }
        }
    }
}

// Driver code
int main()
{
    // number of vertices
    int v = 21;

    // adjacency matrix
    adj = vector<vector<int>>(v, vector<int>(v, 0));

    addEdge(0, 17);
    addEdge(0, 2);
    addEdge(0, 1);
    addEdge(1, 2);
    addEdge(2, 3);
    addEdge(3, 5);
    addEdge(3, 4);
    addEdge(4, 6);
    addEdge(5, 6);
    addEdge(5, 6);
    addEdge(6, 8);
    addEdge(6, 7);
    addEdge(7, 11);
    addEdge(8, 10);
    addEdge(8, 9);
    addEdge(9, 13);
    addEdge(9, 10);
    addEdge(11, 9);
    addEdge(12, 11);
    addEdge(13, 14);
    addEdge(14, 15);
    addEdge(15, 17);
    addEdge(15, 16);
    addEdge(16, 19);
    addEdge(17, 18);
    addEdge(19, 20);
    addEdge(20, 17);

    // perform bfs on the graph
    bfs(0);
}
