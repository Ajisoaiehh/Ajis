#include <iostream>
#include <string>
using namespace std;
const int UKURAN_MAKSIMUM = 10; 

int main() {
    string daftarBelanja[UKURAN_MAKSIMUM];
    int jumlahItem;
    cout << "PROGRAM INPUT DAFTAR BELANJA" << endl;
    cout << "Berapa banyak item yang akan Anda beli (maksimal " << UKURAN_MAKSIMUM << ")? ";
    cin >> jumlahItem; 

    if (jumlahItem <= 0 || jumlahItem > UKURAN_MAKSIMUM) {
        cout << "Jumlah item tidak valid. Program dihentikan." << endl;
        return 1;
    }
    cin.ignore(); 
    cout << "\nSILAKAN INPUT NAMA BARANG\n";
    for (int i = 0; i < jumlahItem; ++i) {
        cout << "Item ke-" << (i + 1) << ": ";
        getline(cin, daftarBelanja[i]); 
    }

    cout << "  DAFTAR BELANJA YANG TERSIMPAN" << endl;
    
    for (int i = 0; i < jumlahItem; ++i) {
        cout << (i + 1) << ". " << daftarBelanja[i] << endl;
    }
    cout << "Data berhasil tersimpan dalam array 1D.\n";

    return 0;
}