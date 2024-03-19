#include <iostream>
#include <vector>
using namespace std;

bool dataValid(int idx, int jumlahData) {
    return (idx >= 1 && idx <= jumlahData);
}

void tampilkanMenu() {
    cout << "-----MENU-----\n"
         << "1. Tambah Data HP\n"
         << "2. Ubah Data HP\n"
         << "3. Lihat Data HP\n"
         << "4. Hapus Data HP\n";
    cout << "Masukkan pilihan : ";
}

void tambahData(vector<string> &data, int maksimal_data) {
    if (data.size() < maksimal_data) {
        cout << "Tambah Data HP\n";
        cout << "Masukkan Merk HP : ";
        string merk;
        cin.ignore();
        getline(cin, merk);
        data.push_back(merk);
    } else {
        cout << "Data sudah mencapai batas maksimum." << endl;
    }
}

void ubahData(vector<string> &data) {
    cout << "Ubah Data HP\n";
    cout << "Masukkan urutan data : ";
    int idx;
    cin >> idx;
    cin.ignore(); // Membersihkan karakter newline dari buffer
    if (dataValid(idx, data.size())) {
        cout << "Masukkan Merk baru : ";
        string merk;
        getline(cin, merk);
        data[idx - 1] = merk;
    } else {
        cout << "Nomor data tidak valid." << endl;
    }
}

bool ulangiProgram() {
    string ulang;
    cout << "Apakah anda ingin mengulang? (y/n)";
    cin >> ulang;
    while (ulang != "y" && ulang != "n") {
        cout << "Input tidak valid. Masukkan 'y' untuk ya atau 'n' untuk tidak." << endl;
        cin >> ulang;
    }
    return (ulang == "y");
}

void jalankanProgram() {
    const int maksimal_data = 10;
    vector<string> data;
    
    while (true) {
        tampilkanMenu();
        int menu;
        cin >> menu;
        cin.ignore();

        if (menu == 1) {
            tambahData(data, maksimal_data);
        } else if (menu == 2) {
            ubahData(data);
        } else if (menu == 3) {
            cout << "Tampilkan data HP : \n";
            for (int i = 0; i < data.size(); i++) {
                cout << "Data Ke-" << i + 1 << " " << data[i] << endl;
            }
            cout << "----------\n";
        } else if (menu == 4) {
            cout << "Hapus data : \n";
            cout << "Masukkan nomor data yang ingin dihapus : ";
            int idx;
            cin >> idx;
            if (dataValid(idx, data.size())) {
                data.erase(data.begin() + idx - 1);
            } else {
                cout << "Nomor data tidak valid." << endl;
            }
        } else {
            cout << "Error: Pilihan tidak valid.\n";
        }

        if (!ulangiProgram())
            break;
    }
}

int main() {
    string nama, nim;
    int percobaan = 0;
    bool login = false;

    while (!login && percobaan < 3) {
        cout << " Silahkan login terlebih dahulu.\n";
        cout << "Masukkan Nama : ";
        getline(cin, nama);
        cout << "Masukkan NIM : ";
        getline(cin, nim);

        if (nama == "asadin" && nim == "2309106061") {
            login = true;
            cout << "Login berhasil!\n";
        } else {
            percobaan++;
            cout << "Nama atau NIM yang anda masukkan salah! Silakan coba lagi.\n";
        }
    }

    if (!login) {
        cout << "Anda telah gagal login sebanyak 3 kali. Program berhenti.\n";
        return 0;
    }

    jalankanProgram();

    return 0;
}
