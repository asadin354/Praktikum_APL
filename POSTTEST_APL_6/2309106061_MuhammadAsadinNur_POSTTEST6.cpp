#include <iostream>
#include <string>
#include <limits>
#include <algorithm> // Untuk penggunaan fungsi sorting
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
         << "5. Cari Data HP\n"
         << "6. Urutkan Data HP\n"
         << "7. Keluar\n";
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

    cout << "Data HP yang tersedia:\n";
    for (int i = 0; i < jumlahData; i++) {
        cout << "Merk: " << data[i].merk << endl;
        cout << "RAM: " << data[i].ram << "GB" << endl;
        cout << "Penyimpanan: " << data[i].penyimpanan << "GB" << endl;
        cout << "Lama Penggunaan: " << data[i].tambahan.lama_penggunaan << endl;
        cout << "Keterangan Tambahan: " << data[i].tambahan.minus_hp << endl;
        cout << "-------------------------" << endl;
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
        } catch (const invalid_argument &e) {
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

void cariBerdasarkanNama(HandphoneSecond *data, int jumlahData) {
    if (jumlahData == 0) {
        cout << "Tidak ada data HP yang tersedia." << endl;
        return;
    }

    cout << "Masukkan Merk HP yang ingin dicari: ";
    string keyword;
    cin.ignore();
    getline(cin, keyword);

    bool ditemukan = false;
    for (int i = 0; i < jumlahData; ++i) {
        if (data[i].merk.find(keyword) != string::npos) {
            cout << "Data HP ditemukan:\n";
            cout << "Merk: " << data[i].merk << endl;
            cout << "RAM: " << data[i].ram << "GB" << endl;
            cout << "Penyimpanan: " << data[i].penyimpanan << "GB" << endl;
            cout << "Lama Penggunaan: " << data[i].tambahan.lama_penggunaan << endl;
            cout << "Keterangan Tambahan: " << data[i].tambahan.minus_hp << endl;
            ditemukan = true;
        }
    }

    if (!ditemukan) {
        cout << "Data HP tidak ditemukan." << endl;
    }
}

void cariBerdasarkanPenyimpanan(HandphoneSecond *data, int jumlahData) {
    if (jumlahData == 0) {
        cout << "Tidak ada data HP yang tersedia." << endl;
        return;
    }

    cout << "Masukkan Penyimpanan HP yang ingin dicari: ";
    int target;
    cin >> target;

    // Proses pencarian dengan binary search
    int low = 0, high = jumlahData - 1;
    bool ditemukan = false;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (data[mid].penyimpanan == target) {
            cout << "Data HP ditemukan:\n";
            cout << "Merk: " << data[mid].merk << endl;
            cout << "RAM: " << data[mid].ram << "GB" << endl;
            cout << "Penyimpanan: " << data[mid].penyimpanan << "GB" << endl;
            cout << "Lama Penggunaan: " << data[mid].tambahan.lama_penggunaan << endl;
            cout << "Keterangan Tambahan: " << data[mid].tambahan.minus_hp << endl;
            ditemukan = true;
            break;
        } else if (data[mid].penyimpanan < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (!ditemukan) {
        cout << "Data HP tidak ditemukan." << endl;
    }
}

void cariData(HandphoneSecond *data, int jumlahData) {
    while (true) {
        cout << "Menu Pencarian Data:\n";
        cout << "1. Berdasarkan Nama (Sequential Search)\n";
        cout << "2. Berdasarkan Penyimpanan (Binary Search)\n";
        cout << "3. Kembali ke Menu Utama\n";
        cout << "Masukkan pilihan : ";
        int pilihan;
        cin >> pilihan;

        switch (pilihan) {
        case 1:
            cariBerdasarkanNama(data, jumlahData);
            break;
        case 2:
            cariBerdasarkanPenyimpanan(data, jumlahData);
            break;
        case 3:
            return;
        default:
            cout << "Pilihan tidak valid." << endl;
        }
    }
}

void selectionSortMerk(HandphoneSecond *data, int jumlahData) {
    for (int i = 0; i < jumlahData - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < jumlahData; j++) {
            if (data[j].merk < data[min_idx].merk) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            swap(data[i], data[min_idx]);
        }
    }
    cout << "Data HP berhasil diurutkan berdasarkan merk menggunakan Selection Sort." << endl;
}

void bubbleSortPenyimpanan(HandphoneSecond *data, int jumlahData) {
    for (int i = 0; i < jumlahData - 1; i++) {
        for (int j = 0; j < jumlahData - i - 1; j++) {
            if (data[j].penyimpanan < data[j + 1].penyimpanan) { // Ubah tanda perbandingan menjadi '<'
                swap(data[j], data[j + 1]);
            }
        }
    }
    cout << "Data HP berhasil diurutkan berdasarkan penyimpanan secara descending menggunakan Bubble Sort." << endl;
}

int partitionRAM(HandphoneSecond *data, int low, int high) {
    int pivot = data[high].ram;
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (data[j].ram < pivot) {
            i++;
            swap(data[i], data[j]);
        }
    }
    swap(data[i + 1], data[high]);
    return (i + 1);
}

void quickSortRAM(HandphoneSecond *data, int low, int high) {
    if (low < high) {
        int pi = partitionRAM(data, low, high);
        quickSortRAM(data, low, pi - 1);
        quickSortRAM(data, pi + 1, high);
    }
}

void urutkanData(HandphoneSecond *data, int jumlahData) {
    if (jumlahData == 0) {
        cout << "Tidak ada data HP yang tersedia." << endl;
        return;
    }

    while (true) {
        cout << "Menu Pengurutan Data:\n";
        cout << "1. Berdasarkan Nama (Selection Sort)\n";
        cout << "2. Berdasarkan Penyimpanan (Bubble Sort)\n";
        cout << "3. Berdasarkan RAM (Quick Sort)\n";
        cout << "4. Kembali ke Menu Utama\n";
        cout << "Masukkan pilihan : ";
        int pilihan;
        cin >> pilihan;

        switch (pilihan) {
        case 1:
            selectionSortMerk(data, jumlahData);
            tampilkanData(data, jumlahData); 
            break;
        case 2:
            bubbleSortPenyimpanan(data, jumlahData);
            tampilkanData(data, jumlahData); 
            break;
        case 3:
            quickSortRAM(data, 0, jumlahData - 1);
            cout << "Data HP berhasil diurutkan berdasarkan RAM secara ascending menggunakan Quick Sort." << endl;
            tampilkanData(data, jumlahData); 
            break;
        case 4:
            return;
        default:
            cout << "Pilihan tidak valid." << endl;
        }
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
            cariData(data, jumlahData);
        } else if (menu == 6) {
            urutkanData(data, jumlahData);
        } else if (menu == 7) {
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
