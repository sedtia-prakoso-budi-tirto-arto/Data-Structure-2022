#include <bits/stdc++.h>

using namespace std;

class Graph
{
protected:
    int vertex;
    list<int> adj[255];

public:
    Graph(int len)
    {
        vertex = len;
    }

    void setLen(int len)
    {
        vertex = len;
        adj[vertex];
    }

    void addEdge(int u, int vertex)
    {
        if (adj[u].empty())
            adj[u].push_back(u);
        if (adj[vertex].empty())
            adj[vertex].push_back(vertex);
        adj[u].push_back(vertex);
        adj[vertex].push_back(u);
    }

    void showGraph()
    {
        for (int i = 0; i <= vertex; i++)
        {
            list<int>::iterator it;
            for (it = adj[i].begin(); it != adj[i].end(); ++it)
            {
                cout << *it << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph graph1(5);

    graph1.addEdge(0, 1);
    graph1.addEdge(0, 4);
    graph1.addEdge(1, 2);
    graph1.addEdge(1, 3);
    graph1.addEdge(1, 4);
    graph1.addEdge(2, 3);
    graph1.addEdge(3, 4);

    graph1.showGraph();
}