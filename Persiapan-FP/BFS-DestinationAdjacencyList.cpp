#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<pair<int, string>> adj[100];

public:
    Graph(int v)
    {
        V = v;
    }

    void addVertex(string str, int v1, int v2)
    {
        adj[v1].push_back(make_pair(v2, str));
    }

    void bfs(string startVertex, string destination)
    {
        vector<bool> visited;
        visited.resize(V, false);
        queue<pair<int, string>> q;
        q.push(make_pair(0, startVertex));
        visited[0] = true;
        while (!q.empty())
        {
            for (auto const &i : adj[q.front().first])
            {
                if (!visited[i.first])
                {
                    visited[i.first] = true;
                    q.push(make_pair(i.first, i.second));
                }
            }
            cout << "(" << q.front().second << ") -> ";
            const char *c = q.front().second.c_str();
            const char *d = destination.c_str();
            q.pop();
            if (strcmp(c, d) == 0)
                break;
        }
    }
};
int main()
{
    Graph g(21);

    g.addVertex("Rumah", 0, 0);
    g.addVertex("Mushola1", 0, 1);
    g.addVertex("Mushola2", 0, 2);
    g.addVertex("Candi Bajang Ratu", 0, 17);
    g.addVertex("Mushola2", 1, 2);
    g.addVertex("Wisata Religi Troloyo", 2, 3);
    g.addVertex("SDN Sentonorejo", 3, 4);
    g.addVertex("Masjid1", 3, 5);
    g.addVertex("Alfamart", 3, 6);
    g.addVertex("Alfamart", 4, 6);
    g.addVertex("Alfamart", 5, 6);
    g.addVertex("Terminal", 6, 7);
    g.addVertex("Indomaret", 6, 8);
    g.addVertex("Wisata Lantai Segi Enam", 7, 11);
    g.addVertex("Kantor Desa", 8, 9);
    g.addVertex("MI Brawijaya", 8, 10);
    g.addVertex("MI Brawijaya", 9, 10);
    g.addVertex("Pertashop", 9, 13);
    g.addVertex("Kantor Desa", 11, 9);
    g.addVertex("Wisata Lantai Segi Enam", 12, 11);
    g.addVertex("Wisata Sumur Upas", 12, 12);
    g.addVertex("Pendopo Agung", 13, 14);
    g.addVertex("Masjid2", 14, 15);
    g.addVertex("Apotek", 15, 16);
    g.addVertex("Candi Bajang Ratu", 15, 17);
    g.addVertex("Museum Sejarah", 16, 19);
    g.addVertex("Candi Tikus", 17, 18);
    g.addVertex("Kolam Segaran", 19, 20);
    g.addVertex("Candi Bajang Ratu", 20, 17);

    g.bfs("Rumah", "Kolam Segaran");
}