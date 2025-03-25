#include <iostream>
#include <string>

using namespace std;

struct GrupKPop {
    string nama;
    int jumlahAnggota;
    string namaAnggota[25];
    string namaAgensi;
    string tanggalDebut;
    string namaFandom;
    bool statusAktif;
};

struct Pengguna {
    string nama;
    string password;
    string peran;
};

const int MAX = 100;

int main() {
    GrupKPop daftarGrup[MAX];
    Pengguna daftarPengguna[MAX];
    int jumlahGrup = 3;
    int jumlahPengguna = 3;

    // Data grup K-Pop awal
    daftarGrup[0] = {"GFRIEND", 6, {"Sowon", "Yerin", "Eunha", "Yuju", "SinB", "Umji"}, "Source Music", "2015-01-16", "BUDDY", true};
    daftarGrup[1] = {"VIVIZ", 3, {"SinB", "Eunha", "Umji"}, "BPM Entertainment", "2022-02-09", "Na.V", true};
    daftarGrup[2] = {"The Wind", 6, {"Thanatorn", "Park Hayuchan", "Kim Heesoo", "Choi Hanbin", "An Chanwon", "Jang Hyounjoon"}, "With US Entertainment", "2023-05-15", "WHIZ", true};
    
    // Data pengguna awal
    daftarPengguna[0] = {"Razib Ramadhan", "2409106076", "admin"};
    daftarPengguna[1] = {"user", "user", "user"};
    daftarPengguna[2] = {"admin", "admin", "admin"};
    bool loginSuccess = false;
    string level;

    while (loginSuccess == false) {
        
        system("cls");
        cout << "=== Pilih menu ===" << endl;
        cout << "1. Registrasi Pengguna" << endl;
        cout << "2. Login Pengguna" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilihan: ";
        int pilihan;
        cin >> pilihan;
        cin.ignore();
        
        string nama;
        string password;
        string peran;
        bool statusRegis = false;
        int percobaan = 0;
        switch (pilihan) {
            case 1:
                if (jumlahPengguna >= MAX) {
                    system("cls");
                    cout << "Pengguna sudah penuh. Registrasi gagal." << endl;
                    break;
                }
                system("cls");
                cout << "=== Registrasi Pengguna ===" << endl;
                cout << "Nama: ";
                getline(cin, nama);
                cout << "Password: ";
                getline(cin, password);
                peran = "user";
    
                if (jumlahPengguna < MAX) {
                    for (int i = 0; i < jumlahPengguna; i++) {
                        if (daftarPengguna[i].nama == nama) {
                            statusRegis = true;
                            cout << "Nama pengguna sudah terdaftar. Registrasi gagal." << endl;
                            cout << "Tekan enter untuk melanjutkan..." << endl;
                            cin.ignore();
                            break;
                        }
                    }
                    if (statusRegis == false) {
                        daftarPengguna[jumlahPengguna] = {nama, password, peran};
                        jumlahPengguna++;
                        cout << "Registrasi berhasil!" << endl;
                        cout << "Tekan enter untuk melanjutkan..." << endl;
                        cin.ignore();
                }
                break;
    
            case 2:
        
            while (percobaan < 3) {
                system("cls");
                cout << "=== Login Pengguna ===" << endl;
                cout << "Masukkan Nama: ";
                getline(cin, nama);
                cout << "Masukkan Password: ";
                getline(cin, password);
    
                for (int i = 0; i < jumlahPengguna; i++) {
                    if (daftarPengguna[i].nama == nama && daftarPengguna[i].password == password) {
                        level = daftarPengguna[i].peran;
                        loginSuccess = true;
                        break;
                    }
                }
    
                if (loginSuccess) {
                    cout << "Login berhasil!" << endl;
                    cout << "Tekan enter untuk melanjutkan..." << endl;
                    cin.ignore();
                    system("cls");
                    break;
                } else {
                    percobaan++;
                    cout << "Nama atau Password salah. Percobaan ke-" << percobaan << endl;
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
                break;
            case 3:
                cout << "Terima kasih telah menggunakan program ini!" << endl;
                cout << "Tekan enter untuk melanjutkan..." << endl;
                cin.ignore();
                return 0;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
                cout << "Tekan enter untuk melanjutkan..." << endl;
                cin.clear();
                cin.ignore();
                cin.ignore();
                cin.ignore();
                continue;
        }
    }
}

while (loginSuccess && level == "admin") {

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
                if (jumlahGrup < MAX) {
                    GrupKPop grupBaru;
                    cout << "\n--- Tambah Grup K-Pop ---" << endl;
                    cout << "Nama Grup: ";
                    getline(cin, grupBaru.nama);

                    bool namaSudahAda = false;
                    for (int i = 0; i < jumlahGrup; ++i) {
                        if (daftarGrup[i].nama == grupBaru.nama) {
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
                    grupBaru.jumlahAnggota = anggotaBaru;
                    cin.ignore();

                    cout << "Nama Anggota (pisahkan dengan koma): ";
                    string anggotaInput;
                    getline(cin, anggotaInput);
                    string anggota;
                    int indexAnggota = 0;
                    for (char c : anggotaInput) {
                        if (c == ',') {
                            grupBaru.namaAnggota[indexAnggota++] = anggota;
                            anggota = "";
                        } else {
                            anggota += c;
                        }
                    }
                    grupBaru.namaAnggota[indexAnggota] = anggota;

                    cout << "Nama Agensi: ";
                    getline(cin, grupBaru.namaAgensi);

                    cout << "Tanggal Debut (TTTT-BB-HH): ";
                    getline(cin, grupBaru.tanggalDebut);

                    cout << "Nama Fandom: ";
                    getline(cin, grupBaru.namaFandom);

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
                        cin.ignore();
                        break;
                    }
                    grupBaru.statusAktif = statusAktifBaru;
                    cin.ignore();

                    daftarGrup[jumlahGrup++] = grupBaru;
                    cout << "Grup K-Pop berhasil ditambahkan!" << endl;
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
                    cout << "Nama Grup: ";
                    cout << daftarGrup[i].nama << endl;
                    cout << "Jumlah Anggota: " << daftarGrup[i].jumlahAnggota << endl;
                    cout << "Nama Anggota: ";
                    for (int j = 0; j < daftarGrup[i].jumlahAnggota; ++j) {
                        cout << daftarGrup[i].namaAnggota[j] << (j < daftarGrup[i].jumlahAnggota - 1 ? ", " : "");
                    }
                    cout << endl;
                    cout << "Nama Agensi: " << daftarGrup[i].namaAgensi << endl;
                    cout << "Tanggal Debut: " << daftarGrup[i].tanggalDebut << endl;
                    cout << "Nama Fandom: " << daftarGrup[i].namaFandom << endl;
                    cout << "Status: " << (daftarGrup[i].statusAktif ? "Aktif" : "Tidak Aktif") << endl;
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
                    if (daftarGrup[i].nama == grupUbah) {
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
                                getline(cin, daftarGrup[i].nama);
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
                                daftarGrup[i].jumlahAnggota = anggotaBaru;
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
                                        daftarGrup[i].namaAnggota[indexAnggota++] = anggota;
                                        anggota = "";
                                    } else {
                                        anggota += c;
                                    }
                                }
                                daftarGrup[i].namaAnggota[indexAnggota] = anggota;
                                cout << "Data grup K-Pop berhasil diubah!" << endl;
                                cout << "Tekan enter untuk melanjutkan..." << endl;
                                cin.ignore();
                                break;
                            }
                            case 4:
                                cout << "Nama Agensi Baru: ";
                                getline(cin, daftarGrup[i].namaAgensi);
                                cout << "Data grup K-Pop berhasil diubah!" << endl;
                                cout << "Tekan enter untuk melanjutkan..." << endl;
                                cin.ignore();
                                break;
                            case 5:
                                cout << "Tanggal Debut Baru: ";
                                getline(cin, daftarGrup[i].tanggalDebut);
                                cout << "Data grup K-Pop berhasil diubah!" << endl;
                                cout << "Tekan enter untuk melanjutkan..." << endl;
                                cin.ignore();
                                break;
                            case 6:
                                cout << "Nama Fandom Baru: ";
                                getline(cin, daftarGrup[i].namaFandom);
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
                                    cin.ignore();
                                    break;
                                }
                                daftarGrup[i].statusAktif = statusAktifBaru;
                                cout << "Data grup K-Pop berhasil diubah!" << endl;
                                cout << "Tekan enter untuk melanjutkan..." << endl;
                                cin.ignore();
                                cin.ignore();
                                break;
                            case 8:
                                cout << "Nama Grup Baru: ";
                                getline(cin, daftarGrup[i].nama);

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
                                daftarGrup[i].jumlahAnggota = anggotaBaru;
                                cin.ignore();

                                cout << "Nama Anggota Baru (pisahkan dengan koma): ";
                                getline(cin, anggotaInput);
                                indexAnggota = 0;
                                for (char c : anggotaInput) {
                                    if (c == ',') {
                                        daftarGrup[i].namaAnggota[indexAnggota++] = anggota;
                                        anggota = "";
                                    } else {
                                        anggota += c;
                                    }
                                }
                                daftarGrup[i].namaAnggota[indexAnggota] = anggota;

                                cout << "Nama Agensi Baru: ";
                                getline(cin, daftarGrup[i].namaAgensi);

                                cout << "Tanggal Debut Baru: ";
                                getline(cin, daftarGrup[i].tanggalDebut);

                                cout << "Nama Fandom Baru: ";
                                getline(cin, daftarGrup[i].namaFandom);

                                cout << "Status Aktif Baru (1: Aktif, 0: Tidak Aktif): ";
                                cin >> statusAktifBaru;
                                if (cin.fail() || (statusAktifBaru != 1 && statusAktifBaru != 0)) {
                                    cout << "Input tidak valid." << endl;
                                    cin.clear();
                                    cin.ignore();
                                    cout << "Tekan enter untuk melanjutkan..." << endl;
                                    cin.ignore();
                                    cin.ignore();
                                    cin.ignore();
                                    break;
                                }
                                daftarGrup[i].statusAktif = statusAktifBaru;
                                cout << "Data grup K-Pop berhasil diubah!" << endl;
                                cout << "Tekan enter untuk melanjutkan..." << endl;
                                cin.ignore();
                                cin.ignore();
                                break;
                            default:
                                cout << "Pilihan tidak valid." << endl;
                                cout << "Tekan enter untuk melanjutkan..." << endl;
                                cin.clear();
                                cin.ignore();
                                cin.ignore();
                                cin.ignore();
                        }
                        ditemukan = true;
                        break;
                    }
                }
            if (!ditemukan) {
                cout << "Grup K-Pop tidak ditemukan." << endl;
                cout << "Tekan enter untuk melanjutkan..." << endl;
                cin.clear();
                cin.ignore();
                break;
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
                if (daftarGrup[i].nama == grupHapus) {
                    for (int j = i; j < jumlahGrup - 1; ++j) {
                        daftarGrup[j] = daftarGrup[j + 1];
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
                loginSuccess = false;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
                cout << "Tekan enter untuk melanjutkan..." << endl;
                cin.clear();
                cin.ignore();
                cin.ignore();
                cin.ignore();
        }
    } while (pilihan != 5);

}

