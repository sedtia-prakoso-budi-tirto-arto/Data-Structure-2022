#include <bits/stdc++.h>

using namespace std;

int vertArr[20][20]; // matriks adjacency awalnya 0
int count = 0;
void displayMatrix(int v)
{
    int i, j;
    for (i = 0; i < v; i++)
    {
        for (j = 0; j < v; j++)
        {
            cout << vertArr[i][j] << " ";
        }
        cout << endl;
    }
}
void add_edge(int u, int v)
{ // fungsi untuk menambahkan edge ke dalam matriks
    vertArr[u][v] = 1;
}
main(int argc, char *argv[])
{
    int v = 21; // terdapat 21 vertices didalam grafik
    add_edge(0, 17);
    add_edge(0, 2);
    add_edge(0, 1);
    add_edge(1, 2);
    add_edge(2, 3);
    add_edge(3, 5);
    add_edge(3, 4);
    add_edge(4, 6);
    add_edge(5, 6);
    add_edge(5, 6);
    add_edge(6, 8);
    add_edge(6, 7);
    add_edge(7, 11);
    add_edge(8, 10);
    add_edge(8, 9);
    add_edge(9, 13);
    add_edge(9, 10);
    add_edge(11, 9);
    add_edge(12, 11);
    add_edge(13, 14);
    add_edge(14, 15);
    add_edge(15, 17);
    add_edge(15, 16);
    add_edge(16, 19);
    add_edge(17, 18);
    add_edge(19, 20);
    add_edge(20, 17);
    displayMatrix(v);
}