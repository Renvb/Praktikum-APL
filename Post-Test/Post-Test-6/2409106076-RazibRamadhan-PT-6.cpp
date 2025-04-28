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

GrupKPop daftarGrup[MAX];
Pengguna daftarPengguna[MAX];
int jumlahGrup = 3;
int jumlahPengguna = 3;

void tambahGrup(GrupKPop &grupBaru, int &jumlahGrup) {
    if (jumlahGrup < MAX) {
        daftarGrup[jumlahGrup] = grupBaru;
        jumlahGrup++;
        cout << "Grup K-Pop berhasil ditambahkan!" << endl;
    } else {
        cout << "Jumlah grup maksimum telah tercapai." << endl;
    }
}

bool cariGrup(string* namaGrup, GrupKPop** hasilPencarian) {
    for (int i = 0; i < jumlahGrup; ++i) {
        if (daftarGrup[i].nama == *namaGrup) {
            *hasilPencarian = &daftarGrup[i];
            return true;
        }
    }
    return false;
}

void hapusGrup(string* namaGrup, bool* status) {
    *status = false;
    for (int i = 0; i < jumlahGrup; ++i) {
        if (daftarGrup[i].nama == *namaGrup) {
            for (int j = i; j < jumlahGrup - 1; ++j) {
                daftarGrup[j] = daftarGrup[j + 1];
            }
            jumlahGrup--;
            *status = true;
            cout << "Grup K-Pop berhasil dihapus!" << endl;
            break;
        }
    }
}

bool login(string* nama, string* password, string* level) {
    for (int i = 0; i < jumlahPengguna; i++) {
        if (daftarPengguna[i].nama == *nama && daftarPengguna[i].password == *password) {
            *level = daftarPengguna[i].peran;
            return true;
        }
    }
    return false;
}

bool tambahPengguna(Pengguna &penggunaBaru, int &jumlahPenggunaSekarang) {
    if (jumlahPenggunaSekarang >= MAX) {
        return false;
    }
    
    for (int i = 0; i < jumlahPenggunaSekarang; i++) {
        if (daftarPengguna[i].nama == penggunaBaru.nama) {
            return false;
        }
    }
    
    daftarPengguna[jumlahPenggunaSekarang] = penggunaBaru;
    jumlahPenggunaSekarang++;
    return true;
}

void inisialisasiData() {
    // Data grup K-Pop awal
    daftarGrup[0] = {"GFRIEND", 6, {"Sowon", "Yerin", "Eunha", "Yuju", "SinB", "Umji"}, "Source Music", "2015-01-16", "BUDDY", true};
    daftarGrup[1] = {"VIVIZ", 3, {"SinB", "Eunha", "Umji"}, "BPM Entertainment", "2022-02-09", "Na.V", true};
    daftarGrup[2] = {"The Wind", 6, {"Thanatorn", "Park Hayuchan", "Kim Heesoo", "Choi Hanbin", "An Chanwon", "Jang Hyounjoon"}, "With US Entertainment", "2023-05-15", "WHIZ", true};
    
    // Data pengguna awal
    daftarPengguna[0] = {"Razib Ramadhan", "2409106076", "admin"};
    daftarPengguna[1] = {"user", "user", "user"};
    daftarPengguna[2] = {"admin", "admin", "admin"};
}

void quitProgram() {
    cout << "Terima kasih telah menggunakan program ini!" << endl;
    cout << "Tekan enter untuk melanjutkan..." << endl;
    cin.ignore();
    return;
}

void defaultChoice() {
    cout << "Pilihan tidak valid." << endl;
    cout << "Tekan enter untuk melanjutkan..." << endl;
    cin.clear();
    cin.ignore();
    cin.ignore();
}

void pauseMenu() {
    cout << "Tekan enter untuk melanjutkan..." << endl;
    cin.ignore();
}

// Fungsi pivot quick sort
int partition(GrupKPop arr[], int low, int high) {
    string pivot = arr[high].nama;
    int i = (low - 1);
    
    for (int j = low; j <= high - 1; j++) {
        if (arr[j].nama > pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// Fungsi quick sort
void quickSortNamaDesc(GrupKPop arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSortNamaDesc(arr, low, pi - 1);
        quickSortNamaDesc(arr, pi + 1, high);
    }
}

// Fungsi insertion sort
void insertionSortJumlahAsc(GrupKPop arr[], int n) {
    for (int i = 1; i < n; i++) {
        GrupKPop key = arr[i];
        int j = i - 1;
        
        while (j >= 0 && arr[j].jumlahAnggota > key.jumlahAnggota) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Fungsi selection sort
void selectionSortJumlahDesc(GrupKPop arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int maxIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j].jumlahAnggota > arr[maxIdx].jumlahAnggota) {
                maxIdx = j;
            }
        }
        swap(arr[maxIdx], arr[i]);
    }
}

