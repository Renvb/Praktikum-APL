#include <iostream>
#include <string>

using namespace std;

const int MAX_GRUP = 100;

int main() {
    string nama, nim;
    int percobaan = 0;

    while (percobaan < 3) {
        system("cls");
        cout << "Masukkan Nama: ";
        getline(cin, nama);
        cout << "Masukkan NIM: ";
        getline(cin, nim);

        if (nama == "a" && nim == "1") {
            break;
        } else {
            percobaan++;
            cout << "Nama atau NIM salah. Percobaan ke-" << percobaan << endl;
            cout << "Tekan enter untuk melanjutkan..." << endl;
            cin.ignore();
        }
    }

    if (percobaan == 3) {
        cout << "Anda telah gagal 3 kali. Program berakhir." << endl;
        cout << "Tekan enter untuk melanjutkan..." << endl;
            cin.ignore();
        system("cls");
        return 0;
    }

    string namaGrup[MAX_GRUP] = {"GFRIEND", "VIVIZ", "The Wind"};
    int jumlahAnggota[MAX_GRUP] = {6, 3, 6};
    string namaAnggota[MAX_GRUP][25] = {
        {"Sowon", "Yerin", "Eunha", "Yuju", "SinB", "Umji"},
        {"SinB", "Eunha", "Umji"},
        {"Thanatorn", "Park Hayuchan", "Kim Heesoo", "Choi Hanbin", "An Chanwon", "Jang Hyounjoon"}
    };
    string namaAgensi[MAX_GRUP] = {"Source Music", "BPM Entertainment", "With US Entertainment"};
    string tanggalDebut[MAX_GRUP] = {"2015-01-16", "2022-02-09", "2023-05-15"};
    string namaFandom[MAX_GRUP] = {"BUDDY", "Na.V", "WHIZ"};
    bool statusAktif[MAX_GRUP] = {true, true, true};
    int jumlahGrup = 3;

    int pilihan;

    do {
        system("cls");
        cout << "\n=== Manajemen Grup K-Pop ===" << endl;
        cout << "1. Tambah Grup K-Pop" << endl;
        cout << "2. Lihat Daftar Grup K-Pop" << endl;
        cout << "3. Ubah Data Grup K-Pop" << endl;
        cout << "4. Hapus Grup K-Pop" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilihan Anda: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1: {
                system("cls");
                if (jumlahGrup < MAX_GRUP) {
                    cout << "\n--- Tambah Grup K-Pop ---" << endl;
                    string grupBaru;
                    cout << "Nama Grup: ";
                    getline(cin, grupBaru);

                    bool namaSudahAda = false;
                    for (int i = 0; i < jumlahGrup; ++i) {
                        if (namaGrup[i] == grupBaru) {
                            namaSudahAda = true;
                            break;
                        }
                    }

                    if (namaSudahAda) {
                        cout << "Grup dengan nama tersebut sudah ada." << endl;
                        cout << "Tekan enter untuk melanjutkan..." << endl;
                        cin.ignore();
                        break;
                    }

                    namaGrup[jumlahGrup] = grupBaru;

                    int anggotaBaru;
                        cout << "Jumlah Anggota: ";
                        cin >> anggotaBaru;

                        if (cin.fail() || anggotaBaru <= 0 || anggotaBaru > 25) {
                            cout << "Input tidak valid." << endl;
                            cin.ignore();
                            cin.clear();
                            cout << "Tekan enter untuk melanjutkan..." << endl;
                            cin.ignore();
                            cin.ignore();
                            cin.ignore();
                            break;
                        }
                    jumlahAnggota[jumlahGrup] = anggotaBaru;
                    cin.ignore();

                    cout << "Nama Anggota (pisahkan dengan koma): ";
                    string anggotaInput;
                    getline(cin, anggotaInput);
                    string anggota;
                    int indexAnggota = 0;
                    for (char c : anggotaInput) {
                        if (c == ',') {
                            namaAnggota[jumlahGrup][indexAnggota++] = anggota;
                            anggota = "";
                        } else {
                            anggota += c;
                        }
                    }
                    namaAnggota[jumlahGrup][indexAnggota] = anggota;

                    cout << "Nama Agensi: ";
                    getline(cin, namaAgensi[jumlahGrup]);

                    cout << "Tanggal Debut (TTTT-BB-HH): ";
                    getline(cin, tanggalDebut[jumlahGrup]);

                    cout << "Nama Fandom: ";
                    getline(cin, namaFandom[jumlahGrup]);

                    bool statusAktifBaru;
                    cout << "Status Aktif (1: Aktif, 0: Tidak Aktif): ";
                    cin >> statusAktifBaru;
                    if (cin.fail() || (statusAktifBaru != 1 && statusAktifBaru != 0)) {
                        cout << "Input tidak valid." << endl;
                        cin.clear();
                        cin.ignore();
                        cout << "Tekan enter untuk melanjutkan..." << endl;
                        cin.ignore();
                        cin.ignore();
                        break;
                    }
                    statusAktif[jumlahGrup] = statusAktifBaru;
                    cin.ignore();

                    cout << "Grup K-Pop berhasil ditambahkan!" << endl;
                    jumlahGrup++;
                } else {
                    cout << "Jumlah grup maksimum telah tercapai." << endl;
                    cout << "Tekan enter untuk melanjutkan..." << endl;
                    cin.ignore();
                    cin.ignore();
                }
                cout << "Tekan enter untuk melanjutkan..." << endl;
                cin.ignore();
                cin.ignore();
                break;
            }
            case 2: {
                system("cls");
                cout << "\n--- Daftar Grup K-Pop ---\n" << endl;
                cout << string(50, '-') << endl;
                if (jumlahGrup == 0) {
                    cout << "Belum ada grup K-Pop yang ditambahkan." << endl;
                    cout << string(50, '-') << endl;
                    cout << "Tekan enter untuk melanjutkan..." << endl;
                        cin.ignore();
                    break;
                }

                for (int i = 0; i < jumlahGrup; ++i) {
                    cout << "Nama Grup: " << namaGrup[i] << endl;
                    cout << "Jumlah Anggota: " << jumlahAnggota[i] << endl;
                    cout << "Nama Anggota: ";
                    for (int j = 0; j < jumlahAnggota[i]; ++j) {
                        cout << namaAnggota[i][j] << (j < jumlahAnggota[i] - 1 ? ", " : "");
                    }
                    cout << endl;
                    cout << "Nama Agensi: " << namaAgensi[i] << endl;
                    cout << "Tanggal Debut: " << tanggalDebut[i] << endl;
                    cout << "Nama Fandom: " << namaFandom[i] << endl;
                    cout << "Status: " << (statusAktif[i] ? "Aktif" : "Tidak Aktif") << endl;
                    cout << string(50, '-') << endl;
                }
                cout << "Tekan enter untuk melanjutkan..." << endl;
                cin.ignore();
                break;
            }
            case 3: {
                system("cls");
                string grupUbah;
                cout << "\n--- Ubah Data Grup K-Pop ---" << endl;
                cout << "Masukkan Nama Grup yang ingin diubah: ";
                getline(cin, grupUbah);

                bool ditemukan = false;
                for (int i = 0; i < jumlahGrup; ++i) {
                    if (namaGrup[i] == grupUbah) {
                        string anggotaInput;
                        string anggota;
                        int indexAnggota = 0;
                        cout << "1. Nama Grup" << endl;
                        cout << "2. Jumlah Anggota" << endl;
                        cout << "3. Nama Anggota" << endl;
                        cout << "4. Nama Agensi" << endl;
                        cout << "5. Tanggal Debut" << endl;
                        cout << "6. Nama Fandom" << endl;
                        cout << "7. Status Aktif" << endl;
                        cout << "8. Ubah Semua Data" << endl;
                        cout << "Pilih data yang ingin diubah: ";
                        int pilihanUbah;
                        cin >> pilihanUbah;
                        cin.ignore();

                        switch (pilihanUbah) {
                            case 1:
                                cout << "Nama Grup Baru: ";
                                getline(cin, namaGrup[i]);
                                cout << "Data grup K-Pop berhasil diubah!" << endl;
                                cout << "Tekan enter untuk melanjutkan..." << endl;
                                cin.ignore();
                                break;
                            case 2: {
                                int anggotaBaru;
                                cout << "Jumlah Anggota Baru: ";
                                cin >> anggotaBaru;

                                if (cin.fail() || anggotaBaru <= 0 || anggotaBaru > 25) {
                                    cout << "Input tidak valid." << endl;
                                    cin.ignore();
                                    cin.clear();
                                    cout << "Tekan enter untuk melanjutkan..." << endl;
                                    cin.ignore();
                                    cin.ignore();
                                    cin.ignore();
                                    break;
                                    }
                                    jumlahAnggota[i] = anggotaBaru;
                                    cout << "Data grup K-Pop berhasil diubah!" << endl;
                                    cout << "Tekan enter untuk melanjutkan..." << endl;
                                    cin.ignore();
                                    cin.ignore();
                                    break;
                                }
                            case 3: {
                                cout << "Nama Anggota Baru (pisahkan dengan koma): ";
                                getline(cin, anggotaInput);
                                int indexAnggota = 0;
                                for (char c : anggotaInput) {
                                    if (c == ',') {
                                        namaAnggota[i][indexAnggota++] = anggota;
                                        anggota = "";
                                    } else {
                                        anggota += c;
                                    }
                                }
                                namaAnggota[i][indexAnggota] = anggota;
                                cout << "Data grup K-Pop berhasil diubah!" << endl;
                                cout << "Tekan enter untuk melanjutkan..." << endl;
                                cin.ignore();
                                break;
                            }
                            case 4:
                                cout << "Nama Agensi Baru: ";
                                getline(cin, namaAgensi[i]);
                                cout << "Data grup K-Pop berhasil diubah!" << endl;
                                cout << "Tekan enter untuk melanjutkan..." << endl;
                                cin.ignore();
                                break;
                            case 5:
                                cout << "Tanggal Debut Baru: ";
                                getline(cin, tanggalDebut[i]);
                                cout << "Data grup K-Pop berhasil diubah!" << endl;
                                cout << "Tekan enter untuk melanjutkan..." << endl;
                                cin.ignore();
                                break;
                            case 6:
                                cout << "Nama Fandom Baru: ";
                                getline(cin, namaFandom[i]);
                                cout << "Data grup K-Pop berhasil diubah!" << endl;
                                cout << "Tekan enter untuk melanjutkan..." << endl;
                                cin.ignore();
                                break;
                            case 7:
                                bool statusAktifBaru;
                                cout << "Status Aktif Baru (1: Aktif, 0: Tidak Aktif): ";
                                cin >> statusAktifBaru;
                                if (cin.fail() || (statusAktifBaru != 1 && statusAktifBaru != 0)) {
                                    cout << "Input tidak valid." << endl;
                                    cin.clear();
                                    cin.ignore();
                                    cout << "Tekan enter untuk melanjutkan..." << endl;
                                    cin.ignore();
                                    cin.ignore();
                                    break;
                                }
                                statusAktif[i] = statusAktifBaru;
                                cout << "Data grup K-Pop berhasil diubah!" << endl;
                                cout << "Tekan enter untuk melanjutkan..." << endl;
                                cin.ignore();
                                cin.ignore();
                                break;
                            case 8:
                                cout << "Nama Grup Baru: ";
                                getline(cin, namaGrup[i]);

                                int anggotaBaru;
                                cout << "Jumlah Anggota Baru: ";
                                cin >> anggotaBaru;

                                if (cin.fail() || anggotaBaru <= 0 || anggotaBaru > 25) {
                                    cout << "Input tidak valid." << endl;
                                    cin.ignore();
                                    cin.clear();
                                    cout << "Tekan enter untuk melanjutkan..." << endl;
                                    cin.ignore();
                                    cin.ignore();
                                    cin.ignore();
                                    break;
                                    }
                                    jumlahAnggota[i] = anggotaBaru;
                                    cin.ignore();

                                    cout << "Nama Anggota Baru (pisahkan dengan koma): ";
                                    getline(cin, anggotaInput);
                                    for (char c : anggotaInput) {
                                        if (c == ',') {
                                            namaAnggota[i][indexAnggota++] = anggota;
                                            anggota = "";
                                        } else {
                                            anggota += c;
                                        }
                                    }
                                    namaAnggota[i][indexAnggota] = anggota;

                                    cout << "Nama Agensi Baru: ";
                                    getline(cin, namaAgensi[i]);

                                    cout << "Tanggal Debut Baru: ";
                                    getline(cin, tanggalDebut[i]);

                                    cout << "Nama Fandom Baru: ";
                                    getline(cin, namaFandom[i]);

                                    cout << "Status Aktif Baru (1: Aktif, 0: Tidak Aktif): ";
                                    cin >> statusAktifBaru;
                                    if (cin.fail() || (statusAktifBaru != 1 && statusAktifBaru != 0)) {
                                        cout << "Input tidak valid." << endl;
                                        cin.clear();
                                        cin.ignore();
                                        cout << "Tekan enter untuk melanjutkan..." << endl;
                                        cin.ignore();
                                        cin.ignore();
                                        break;
                                    }
                                    statusAktif[i] = statusAktifBaru;
                                    cout << "Data grup K-Pop berhasil diubah!" << endl;
                                    cout << "Tekan enter untuk melanjutkan..." << endl;
                                    cin.ignore();
                                    cin.ignore();
                                    break;
                            default:
                                cout << "Pilihan tidak valid." << endl;
                                cout << "Tekan enter untuk melanjutkan..." << endl;
                                cin.ignore();
                        }
                        ditemukan = true;
                        break;
                    }
                    
                }
                if (!ditemukan) {
                    cout << "Grup K-Pop tidak ditemukan." << endl;
                    cout << "Tekan enter untuk melanjutkan..." << endl;
                    cin.ignore();
                }
                break;
            }
            case 4: {
                system("cls");
                string grupHapus;
                bool ditemukan = false;
                cout << "\n--- Hapus Grup K-Pop ---" << endl;
                cout << "Masukkan Nama Grup yang ingin dihapus: ";
                getline(cin, grupHapus);
                

                for (int i = 0; i < jumlahGrup; ++i) {
                    if (namaGrup[i] == grupHapus) {
                        for (int j = i; j < jumlahGrup - 1; ++j) {
                            namaGrup[j] = namaGrup[j + 1];
                            jumlahAnggota[j] = jumlahAnggota[j + 1];
                            for(int k=0; k<25; k++){
                                namaAnggota[j][k] = namaAnggota[j+1][k];
                            }
                            namaAgensi[j] = namaAgensi[j + 1];
                            tanggalDebut[j] = tanggalDebut[j + 1];
                            namaFandom[j] = namaFandom[j + 1];
                            statusAktif[j] = statusAktif[j + 1];
                        }
                        jumlahGrup--;
                        ditemukan = true;
                        cout << "Grup K-Pop berhasil dihapus!" << endl;
                        cout << "Tekan enter untuk melanjutkan..." << endl;
                        cin.ignore();
                        break;
                    }
                }
                if (!ditemukan) {
                    cout << "Grup tidak ditemukan" << endl;
                    cout << "Tekan enter untuk melanjutkan..." << endl;
                    cin.ignore();
                    break;
                }
                break;
            }
            case 5:
                cout << "Terima kasih telah menggunakan program ini!" << endl;
                cout << "Tekan enter untuk melanjutkan..." << endl;
                cin.ignore();
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
                cout << "Tekan enter untuk melanjutkan..." << endl;
                cin.ignore();
        }
    } while (pilihan != 5);

    system("cls");
    return 0;
}