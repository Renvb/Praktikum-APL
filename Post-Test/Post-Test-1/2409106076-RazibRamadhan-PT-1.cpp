#include <iostream>
#include <string>

using namespace std;

int main() {
    string username = "Razib Ramadhan";
    string password = "2409106076";
    string inputUsername, inputPassword;
    int percobaan = 0;
    int pilihanMenu, pilihanSubMenu;
    double jumlah, hasil;

    // Login
    while (percobaan < 3) {
        cout << "Username: ";
        getline(cin, inputUsername);
        cout << "Password: ";
        getline(cin, inputPassword);

        if (inputUsername == username && inputPassword == password) {
            break;
        } else {
            percobaan++;
            cout << "Login gagal. Sisa percobaan: " << 3 - percobaan << endl;
        }
    }

    if (percobaan >= 3) {
        cout << "Login gagal 3 kali. Program berhenti." << endl;
        return 0;
    }

    // Menu Utama
    do {
        cout << "\nMenu Utama:" << endl;
        cout << "1. Konversi Mata Uang" << endl;
        cout << "2. Konversi Jarak" << endl;
        cout << "3. Konversi Waktu" << endl;
        cout << "4. Logout" << endl;
        cout << "Pilihan: ";
        cin >> pilihanMenu;

        if (pilihanMenu < 1 || pilihanMenu > 4) {
            cin.clear();
            cin.ignore();
            cout << "Input tidak valid. Silakan coba lagi. \n" << endl;
            continue;
        }

        switch (pilihanMenu) {
            case 1: // Konversi Mata Uang
                do {
                    cout << "\nKonversi Mata Uang:" << endl;
                    cout << "1. Rupiah ke Dolar AS" << endl;
                    cout << "2. Rupiah ke Euro" << endl;
                    cout << "3. Dolar AS ke Rupiah" << endl;
                    cout << "4. Dolar AS ke Euro" << endl;
                    cout << "5. Euro ke Rupiah" << endl;
                    cout << "6. Euro ke Dolar AS" << endl;
                    cout << "7. Kembali" << endl;
                    cout << "Pilihan: ";
                    cin >> pilihanSubMenu;

                    if (pilihanSubMenu < 1 || pilihanSubMenu > 7) {
                        cin.clear();
                        cin.ignore();
                        cout << "Input tidak valid. Silakan coba lagi. \n" << endl;
                        continue;
                    }

                    if (pilihanSubMenu >= 1 && pilihanSubMenu <= 6) {
                        cout << "Masukkan jumlah: ";
                        cin >> jumlah;

                        if (cin.fail()) {
                            cin.clear();
                            cin.ignore();
                            cout << "Input tidak valid. Silakan coba lagi. \n" << endl;
                            continue;
                        }

                        switch (pilihanSubMenu) {
                            case 1: // Rupiah ke Dolar AS
                                hasil = jumlah / 15000;
                                cout << jumlah << " Rupiah = " << hasil << " Dolar AS" << endl;
                                break;
                            case 2: // Rupiah ke Euro
                                hasil = jumlah / 16000;
                                cout << jumlah << " Rupiah = " << hasil << " Euro" << endl;
                                break;
                            case 3: // Dolar AS ke Rupiah
                                hasil = jumlah * 15000;
                                cout << jumlah << " Dolar AS = " << hasil << " Rupiah" << endl;
                                break;
                            case 4: // Dolar AS ke Euro
                                hasil = jumlah / 1.07;
                                cout << jumlah << " Dolar AS = " << hasil << " Euro" << endl;
                                break;
                            case 5: // Euro ke Rupiah
                                hasil = jumlah * 16000;
                                cout << jumlah << " Euro = " << hasil << " Rupiah" << endl;
                                break;
                            case 6: // Euro ke Dolar AS
                                hasil = jumlah * 1.07;
                                cout << jumlah << " Euro = " << hasil << " Dolar AS" << endl;
                                break;
                        }
                    } else if (pilihanSubMenu == 7) {
                        break;
                    } else {
                        cout << "Pilihan tidak valid.\n" << endl;
                    }
                } while (true);
                break;

            case 2: // Konversi Jarak
                do {
                    cout << "\nKonversi Jarak:" << endl;
                    cout << "1. Kilometer ke Meter" << endl;
                    cout << "2. Kilometer ke Centimeter" << endl;
                    cout << "3. Meter ke Kilometer" << endl;
                    cout << "4. Meter ke Centimeter" << endl;
                    cout << "5. Centimeter ke Kilometer" << endl;
                    cout << "6. Centimeter ke Meter" << endl;
                    cout << "7. Kembali" << endl;
                    cout << "Pilihan: ";
                    cin >> pilihanSubMenu;

                    if (pilihanSubMenu < 1 || pilihanSubMenu > 7) {
                        cin.clear();
                        cin.ignore();
                        cout << "Input tidak valid. Silakan coba lagi. \n" << endl;
                        continue;
                    }

                    if (pilihanSubMenu >= 1 && pilihanSubMenu <= 6) {
                        cout << "Masukkan jumlah: ";
                        cin >> jumlah;

                        if (cin.fail()) {
                            cin.clear();
                            cin.ignore();
                            cout << "Input tidak valid. Silakan coba lagi.\n" << endl;
                            continue;
                        }

                        switch (pilihanSubMenu) {
                            case 1: // Kilometer ke Meter
                                hasil = jumlah * 1000;
                                cout << jumlah << " Kilometer = " << hasil << " Meter" << endl;
                                break;
                            case 2: // Kilometer ke Centimeter
                                hasil = jumlah * 100000;
                                cout << jumlah << " Kilometer = " << hasil << " Centimeter" << endl;
                                break;
                            case 3: // Meter ke Kilometer
                                hasil = jumlah / 1000;
                                cout << jumlah << " Meter = " << hasil << " Kilometer" << endl;
                                break;
                            case 4: // Meter ke Centimeter
                                hasil = jumlah * 100;
                                cout << jumlah << " Meter = " << hasil << " Centimeter" << endl;
                                break;
                            case 5: // Centimeter ke Kilometer
                                hasil = jumlah / 100000;
                                cout << jumlah << " Centimeter = " << hasil << " Kilometer" << endl;
                                break;
                            case 6: // Centimeter ke Meter
                                hasil = jumlah / 100;
                                cout << jumlah << " Centimeter = " << hasil << " Meter" << endl;
                                break;
                        }
                    } else if (pilihanSubMenu == 7) {
                        break;
                    } else {
                        cout << "Pilihan tidak valid.\n" << endl;
                    }
                } while (true);
                break;

            case 3: // Konversi Waktu
                do {
                    cout << "\nKonversi Waktu:" << endl;
                    cout << "1. Jam ke Menit" << endl;
                    cout << "2. Jam ke Detik" << endl;
                    cout << "3. Menit ke Jam" << endl;
                    cout << "4. Menit ke Detik" << endl;
                    cout << "5. Detik ke Jam" << endl;
                    cout << "6. Detik ke Menit" << endl;
                    cout << "7. Kembali" << endl;
                    cout << "Pilihan: ";
                    cin >> pilihanSubMenu;

                    if (pilihanSubMenu < 1 || pilihanSubMenu > 7) {
                        cin.clear();
                        cin.ignore();
                        cout << "Input tidak valid. Silakan coba lagi. \n" << endl;
                        continue;
                    }

                    if (pilihanSubMenu >= 1 && pilihanSubMenu <= 6) {
                        cout << "Masukkan jumlah: ";
                        cin >> jumlah;

                        if (cin.fail()) {
                            cin.clear();
                            cin.ignore();
                            cout << "Input tidak valid. Silakan coba lagi.\n" << endl;
                            continue;
                        }

                        switch (pilihanSubMenu) {
                            case 1: // Jam ke Menit
                                hasil = jumlah * 60;
                                cout << jumlah << " Jam = " << hasil << " Menit" << endl;
                                break;
                            case 2: // Jam ke Detik
                                hasil = jumlah * 3600;
                                cout << jumlah << " Jam = " << hasil << " Detik" << endl;
                                break;
                            case 3: // Menit ke Jam
                                hasil = jumlah / 60;
                                cout << jumlah << " Menit = " << hasil << " Jam" << endl;
                                break;
                            case 4: // Menit ke Detik
                                hasil = jumlah * 60;
                                cout << jumlah << " Menit = " << hasil << " Detik" << endl;
                                break;
                            case 5: // Detik ke Jam
                                hasil = jumlah / 3600;
                                cout << jumlah << " Detik = " << hasil << " Jam" << endl;
                                break;
                            case 6: // Detik ke Menit
                                hasil = jumlah / 60;
                                cout << jumlah << " Detik = " << hasil << " Menit" << endl;
                                break;
                        }
                    } else if (pilihanSubMenu == 7) {
                        break;
                    } else {
                        cout << "Pilihan tidak valid.\n" << endl;
                    }
                } while (true);
                break;

            case 4: // Logout
                cout << "Logout berhasil.\n" << endl;
                return 0;

            default:
                cout << "Pilihan tidak valid.\n" << endl;
        }
    } while (true);

    return 0;
}