// Fungsi menyalin array
void salinArray(GrupKPop sumber[], GrupKPop tujuan[], int jumlah) {
    for (int i = 0; i < jumlah; i++) {
        tujuan[i] = sumber[i];
    }
}

void lihatGrup(int* jumlahGrupPtr) {
    system("cls");
    cout << "\n--- Daftar Grup K-Pop ---\n" << endl;
    
    if (*jumlahGrupPtr == 0) {
        cout << string(50, '-') << endl;
        cout << "Belum ada grup K-Pop yang ditambahkan." << endl;
        cout << string(50, '-') << endl;
        cout << "Tekan enter untuk melanjutkan..." << endl;
        cin.ignore();
        return;
    }
    
    cout << "Pilih metode sorting:" << endl;
    cout << "1. Urut berdasarkan nama grup (descending - quick sort)" << endl;
    cout << "2. Urut berdasarkan jumlah anggota (ascending - insertion sort)" << endl;
    cout << "3. Urut berdasarkan jumlah anggota (descending - selection sort)" << endl;
    cout << "Pilihan: ";
    
    int pilihan;
    cin >> pilihan;
    cin.ignore();

    system("cls");
    cout << "\n--- Daftar Grup K-Pop ---" << endl;
    
    // Membuat salinan array
    GrupKPop grupSorted[MAX];
    salinArray(daftarGrup, grupSorted, *jumlahGrupPtr);
    
    switch (pilihan) {
        case 1:
            cout << "\nHasil sorting berdasarkan nama grup (descending):" << endl;
            quickSortNamaDesc(grupSorted, 0, *jumlahGrupPtr - 1);
            break;
        case 2:
            cout << "\nHasil sorting berdasarkan jumlah anggota (ascending):" << endl;
            insertionSortJumlahAsc(grupSorted, *jumlahGrupPtr);
            break;
        case 3:
            cout << "\nHasil sorting berdasarkan jumlah anggota (descending):" << endl;
            selectionSortJumlahDesc(grupSorted, *jumlahGrupPtr);
            break;
        default:
            cout << "\nPilihan tidak valid. Menampilkan data tanpa pengurutan." << endl;
            salinArray(daftarGrup, grupSorted, *jumlahGrupPtr);
    }
    
    cout << string(50, '-') << endl;
    
    GrupKPop* grupPtr = grupSorted;
    for (int i = 0; i < *jumlahGrupPtr; ++i, ++grupPtr) {
        cout << "Nama Grup: ";
        cout << grupPtr->nama << endl;
        cout << "Jumlah Anggota: " << grupPtr->jumlahAnggota << endl;
        cout << "Nama Anggota: ";
        
        string* anggotaPtr = grupPtr->namaAnggota;
        for (int j = 0; j < grupPtr->jumlahAnggota; ++j, ++anggotaPtr) {
            cout << *anggotaPtr << (j < grupPtr->jumlahAnggota - 1 ? ", " : "");
        }
        
        cout << endl;
        cout << "Nama Agensi: " << grupPtr->namaAgensi << endl;
        cout << "Tanggal Debut: " << grupPtr->tanggalDebut << endl;
        cout << "Nama Fandom: " << grupPtr->namaFandom << endl;
        cout << "Status: " << (grupPtr->statusAktif ? "Aktif" : "Tidak Aktif") << endl;
        cout << string(50, '-') << endl;
    }
    
    cout << "Tekan enter untuk melanjutkan..." << endl;
    cin.ignore();
    return;
}

// Fungsi untuk menangani registrasi pengguna
void handleRegistrasi() {
    if (jumlahPengguna >= MAX) {
        system("cls");
        cout << "Pengguna sudah penuh. Registrasi gagal." << endl;
        pauseMenu();
        return;
    }
    
    system("cls");
    cout << "=== Registrasi Pengguna ===" << endl;
    string nama, password, peran = "user";
    cout << "Nama: ";
    getline(cin, nama);
    cout << "Password: ";
    getline(cin, password);
    
    Pengguna penggunaBaru = {nama, password, peran};
    if (tambahPengguna(penggunaBaru, jumlahPengguna)) {
        cout << "Registrasi berhasil!" << endl;
    } else {
        cout << "Nama pengguna sudah terdaftar atau database penuh. Registrasi gagal." << endl;
    }
    pauseMenu();
}

