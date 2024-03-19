#include <iostream>
using namespace std;

// Fungsi untuk memeriksa apakah nomor data yang dimasukkan pengguna valid
bool dataValid(int idx, int jumlahData) {
    return (idx >= 1 && idx <= jumlahData);
}

// Fungsi untuk menampilkan menu
void tampilkanMenu() {
    cout << "-----MENU-----\n"
         << "1. Tambah Data HP\n"
         << "2. Ubah Data HP\n"
         << "3. Lihat Data HP\n"
         << "4. Hapus Data HP\n";
    cout<< "Masukkan pilihan : ";
}

// Prosedur untuk menambahkan data HP
void tambahData(string data[], int &jumlahData, int maksimal_data) {
    if(jumlahData < maksimal_data){
        cout << "Tambah Data HP\n";
        cout << "Masukkan Merk HP : ";
        cin.ignore();
        getline(cin, data[jumlahData]);
        jumlahData++;
    } else {
        cout << "Data sudah mencapai batas maksimum." << endl;
    }
}

// Prosedur untuk mengubah data HP
void ubahData(string data[], int jumlahData) {
    cout << "Ubah Data HP\n";
    cout << "Masukkan urutan data : ";
    int idx;
    cin >> idx;
    cin.ignore();
    if(dataValid(idx, jumlahData)){
        cout << "Masukkan Merk baru : ";
        getline(cin, data[idx-1]);
    } else {
        cout << "Nomor data tidak valid." << endl;
    }
}

// Rekursif: Fungsi untuk memeriksa apakah pengguna ingin mengulangi program
bool ulangiProgram() {
    string ulang;
    cout << "Apakah anda ingin mengulang? (y/n)";
    cin >> ulang;
    if (ulang == "y")
        return true;
    else if (ulang == "n")
        return false;
    else {
        cout << "Input tidak valid. Masukkan 'y' untuk ya atau 'n' untuk tidak." << endl;
        return ulangiProgram();
    }
}

// Rekursif: Fungsi utama untuk menjalankan program
void jalankanProgram() {
    const int maksimal_data = 10;
    string data[maksimal_data];
    int jumlahData = 0;

    tampilkanMenu(); // Menampilkan menu
    int menu;
    cin >> menu;
    cin.ignore();

    if (menu == 1) {
        tambahData(data, jumlahData, maksimal_data); // Menambahkan data
        cin.ignore(); // Membersihkan buffer keyboard sebelum memasukkan string
    } else if (menu == 2) {
        ubahData(data, jumlahData); // Mengubah data
    } else if (menu == 3) {
        // Menampilkan data HP
        cout << "Tampilkan data HP : \n";
        for(int i = 0 ; i < jumlahData; i++){
            cout << "Data Ke-" << i+1 << " " << data[i] << endl;
            cout << "----------\n";
        }
    } else if (menu == 4) {
        // Menghapus data
        cout << "Hapus data : \n";
        cout << "Masukkan nomor data yang ingin dihapus : ";
        int idx;
        cin >> idx;
        if(dataValid(idx, jumlahData)){
            for(int i = idx - 1; i < jumlahData - 1; i++){
                data[i] = data[i+1];
            }
            jumlahData--;
        } else {
            cout << "Nomor data tidak valid." << endl;
        }
    } else {
        cout << "Error: Pilihan tidak valid.\n";
    }

    if (ulangiProgram()) // Rekursif: Memeriksa apakah pengguna ingin mengulangi program
        jalankanProgram(); // Rekursif: Menjalankan program kembali jika pengguna ingin mengulang
}

int main(){
    string nama, nim;
    int percobaan = 0;
    bool login = false;

    // Looping untuk login
    while (!login && percobaan < 3) {
        cout << " Silahkan login terlebih dahulu.\n";
        cout << "Masukkan Nama : ";
        cin >> nama;
        cout << "Masukkan NIM : ";
        cin >> nim;

        // Cek login
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

    jalankanProgram(); // Memanggil fungsi utama untuk menjalankan program

    return 0;
}
