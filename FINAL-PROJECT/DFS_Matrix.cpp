#include <iostream>
#include <list>
#include <iterator>
#include <queue>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <map>
using namespace std;

class Graph
{
protected:
    int v;
    vector<string> place;
    vector<vector<int>> adj;
    vector<int> dfsResult;
    vector<int> dijkstraRes;
    int dfsWeight;

public:
    Graph(int len)
    {
        v = len;
        place.assign(v + 1, "");
        vector<int> l(v + 1, -1);
        adj.assign(v + 1, l);
        dfsResult.assign(v + 1, 0);
        vector<int> vec(v + 1, 0);
    }

    void addVertex(string i, int u, int v, int w)
    {
        adj[u][v] = w;
        place[v] = i;
    }

    void showGraph()
    {
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                if (adj[i][j] == -1)
                    cout << ".  ";
                else if (adj[i][j] < 10)
                    cout << adj[i][j] << "  ";
                else
                    cout << adj[i][j] << " ";
            }
            cout << endl;
        }
    }

    void DFS(int start, int end)
    {
        cout << endl;
        cout << "================" << endl;
        dfsWeight = INT_MAX;
        vector<int> path;
        vector<bool> visited(v + 1, false);
        solveDFS(start, end, path, visited, 0);

        for (int i = 0; i < dfsResult.size(); i++)
        {
            cout << dfsResult[i] << " ";
        }

        cout << endl
             << "Weight = " << dfsWeight << endl;
    }

    void solveDFS(int start, int end, vector<int> path, vector<bool> visited, int currWeight)
    {
        if (start == end)
        {
            path.push_back(end);
            if (currWeight < dfsWeight)
            {
                dfsWeight = currWeight;
                dfsResult = path;
            }
            cout << currWeight << " ";
            for (int i = 0; i < path.size(); i++)
            {
                cout << path[i] << " ";
            }
            cout << endl;
        }
        visited[start] = true;
        path.push_back(start);
        for (int it = 1; it <= v; it++)
        {
            if (!visited[it] && adj[start][it] != -1)
            {
                int wtemp = currWeight;
                wtemp += adj[start][it];
                solveDFS(it, end, path, visited, wtemp);
            }
        }
    }
};

int main()
{
    Graph g(21);
    g.addVertex("Rumah", 0, 0, 0);
    g.addVertex("Mushola1", 0, 1, 2);
    g.addVertex("Mushola2", 0, 2, 4);
    g.addVertex("Candi Bajang Ratu", 0, 17, 5);
    g.addVertex("Mushola2", 1, 2, 3);
    g.addVertex("Wisata Religi Troloyo", 2, 3, 7);
    g.addVertex("SDN Sentonorejo", 3, 4, 6);
    g.addVertex("Masjid1", 3, 5, 9);
    g.addVertex("Alfamart", 3, 6, 8);
    g.addVertex("Alfamart", 4, 6, 3);
    g.addVertex("Alfamart", 5, 6, 5);
    g.addVertex("Terminal", 6, 7, 7);
    g.addVertex("Indomaret", 6, 8, 10);
    g.addVertex("Wisata Lantai Segi Enam", 7, 11, 2);
    g.addVertex("Kantor Desa", 8, 9, 4);
    g.addVertex("MI Brawijaya", 8, 10, 11);
    g.addVertex("MI Brawijaya", 9, 10, 13);
    g.addVertex("Pertashop", 9, 13, 8);
    g.addVertex("Kantor Desa", 11, 9, 15);
    g.addVertex("Wisata Lantai Segi Enam", 12, 11, 10);
    g.addVertex("Wisata Sumur Upas", 12, 12, 6);
    g.addVertex("Pendopo Agung", 13, 14, 12);
    g.addVertex("Masjid2", 14, 15, 11);
    g.addVertex("Apotek", 15, 16, 13);
    g.addVertex("Candi Bajang Ratu", 15, 17, 5);
    g.addVertex("Museum Sejarah", 16, 19, 7);
    g.addVertex("Candi Tikus", 17, 18, 4);
    g.addVertex("Kolam Segaran", 19, 20, 1);
    g.addVertex("Candi Bajang Ratu", 20, 17, 9);
    g.showGraph();
    int start, end;
    cin >> start >> end;
    g.DFS(start, end);
}