// Fungsi untuk menangani login pengguna
bool handleLogin(string* levelPtr) {
    int percobaan = 0;
    while (percobaan < 3) {
        system("cls");
        cout << "=== Login Pengguna ===" << endl;
        string nama, password;
        cout << "Masukkan Nama: ";
        getline(cin, nama);
        cout << "Masukkan Password: ";
        getline(cin, password);

        if (login(&nama, &password, levelPtr)) {
            cout << "Login berhasil!" << endl;
            pauseMenu();
            system("cls");
            return true;
        } else {
            percobaan++;
            cout << "Nama atau Password salah. Percobaan ke-" << percobaan << endl;
            pauseMenu();
        }
    }

    if (percobaan == 3) {
        cout << "Anda telah gagal 3 kali. Program berakhir." << endl;
        pauseMenu();
        system("cls");
    }
    return false;
}

int main() {
    inisialisasiData();
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
        
        switch (pilihan) {
            case 1:
                handleRegistrasi();
                break;
            case 2:
                loginSuccess = handleLogin(&level);
                break;
            case 3:
                quitProgram();
                system("cls");
                return 0;
            default:
                defaultChoice();
                break;
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

                        GrupKPop* hasilPtr = nullptr;
                        string namaGrup = grupBaru.nama;
                        if (cariGrup(&namaGrup, &hasilPtr)) {
                            cout << "Grup dengan nama tersebut sudah ada." << endl;
                            pauseMenu();
                            break;
                        }

                        int anggotaBaru;
                        cout << "Jumlah Anggota: ";
                        cin >> anggotaBaru;

                        if (cin.fail() || anggotaBaru <= 0 || anggotaBaru > 25) {
                            cout << "Input tidak valid." << endl;
                            cin.ignore();
                            cin.clear();
                            pauseMenu();
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
                            pauseMenu();
                            cin.ignore();
                            cin.ignore();
                            break;
                        }
                        grupBaru.statusAktif = statusAktifBaru;
                        cin.ignore();

                        tambahGrup(grupBaru, jumlahGrup);
                    } else {
                        cout << "Jumlah grup maksimum telah tercapai." << endl;
                        pauseMenu();
                        cin.ignore();
                    }
                    pauseMenu();
                    cin.ignore();
                    break;
                }
                case 2: {
                    lihatGrup(&jumlahGrup);
                    break;
                }
                case 3: {
                    system("cls");
                    string grupUbah;
                    cout << "\n--- Ubah Data Grup K-Pop ---" << endl;
                    cout << "Masukkan Nama Grup yang ingin diubah: ";
                    getline(cin, grupUbah);

                    GrupKPop* hasilPencarian = nullptr;
                    if (cariGrup(&grupUbah, &hasilPencarian)) {
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
                                getline(cin, hasilPencarian->nama);
                                cout << "Data grup K-Pop berhasil diubah!" << endl;
                                pauseMenu();
                                break;
                            case 2: {
                                int anggotaBaru;
                                cout << "Jumlah Anggota Baru: ";
                                cin >> anggotaBaru;

                                if (cin.fail() || anggotaBaru <= 0 || anggotaBaru > 25) {
                                    cout << "Input tidak valid." << endl;
                                    cin.ignore();
                                    cin.clear();
                                    pauseMenu();
                                    cin.ignore();
                                    cin.ignore();
                                    break;
                                }
                                hasilPencarian->jumlahAnggota = anggotaBaru;
                                cout << "Data grup K-Pop berhasil diubah!" << endl;
                                pauseMenu();
                                cin.ignore();
                                break;
                            }
                            case 3: {
                                cout << "Nama Anggota Baru (pisahkan dengan koma): ";
                                getline(cin, anggotaInput);
                                
                                int indexAnggota = 0;
                                for (char c : anggotaInput) {
                                    if (c == ',') {
                                        hasilPencarian->namaAnggota[indexAnggota++] = anggota;
                                        anggota = "";
                                    } else {
                                        anggota += c;
                                    }
                                }
                                hasilPencarian->namaAnggota[indexAnggota] = anggota;
                                cout << "Data grup K-Pop berhasil diubah!" << endl;
                                pauseMenu();
                                break;
                            }
                            case 4:
                                cout << "Nama Agensi Baru: ";
                                getline(cin, hasilPencarian->namaAgensi);
                                cout << "Data grup K-Pop berhasil diubah!" << endl;
                                pauseMenu();
                                break;
                            case 5:
                                cout << "Tanggal Debut Baru: ";
                                getline(cin, hasilPencarian->tanggalDebut);
                                cout << "Data grup K-Pop berhasil diubah!" << endl;
                                pauseMenu();
                                break;
                            case 6:
                                cout << "Nama Fandom Baru: ";
                                getline(cin, hasilPencarian->namaFandom);
                                cout << "Data grup K-Pop berhasil diubah!" << endl;
                                pauseMenu();
                                break;
                            case 7: {
                                bool statusAktifBaru;
                                cout << "Status Aktif Baru (1: Aktif, 0: Tidak Aktif): ";
                                cin >> statusAktifBaru;
                                if (cin.fail() || (statusAktifBaru != 1 && statusAktifBaru != 0)) {
                                    cout << "Input tidak valid." << endl;
                                    cin.clear();
                                    cin.ignore();
                                    pauseMenu();
                                    cin.ignore();
                                    cin.ignore();
                                    break;
                                }
                                hasilPencarian->statusAktif = statusAktifBaru;
                                cout << "Data grup K-Pop berhasil diubah!" << endl;
                                pauseMenu();
                                cin.ignore();
                                break;
                            }
                            case 8: {
                                cout << "Nama Grup Baru: ";
                                getline(cin, hasilPencarian->nama);

                                int anggotaBaru;
                                cout << "Jumlah Anggota Baru: ";
                                cin >> anggotaBaru;

                                if (cin.fail() || anggotaBaru <= 0 || anggotaBaru > 25) {
                                    cout << "Input tidak valid." << endl;
                                    cin.ignore();
                                    cin.clear();
                                    pauseMenu();
                                    cin.ignore();
                                    cin.ignore();
                                    break;
                                }
                                hasilPencarian->jumlahAnggota = anggotaBaru;
                                cin.ignore();

                                cout << "Nama Anggota Baru (pisahkan dengan koma): ";
                                getline(cin, anggotaInput);
                                
                                indexAnggota = 0;
                                for (char c : anggotaInput) {
                                    if (c == ',') {
                                        hasilPencarian->namaAnggota[indexAnggota++] = anggota;
                                        anggota = "";
                                    } else {
                                        anggota += c;
                                    }
                                }
                                hasilPencarian->namaAnggota[indexAnggota] = anggota;

                                cout << "Nama Agensi Baru: ";
                                getline(cin, hasilPencarian->namaAgensi);

                                cout << "Tanggal Debut Baru: ";
                                getline(cin, hasilPencarian->tanggalDebut);

                                cout << "Nama Fandom Baru: ";
                                getline(cin, hasilPencarian->namaFandom);

                                bool statusAktifBaru;
                                cout << "Status Aktif Baru (1: Aktif, 0: Tidak Aktif): ";
                                cin >> statusAktifBaru;
                                if (cin.fail() || (statusAktifBaru != 1 && statusAktifBaru != 0)) {
                                    cout << "Input tidak valid." << endl;
                                    cin.clear();
                                    cin.ignore();
                                    pauseMenu();
                                    cin.ignore();
                                    cin.ignore();
                                    break;
                                }
                                hasilPencarian->statusAktif = statusAktifBaru;
                                cout << "Data grup K-Pop berhasil diubah!" << endl;
                                pauseMenu();
                                cin.ignore();
                                break;
                            }
                            default:
                                defaultChoice();
                                cin.ignore();
                        }
                    } else {
                        cout << "Grup K-Pop tidak ditemukan." << endl;
                        cout << "Tekan enter untuk melanjutkan..." << endl;
                        cin.clear();
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

                    hapusGrup(&grupHapus, &ditemukan);
                    
                    if (!ditemukan) {
                        cout << "Grup tidak ditemukan" << endl;
                        pauseMenu();
                    } else {
                        pauseMenu();
                    }
                    break;
                }
                case 5:
                    quitProgram();
                    loginSuccess = false;
                    system("cls");
                    return 0;
                default:
                    defaultChoice();
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
                lihatGrup(&jumlahGrup);
                cin.ignore();
                break;
            }
            case 2: {
                quitProgram();
                cin.ignore();
                loginSuccess = false;
                system("cls");
                return 0;
            }
            default:
                defaultChoice();
                cin.ignore();
        }
    }
    system("cls");
    return 0;
}