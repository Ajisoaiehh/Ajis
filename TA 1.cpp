#include <iostream>
#include <string>
using namespace std;
struct Pasien {
    string nama;
    string keluhan;
    Pasien* next;

    Pasien(string n, string k) {
        nama = n;
        keluhan = k;
        next = nullptr;
    }
};
class AntrianRumahSakit {
private:
    Pasien* head;
    Pasien* tail;

public:
    AntrianRumahSakit() {
        head = nullptr;
        tail = nullptr;
    }
    void tambahPasien(string nama, string keluhan) {
        Pasien* pasienBaru = new Pasien(nama, keluhan);
        if (tail == nullptr) {
            head = tail = pasienBaru;
        } else {
            tail->next = pasienBaru;
            tail = pasienBaru;
        }
        cout << "Pasien '" << nama << "' dengan keluhan '" << keluhan << "' telah ditambahkan ke antrian." << endl;
    }
    void panggilPasien() {
        if (head == nullptr) {
            cout << "Antrian kosong. Tidak ada pasien untuk dipanggil." << endl;
            return;
        }

        Pasien* pasienDipanggil = head;
        cout << "\nMemanggil pasien: '" << pasienDipanggil->nama << "' dengan keluhan '" << pasienDipanggil->keluhan << "'." << endl;
        
        head = head->next;
        if (head == nullptr) {
            tail = nullptr;
        }
        delete pasienDipanggil;
    }
    void tampilkanAntrian() {
        if (head == nullptr) {
            cout << "\nAntrian kosong." << endl;
            return;
        }

        Pasien* current = head;
        cout << "\nDaftar Antrian Saat Ini:" << endl;
        int nomor = 1;
        while (current != nullptr) {
            cout << nomor << ". Nama: " << current->nama << ", Keluhan: " << current->keluhan << endl;
            current = current->next;
            nomor++;
        }
    }
    ~AntrianRumahSakit() {
        Pasien* current = head;
        while (current != nullptr) {
            Pasien* nextPasien = current->next;
            delete current;
            current = nextPasien;
        }
    }
};
void tampilkanMenu() {
    cout << "\n--- Sistem Antrian Rumah Sakit ---" << endl;
    cout << "1. Tambah Pasien Baru" << endl;
    cout << "2. Panggil Pasien Berikutnya" << endl;
    cout << "3. Tampilkan Seluruh Antrian" << endl;
    cout << "4. Keluar" << endl;
    cout << "Masukkan pilihan Anda: ";
}

int main() {
    AntrianRumahSakit antrian;
    int pilihan;
    string nama, keluhan;

    do {
        tampilkanMenu();
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1:
                cout << "Masukkan nama pasien: ";
                getline(cin, nama);
                cout << "Masukkan keluhan: ";
                getline(cin, keluhan);
                antrian.tambahPasien(nama, keluhan);
                break;
            case 2:
                antrian.panggilPasien();
                break;
            case 3:
                antrian.tampilkanAntrian();
                break;
            case 4:
                cout << "Terima kasih telah menggunakan layanan ini." << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while (pilihan != 4);

    return 0;
}