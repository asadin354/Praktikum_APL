#include <iostream>
using namespace std;

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

    const int maximal_data = 10;
    string data[maximal_data];
    int count = 0;
    string repeat = "y";

    while(repeat == "y"){
        cout << "-----MENU-----\n"
             << "1. Tambah Data HP\n"
             << "2. Ubah Data HP\n"
             << "3. Lihat Data HP\n"
             << "4. Hapus Data HP\n";
        cout<< "Masukkan pilihan : ";
        int menu;
        cin >> menu;

        cin.ignore();

        if(menu == 1){
            if(count < maximal_data){
                cout << "Tambah Data HP\n";
                cout << "Masukkan Merk HP : ";
                cin.ignore();
                getline(cin, data[count]);
                count++;
            } else {
                cout << "Data sudah mencapai batas maksimum." << endl;
            }
        }
        else if (menu == 2){
            cout << "Ubah Data HP\n";
            cout << "Masukkan urutan data : ";
            int idx;
            cin >> idx;
            cin.ignore();
            if(idx >= 1 && idx <= count){
                cout << "Masukkan Merk baru : ";
                getline(cin, data[idx-1]);
            } else {
                cout << "Nomor data tidak valid." << endl;
            }
        }
        else if (menu == 3){
            cout << "Tampilkan data HP : \n";
            for(int i = 0 ; i < count; i++){
                cout << "Data Ke-" << i+1 << " " << data[i] << endl;
                cout << "----------\n";
            }
        }
        else if (menu == 4){
            cout << "Hapus data : \n";
            cout << "Masukkan nomor data yang ingin dihapus : ";
            int idx;
            cin >> idx;
            if(idx >= 1 && idx <= count){
                for(int i = idx - 1; i < count - 1; i++){
                    data[i] = data[i+1];
                }
                count--;
            } else {
                cout << "Nomor data tidak valid." << endl;
            }
        }
        else {
            cout << "Error: Pilihan tidak valid.\n";
        }

        cout << "Apakah anda ingin mengulang? (y/n)";
        cin >> repeat;
        if (repeat != "y"){
            break;
        } 
    }
    return 0;
}
 