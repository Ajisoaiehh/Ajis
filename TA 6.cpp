#include <iostream>
using namespace std;

const int MAX = 10;

struct NodePasien {
    int id;
    NodePasien* next;

    NodePasien(int identitas, NodePasien* berikut = nullptr)
        : id(identitas), next(berikut) {}
};

NodePasien* hashTable[MAX];

void inisialisasi() {
    for (int i = 0; i < MAX; i++) {
        hashTable[i] = nullptr;
    }
}

int fungsiHash(int id) {
    return id % MAX;
}

void tambahPasien(int id) {
    int indeks = fungsiHash(id);
    NodePasien* baru = new NodePasien(id, hashTable[indeks]);
    hashTable[indeks] = baru;
    cout << "Pasien dengan ID " << id << " berhasil dimasukkan ke daftar.\n";
}

NodePasien* cariPasien(int id) {
    int indeks = fungsiHash(id);
    NodePasien* temp = hashTable[indeks];
    while (temp != nullptr) {
        if (temp->id == id)
            return temp;
        temp = temp->next;
    }
    return nullptr;
}

void hapusPasien(int id) {
    int indeks = fungsiHash(id);
    NodePasien* curr = hashTable[indeks];
    NodePasien* prev = nullptr;

    while (curr && curr->id != id) {
        prev = curr;
        curr = curr->next;
    }

    if (!curr) {
        cout << "Pasien dengan ID " << id << " tidak ditemukan.\n";
        return;
    }

    if (!prev)
        hashTable[indeks] = curr->next;
    else
        prev->next = curr->next;

    cout << "Pasien dengan ID " << id << " telah dihapus dari daftar.\n";
    delete curr;
}

void tampilkanPasien() {
    cout << "\n=== DAFTAR ANTRIAN PASIEN ===\n";
    for (int i = 0; i < MAX; i++) {
        cout << i << " : ";
        NodePasien* temp = hashTable[i];
        if (!temp)
            cout << "Kosong";
        while (temp) {
            cout << "[" << temp->id << "]";
            if (temp->next) cout << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }
}

int main() {
    inisialisasi();
    int pilihan;

    do {
        cout << "\n===== MENU UTAMA RUMAH SAKIT =====\n";
        cout << "1. Tambah Pasien\n";
        cout << "2. Cari Pasien\n";
        cout << "3. Hapus Pasien\n";
        cout << "4. Lihat Semua Pasien\n";
        cout << "0. Keluar\n";
        cout << "==================================\n";
        cout << "Masukkan pilihan: ";
        cin >> pilihan;

        if (pilihan == 1) {
            int id;
            cout << "Masukkan ID pasien: ";
            cin >> id;
            tambahPasien(id);
        } 
        else if (pilihan == 2) {
            int id;
            cout << "Masukkan ID pasien yang dicari: ";
            cin >> id;
            NodePasien* hasil = cariPasien(id);
            if (hasil)
                cout << "Pasien dengan ID " << hasil->id << " ditemukan.\n";
            else
                cout << "Pasien tidak ditemukan.\n";
        } 
        else if (pilihan == 3) {
            int id;
            cout << "Masukkan ID pasien yang akan dihapus: ";
            cin >> id;
            hapusPasien(id);
        } 
        else if (pilihan == 4) {
            tampilkanPasien();
        } 
        else if (pilihan == 0) {
            cout << "Terima kasih telah menggunakan sistem.\n";
        } 
        else {
            cout << "Pilihan tidak valid! Coba lagi.\n";
        }

    } while (pilihan != 0);

    return 0;
}