while (loginSuccess == true && level == "user") {
    int pilihan;
    system("cls");
    cout << "=== Menu User ===" << endl;
    cout << "1. Lihat Daftar Grup K-Pop" << endl;
    cout << "2. Keluar" << endl;
    cout << "Pilihan: ";
    cin >> pilihan;

    switch (pilihan) {
        case 1: {
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
                    cout << "Nama Grup: ";
                    cout << daftarGrup[i].nama << endl;
                    cout << "Jumlah Anggota: " << daftarGrup[i].jumlahAnggota << endl;
                    cout << "Nama Anggota: ";
                    for (int j = 0; j < daftarGrup[i].jumlahAnggota; ++j) {
                        cout << daftarGrup[i].namaAnggota[j] << (j < daftarGrup[i].jumlahAnggota - 1 ? ", " : "");
                    }
                    cout << endl;
                    cout << "Nama Agensi: " << daftarGrup[i].namaAgensi << endl;
                    cout << "Tanggal Debut: " << daftarGrup[i].tanggalDebut << endl;
                    cout << "Nama Fandom: " << daftarGrup[i].namaFandom << endl;
                    cout << "Status: " << (daftarGrup[i].statusAktif ? "Aktif" : "Tidak Aktif") << endl;
                    cout << string(50, '-') << endl;
                }
                cout << "Tekan enter untuk melanjutkan..." << endl;
                cin.ignore();
                cin.ignore();
                break;
            }
        case 2: {
            cout << "Terima kasih telah menggunakan program ini!" << endl;
                cout << "Tekan enter untuk melanjutkan..." << endl;
                cin.ignore();
                cin.ignore();
                loginSuccess = false;
                break;
        }
        default:
            cout << "Pilihan tidak valid." << endl;
            cout << "Tekan enter untuk melanjutkan..." << endl;
            cin.clear();
            cin.ignore();
            cin.ignore();
}

}
    system("cls");
    return 0;
}