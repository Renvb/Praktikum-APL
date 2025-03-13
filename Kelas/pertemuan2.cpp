#include <iostream>

using namespace std;
#define max 100
int panjangArray = 0;
int arr[max];
int pilihan, index;

int main() {

    while (true) {
        cout << "Pilih Menu" << endl;
        cout << "1. Input Data" << endl;
        cout << "2. Tampilkan Data" << endl;
        cout << "3. Hapus Data" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;
    
        if (pilihan == 1) {
            if (panjangArray < max) {
                cout << "Masukkan data: ";
                cin >> arr[panjangArray];
                panjangArray++;
            } else if (panjangArray = 0) {
                cout << "Array masih kosong" << endl;
            } else {
                cout << "Array sudah penuh" << endl;
            }
        } else if (pilihan == 2) {
            
        }
        
    }

    // string nama[5] = {"Andi", "Budi", "Caca", "Deni", "Euis"};
    // int panjang = sizeof(nama) / sizeof(nama[0]);
    // cout << nama[5] << endl;
    // cout << sizeof(nama) / sizeof(nama[0]); //total elemen array
    // cout << sizeof(nama) / sizeof(string) << endl;

    // for (int i = 0; i < panjang; i++) {
    //     cout << nama[i] << endl;
    // }

    // for (int x : nama) {
    //     cout << x << endl;
    // }


    // string nama[4][5] = {
    //     {"Andi", "Informatika", "123", "Makan"},
    //     {"Euis", "Sipil", "133", "Main"},
    //     {"Iwan", "Sipil", "012", "Main"},
    //     {"Mali", "Industri", "111", "minum"}
    // };

    // cout << nama[0][3] << endl;

    // int arr[3][3][3] = {
    //         {
    //             {1, 2, 3},
    //             {4, 5, 6},
    //             {7, 8, 9}
    //         },
    //         {
    //             {10, 11, 12},
    //             {13, 14, 15},
    //             {16, 17, 18}
    //         },
    //         {
    //             {19, 20, 21},
    //             {22, 23, 24},
    //             {25, 26, 27}
    //         }
    //     };

    // cout << arr[1][2][1] << endl; // Output: 17



    return 0;

}