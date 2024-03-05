#include <iostream>
#include <string>

using namespace std;

// Fungsi untuk konversi Kilometer/jam ke unit yang dipilih
float konversiKilometerPerJam(float nilai, int pilihan) {
    switch (pilihan) {
        case 1: // Kilometer/jam ke Centimeter/detik
            return nilai * 100000 / 3600;
        case 2: // Kilometer/jam ke Meter/detik
            return nilai * 1000 / 3600;
        case 3: // Kilometer/jam ke Mil/jam
            return nilai / 1.609;
        default:
            return 0;
    }
}

// Fungsi untuk konversi Centimeter/detik ke unit yang dipilih
float konversiCentimeterPerDetik(float nilai, int pilihan) {
    switch (pilihan) {
        case 1: // Centimeter/detik ke Kilometer/jam
            return nilai * 0.036;
        case 2: // Centimeter/detik ke Meter/detik
            return nilai / 100;
        case 3: // Centimeter/detik ke Mil/jam
            return nilai * 0.022;
        default:
            return 0;
    }
}

// Fungsi untuk konversi Meter/detik ke unit yang dipilih
float konversiMeterPerDetik(float nilai, int pilihan) {
    switch (pilihan) {
        case 1: // Meter/detik ke Kilometer/jam
            return nilai * 3.6;
        case 2: // Meter/detik ke Centimeter/detik
            return nilai * 100;
        case 3: // Meter/detik ke Mil/jam
            return nilai * 2.237;
        default:
            return 0;
    }
}

// Fungsi untuk konversi Mil/jam ke unit yang dipilih
float konversiMilPerJam(float nilai, int pilihan) {
    switch (pilihan) {
        case 1: // Mil/jam ke Kilometer/jam
            return nilai * 1.609;
        case 2: // Mil/jam ke Centimeter/detik
            return nilai * 44.704;
        case 3: // Mil/jam ke Meter/detik
            return nilai * 0.447;
        default:
            return 0;
    }
}

int main() {
    string nama, nim;
    int percobaan = 0;
    bool login = false;

    // Looping untuk login
    while (!login && percobaan < 3) {
        cout << "Nama : ";
        cin >> nama;
        cout << "NIM : ";
        cin >> nim;

        // Cek login
        if (nama == "asadin" && nim == "2309106061") {
            login = true;
            cout << "Login berhasil!\n";
        } else {
            percobaan++;
            cout << "Nama atau NIM yangb anda masukkan salah! Silakan coba lagi.\n";
        }
    }

    if (!login) {
        cout << "Anda telah gagal login sebanyak 3 kali. Program berhenti.\n";
        return 0;
    }

    int pilihanMenu;
    float nilai;
    char ulangi;

    do {
        cout << "Pilih menu konversi: \n";
        cout << "1. Kilometer/jam\n";
        cout << "2. Centimeter/detik\n";
        cout << "3. Meter/detik\n";
        cout << "4. Mil/jam\n";
        cout << "Pilihan Anda: ";
        cin >> pilihanMenu;

        cout << "Masukkan nilai: ";
        cin >> nilai;

        switch (pilihanMenu) {
            case 1: {
                int pilihan;
                cout << "------Pilih konversi------\n";
                cout << "1. Centimeter/detik\n"; 
                cout << "2. Meter/detik\n"; 
                cout << "3. Mil/jam\n";
                cout << "Pilihan Anda: ";
                cin >> pilihan;
                cout << "Hasil konversi: " << konversiKilometerPerJam(nilai, pilihan) << endl;
                break;
            }
            case 2: {
                int pilihan;
                cout << "------Pilih konversi------\n";
                cout << "1. Kilometer/jam\n"; 
                cout << "2. Meter/detik\n"; 
                cout << "3. Mil/jam\n";
                cout << "Pilihan Anda: ";
                cin >> pilihan;
                cout << "Hasil konversi: " << konversiCentimeterPerDetik(nilai, pilihan) << endl;
                break;
            }
            case 3: {
                int pilihan;
                cout << "------Pilih konversi------\n";
                cout << "1. Kilometer/jam\n"; 
                cout << "2. Centimeter/detik\n"; 
                cout << "3. Mil/jam\n";
                cout << "Pilihan Anda: ";
                cin >> pilihan;
                cout << "Hasil konversi: " << konversiMeterPerDetik(nilai, pilihan) << endl;
                break;
            }
            case 4: {
                int pilihan;
                cout << "------Pilih konversi------\n";
                cout << "1. Kilometer/jam\n"; 
                cout << "2. Centimeter/detik\n"; 
                cout << "3. Meter/detik\n";
                cout << "Pilihan Anda: ";
                cin >> pilihan;
                cout << "Hasil konversi: " << konversiMilPerJam(nilai, pilihan) << endl;
                break;
            }
            default:
                cout << "Pilihan tidak valid!";
        }

        cout << "Apakah Anda ingin melakukan konversi lagi? (y/n): ";
        cin >> ulangi;
    } while (ulangi == 'y' || ulangi == 'Y');

    cout << "Anda keluar dari program\n";

    return 0;
}