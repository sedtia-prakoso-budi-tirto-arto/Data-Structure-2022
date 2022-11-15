#include <bits/stdc++.h>
using namespace std;

class Mahasiswa
{
public:
    string Nama;

    void tampilNama()
    {
        cout << "Nama Mahasiswa : " << Nama;
    }
};

int main()
{
    Mahasiswa mhs1;

    mhs1.Nama = "Prakas";

    mhs1.tampilNama();

    return 0;
}