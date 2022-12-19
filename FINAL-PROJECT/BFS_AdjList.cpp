#include <iostream>
#include <list>
#include <queue>
#include <string.h>
using namespace std;

class Graph{
	int V;
	list<int> adj[22];
	string places[22];
	public:
	Graph(int v){
	    V = v;
	}
	
	void addVertex(string str, int u, int v){
	    adj[u].push_back(v);
	    places[v] = str;
	}
	
	void showAllVertex(){
	    for(int i = 0; i<V;i++){
	    	cout << i << " :";
	        for(auto const &j: adj[i]){
	            cout << " " << j << " ";
	        }
	        cout << endl;
	    }
	}
	
	bool shortest_path(int src, int dest, int pred[], int dist[]){
	queue<int> q;
	bool visited[V] = {false};
	dist[21] = {0};
	pred[21] = {-1};
	visited[src] = true;
	dist[src] = 0;
	q.push(src);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(auto const &i: adj[u]){
			if(visited[i] == false){
				visited[i] = true;
				dist[i] = dist[u] + 1;
				pred[i] = u;
				cout << u << " " << i << endl;
				q.push(i);
				if(i == dest) return true;
			}
		}
	}
	return false;
    }
    
    void shortestDistance(int src, int dest){
	int pred[V], dist[V];
	shortest_path(src, dest, pred, dist);
	vector<int> path;
	int c = dest;
	path.push_back(c);
	while(pred[c] != 0){
		path.push_back(pred[c]);
		c = pred[c];
	}
	for(int i = path.size() - 1; i >= 0; i--){
			cout << path[i] << " " << places[path[i]] << endl;
		}
}
};
int main(){
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
	g.showAllVertex();
	int source, dest;
	cin >> source >> dest;
    g.shortestDistance(source,dest);
}