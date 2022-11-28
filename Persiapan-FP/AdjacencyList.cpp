#include <bits/stdc++.h>
using namespace std;

// Struktur data untuk menyimpan node adjacency list
struct Node
{
    int val;
    Node *next;
};

// Struktur data untuk menyimpan graph edge
struct Edge
{
    int src, dest;
};

class Graph
{
    // Berfungsi untuk mengalokasikan node baru untuk adjacency list
    Node *getAdjListNode(int dest, Node *head)
    {
        Node *newNode = new Node;
        newNode->val = dest;

        // arahkan node baru ke head saat ini
        newNode->next = head;

        return newNode;
    }

    int N; // jumlah total node dalam grafik

public:
    // Sebuah array pointer ke Node untuk mewakili
    // adjacency list
    Node **head;

    // Constructor
    Graph(Edge edges[], int n, int N)
    {
        // allokasi memori
        head = new Node *[N]();
        this->N = N;

        // menginisialisasi pointer head untuk semua vertices
        for (int i = 0; i < N; i++)
        {
            head[i] = nullptr;
        }

        // tambahkan edges ke directed graph
        for (unsigned i = 0; i < n; i++)
        {
            int src = edges[i].src;
            int dest = edges[i].dest;

            // masukkan diawal
            Node *newNode = getAdjListNode(dest, head[src]);

            // arahkan pointer head ke node baru
            head[src] = newNode;
        }
    }

    // Destructor
    ~Graph()
    {
        for (int i = 0; i < N; i++)
        {
            delete[] head[i];
        }

        delete[] head;
    }
};

// Berfungsi untuk mencetak semua vertices tetangga dari vertices yang diberikan
void printList(Node *ptr)
{
    while (ptr != nullptr)
    {
        cout << " —> " << ptr->val;
        ptr = ptr->next;
    }
    cout << endl;
}

int main()
{
    // array dari graph edges sesuai diagram di atas
    Edge edges[] =
        {
            // pasangan {x, y} merepresentasikan sisi dari `x` hingga `y`
            {0, 17},
            {0, 2},
            {0, 1},
            {1, 2},
            {2, 3},
            {3, 5},
            {3, 4},
            {4, 6},
            {5, 6},
            {6, 8},
            {6, 7},
            {7, 11},
            {8, 10},
            {8, 9},
            {9, 13},
            {9, 10},
            {11, 9},
            {12, 11},
            {13, 14},
            {14, 15},
            {15, 17},
            {15, 16},
            {16, 19},
            {17, 18},
            {19, 20},
            {20, 17}};

    // jumlah total node dalam grafik
    int N = 21;

    // menghitung jumlah total edges
    int n = sizeof(edges) / sizeof(edges[0]);

    // construct graph
    Graph graph(edges, n, N);

    // cetak adjacency list representasi dari grafik
    for (int i = 0; i < N; i++)
    {
        // cetak titik yang diberikan
        cout << i;

        // mencetak semua vertices tetangganya
        printList(graph.head[i]);
    }

    return 0;
}
