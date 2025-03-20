#include <iostream>

using namespace std;

struct Mahasiswa
{
    /* data */
    string nama;
    string nim;
};


int main() {

    Mahasiswa mhs[100];
    mhs[0].nama = "Razib Ramadhan";
    mhs[0].nim = "2409106076";

    mhs[1].nama = "Budi";
    mhs[1].nim = "2409106077";

    for (int i = 0; i < 2; i++) {
        cout << mhs[i].nama << endl;
        cout << mhs[i].nim << endl;
    }

    // struct Mahasiswa
    // {
    //     /* data */
    //     string nama;
    //     string nim;
    //     int umur;
    // };
    
    // typedef struct {
    //     /* data */
    //     string nama;
    //     string nim;
    //     int umur;
    // };

    // Mahasiswa mahasiswa;

    // mahasiswa = {"Razib Ramadhan", "2409106076"};
    // // mahasiswa.nama = "Razib Ramadhan";
    // // mahasiswa.nim = "2409106076";
    // cout << mahasiswa.nama << endl;
    // cout << mahasiswa.nim << endl;

    // struct Nilai
    // {
    //     int uts;
    //     int uas;
    // };

    // struct Data
    // {
    //     /* data */
    //     string nama;
    //     string nim;
    // };
    

    // struct Mahasiswa
    // {
    //     /* data */
    //     Data data;
    //     Nilai nilai;
    // };

    // Mahasiswa mhs;
    // mhs.data.nama = "Razib Ramadhan";
    // cout << mhs.data.nama << endl;

    return 0;
}