#include <iostream>
using namespace std;

struct Sepatu {
    int id;
    Sepatu *kiri, *kanan;
};

Sepatu* buatNode(int idBaru) {
    Sepatu* nodeBaru = new Sepatu;
    nodeBaru->id = idBaru;
    nodeBaru->kiri = nodeBaru->kanan = nullptr;
    return nodeBaru;
}

Sepatu* tambahSepatu(Sepatu* rak, int idBaru) {
    if (rak == nullptr)
        return buatNode(idBaru);
    if (idBaru < rak->id)
        rak->kiri = tambahSepatu(rak->kiri, idBaru);
    else if (idBaru > rak->id)
        rak->kanan = tambahSepatu(rak->kanan, idBaru);
    return rak;
}

void tampilkanSepatu(Sepatu* rak) {
    if (!rak) return;
    tampilkanSepatu(rak->kiri);
    cout << rak->id << " ";
    tampilkanSepatu(rak->kanan);
}

bool cariSepatu(Sepatu* rak, int idCari) {
    if (!rak) return false;
    if (rak->id == idCari) return true;
    return (idCari < rak->id)
           ? cariSepatu(rak->kiri, idCari)
           : cariSepatu(rak->kanan, idCari);
}

Sepatu* sepatuTerkecil(Sepatu* rak) {
    if (!rak) return nullptr;
    while (rak->kiri)
        rak = rak->kiri;
    return rak;
}

Sepatu* sepatuTerbesar(Sepatu* rak) {
    if (!rak) return nullptr;
    while (rak->kanan)
        rak = rak->kanan;
    return rak;
}

int hitungSepatu(Sepatu* rak) {
    if (!rak) return 0;
    return 1 + hitungSepatu(rak->kiri) + hitungSepatu(rak->kanan);
}

int main() {
    Sepatu* rak = nullptr;
    int pilihan, id;

    do {
        cout << "\n=== SISTEM MANAJEMEN RAK SEPATU ===\n";
        cout << "1. Tambah Sepatu\n";
        cout << "2. Cari Sepatu\n";
        cout << "3. Lihat Semua Sepatu\n";
        cout << "4. Lihat Sepatu dengan ID Terkecil\n";
        cout << "5. Lihat Sepatu dengan ID Terbesar\n";
        cout << "6. Hitung Total Sepatu\n";
        cout << "7. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan ID sepatu: ";
                cin >> id;
                rak = tambahSepatu(rak, id);
                cout << "Sepatu berhasil ditambahkan!\n";
                break;
            case 2:
                cout << "Masukkan ID sepatu yang dicari: ";
                cin >> id;
                cout << (cariSepatu(rak, id) ? "Sepatu ditemukan!" : "Sepatu tidak ada!") << endl;
                break;
            case 3:
                cout << "Daftar ID Sepatu: ";
                tampilkanSepatu(rak);
                cout << endl;
                break;
            case 4:
                if (sepatuTerkecil(rak))
                    cout << "ID Sepatu Terkecil: " << sepatuTerkecil(rak)->id << endl;
                else
                    cout << "Rak masih kosong!\n";
                break;
            case 5:
                if (sepatuTerbesar(rak))
                    cout << "ID Sepatu Terbesar: " << sepatuTerbesar(rak)->id << endl;
                else
                    cout << "Rak masih kosong!\n";
                break;
            case 6:
                cout << "Jumlah Total Sepatu: " << hitungSepatu(rak) << endl;
                break;
            case 7:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }

    } while (pilihan != 7);

    return 0;
}
