#include <bits/stdc++.h>
using namespace std;

class Mahasiswa
{

private:
    string Nama;

public:
    void tampilNama()
    {
        cout << "Nama Mahasiswa : " << Nama;
    }

    string getNama()
    {
        return Nama;
    }

    Mahasiswa(string nama)
    {
        Nama = nama;
    }
};

int main()
{

    Mahasiswa mhs1("Prakas");

    mhs1.tampilNama();

    cout << " ";

    cout << mhs1.getNama();

    return 0;
}