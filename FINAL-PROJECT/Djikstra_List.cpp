#include <iostream>
#include <list>
#include <queue>
#include <string.h>
using namespace std;
typedef pair<int,int> intPair;

class Graph{
	int V;
	list<pair<int,int>> adj[22];
	string places[22];
	public:
	Graph(int v){
	    V = v;
	}
	
	void addVertex(string str, int u, int v, int w){
	    adj[u].push_back(make_pair(v, w));
	    places[v] = str;
	}
	
	void showAllVertex(){
	    for(int i = 0; i<V;i++){
	    	cout << i << " :";
	        for(auto const &j: adj[i]){
	            cout << " " << j.first << " ";
	        }
	        cout << endl;
	    }
	}
	
	void djikstra(int src){
		priority_queue<intPair, vector<intPair>, greater<intPair> >
        q;
		q.push(make_pair(1, src));
		int dist[V];
		for(int i = 0; i<V; i++){
		    dist[i] = 100;
		}
		dist[src] = 0;
		
		while(!q.empty()){
			int u = q.top().second;
			q.pop();
			
			list<pair<int,int>> :: iterator i;
			for(i = adj[u].begin(); i != adj[u].end(); i++){
				int v = (*i).first;
				int w = (*i).second;
				if(dist[v] > dist[u] + w){
					dist[v] = dist[u] + w;
					q.push(make_pair(dist[v], v));
				}
			}
		}
		printf("Vertex Distance from Source\n");
    for (int i = 0; i < V; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
	}
	
};
int main(){
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
	g.showAllVertex();
	int src;
	cin >> src;
    g.djikstra(src);
}