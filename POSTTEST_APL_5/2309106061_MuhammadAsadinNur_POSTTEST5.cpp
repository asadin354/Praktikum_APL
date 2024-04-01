#include <iostream>
#include <string>
#include <limits> 
using namespace std;

struct KeteranganTambahan {
    string lama_penggunaan; 
    string minus_hp;        
};

struct HandphoneSecond {
    string merk;            
    int ram;                
    int penyimpanan;        
    KeteranganTambahan tambahan; 
};

bool dataValid(int idx, int jumlahData) {
    return (idx >= 0 && idx < jumlahData);
}

void tampilkanMenu() {
    cout << "-----MENU-----\n"
         << "1. Tambah Data HP\n"
         << "2. Tampilkan Data\n"
         << "3. Hapus Data HP\n"
         << "4. Edit Data HP\n"
         << "5. Keluar\n";
    cout << "Masukkan pilihan : ";
}

void tambahData(HandphoneSecond *data, int &jumlahData, int maksimal_data) {
    if (jumlahData < maksimal_data) {
        cout << "Tambah Data HP\n";
        cout << "Masukkan Merk HP (tekan spasi terlebih dahulu) : ";
        cin.ignore(); 
        getline(cin, data[jumlahData].merk);
        
        cout << "Masukkan RAM (GB): ";
        while (!(cin >> data[jumlahData].ram)) {
            cout << "Input tidak valid. Masukkan angka: ";
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        
        cout << "Masukkan Penyimpanan (GB): ";
        while (!(cin >> data[jumlahData].penyimpanan)) {
            cout << "Input tidak valid. Masukkan angka: ";
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        }
        
        cout << "Masukkan Lama Penggunaan: ";
        cin.ignore(); 
        getline(cin, data[jumlahData].tambahan.lama_penggunaan);
        
        cout << "Masukkan Keterangan Minus HP: ";
        getline(cin, data[jumlahData].tambahan.minus_hp);
        
        jumlahData++;
    } else {
        cout << "Data sudah mencapai batas maksimum." << endl;
    }
}

void tampilkanData(HandphoneSecond *data, int jumlahData) {
    if (jumlahData == 0) {
        cout << "Tidak ada data HP yang tersedia." << endl;
        return;
    }
    
    cout << "Merk HP yang tersedia:\n";
    for (int i = 0; i < jumlahData; i++) {
        cout << i + 1 << ". " << data[i].merk << endl;
    }

    cout << "Pilih nomor merk untuk menampilkan data lebih lengkap ('exit' untuk kembali): ";
    string pilihan;
    cin >> pilihan;

    if (pilihan == "exit") {
        return;
    }

    int nomorMerk;
    try {
        nomorMerk = stoi(pilihan);
    } catch (const invalid_argument& e) {
        cout << "Input tidak valid. Harap masukkan nomor merk yang benar." << endl;
        return;
    }
    
    if (nomorMerk >= 1 && nomorMerk <= jumlahData) {
        cout << "Data HP untuk merk " << data[nomorMerk - 1].merk << ":\n";
        cout << "Merk: " << data[nomorMerk - 1].merk << endl;
        cout << "RAM: " << data[nomorMerk - 1].ram << "GB" << endl;
        cout << "Penyimpanan: " << data[nomorMerk - 1].penyimpanan << "GB" << endl;
        cout << "Lama Penggunaan: " << data[nomorMerk - 1].tambahan.lama_penggunaan << endl;
        cout << "Keterangan Tambahan: " << data[nomorMerk - 1].tambahan.minus_hp << endl;
    } else {
        cout << "Nomor merk tidak valid." << endl;
    }
}

void hapusData(HandphoneSecond *data, int &jumlahData) {
    cout << "Hapus Data HP\n";
    if (jumlahData > 0) {
        cout << "Merk HP yang tersedia:\n";
        for (int i = 0; i < jumlahData; i++) {
            cout << i + 1 << ". " << data[i].merk << endl;
        }

        cout << "Pilih nomor merk untuk menghapus data: ";
        int pilihan;
        cin >> pilihan;

        if (pilihan >= 1 && pilihan <= jumlahData) {
            for (int i = pilihan - 1; i < jumlahData - 1; i++) {
                data[i] = data[i + 1];
            }
            jumlahData--;
            cout << "Data HP berhasil dihapus." << endl;
        } else {
            cout << "Nomor merk tidak valid." << endl;
        }
    } else {
        cout << "Tidak ada data yang tersedia untuk dihapus." << endl;
    }
}

void editData(HandphoneSecond *data, int jumlahData) {
    cout << "Edit Data HP\n";
    if (jumlahData > 0) {
        cout << "Merk HP yang tersedia:\n";
        for (int i = 0; i < jumlahData; i++) {
            cout << i + 1 << ". " << data[i].merk << endl;
        }

        cout << "Pilih nomor merk untuk mengedit data ('exit' untuk kembali): ";
        string pilihan;
        cin >> pilihan;

        if (pilihan == "exit") {
            return;
        }

        int nomorMerk;
        try {
            nomorMerk = stoi(pilihan);
        } catch (const invalid_argument& e) {
            cout << "Input tidak valid. Harap masukkan nomor merk yang benar." << endl;
            return;
        }
        
        if (nomorMerk >= 1 && nomorMerk <= jumlahData) {
            cout << "Masukkan Merk HP baru (tekan spasi terlebih dahulu) : ";
            cin.ignore();
            getline(cin, data[nomorMerk - 1].merk);
            
            cout << "Masukkan RAM (GB) baru : ";
            while (!(cin >> data[nomorMerk - 1].ram)) {
                cout << "Input tidak valid. Masukkan angka: ";
                cin.clear(); 
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            }
            
            cout << "Masukkan Penyimpanan (GB) baru : ";
            while (!(cin >> data[nomorMerk - 1].penyimpanan)) {
                cout << "Input tidak valid. Masukkan angka: ";
                cin.clear(); 
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            
            cout << "Masukkan Lama Penggunaan baru : ";
            cin.ignore(); 
            getline(cin, data[nomorMerk - 1].tambahan.lama_penggunaan);
            
            cout << "Masukkan Keterangan Minus HP baru : ";
            getline(cin, data[nomorMerk - 1].tambahan.minus_hp);
            
            cout << "Data HP berhasil diubah." << endl;
        } else {
            cout << "Nomor merk tidak valid." << endl;
        }
    } else {
        cout << "Tidak ada data yang tersedia untuk diedit." << endl;
    }
}

bool ulangiProgram() {
    string ulang;
    cout << "Apakah anda ingin mengulang? (y/n)";
    cin >> ulang;
    cin.ignore();
    while (ulang != "y" && ulang != "n") {
        cout << "Input tidak valid. Masukkan 'y' untuk ya atau 'n' untuk tidak." << endl;
        cin >> ulang;
    }
    return (ulang == "y");
}

bool login() {
    string nama, nim;
    int percobaan = 0;

    while (percobaan < 3) {
        cout << " Silahkan login terlebih dahulu.\n";
        cout << "Masukkan Nama : ";
        cin >> nama;
        cout << "Masukkan NIM : ";
        cin >> nim;

        if (nama == "asadin" && nim == "2309106061") {
            cout << "Login berhasil!\n";
            return true;
        } else {
            percobaan++;
            cout << "Nama atau NIM yang Anda masukkan salah! Silakan coba lagi.\n";
        }
    }

    cout << "Anda telah gagal login sebanyak 3 kali. Program berhenti.\n";
    return false;
}

void jalankanProgram() {
    if (!login()) {
        return;
    }

    const int maksimal_data = 10;
    HandphoneSecond *data = new HandphoneSecond[maksimal_data];
    int jumlahData = 0;
    
    while (true) {
        tampilkanMenu();
        int menu;
        cin >> menu;
        cin.ignore();

        if (menu == 1) {
            tambahData(data, jumlahData, maksimal_data);
        } else if (menu == 2) {
            tampilkanData(data, jumlahData);
        } else if (menu == 3) {
            hapusData(data, jumlahData);
        } else if (menu == 4) {
            editData(data, jumlahData);
        } else if (menu == 5) {
            break;
        } else {
            cout << "Error: Pilihan tidak valid.\n";
        }

        if (!ulangiProgram())
            break;
    }

    delete[] data; 
}

int main() {
    jalankanProgram();
    return 0;
}
