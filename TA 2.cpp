#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;

struct Lagu {
    string judul;
};

void cetakDaftarLagu(const vector<Lagu>& daftar) {
    if (daftar.empty()) {
        cout << "(Daftar lagu kosong.)\n";
        return;
    }
    cout << "No. | Judul Lagu\n";
    cout << string(30, '-') << "\n";
    for (size_t i = 0; i < daftar.size(); ++i) {
        cout << setw(3) << i + 1 << " | " << daftar[i].judul << "\n";
    }
}

void insertLagu(vector<Lagu>& daftar, const Lagu& laguBaru) {
    Lagu kunci = laguBaru;
    int j = daftar.size() - 1;
    
    daftar.push_back(Lagu()); 
    
    while (j >= 0 && daftar[j].judul > kunci.judul) {
        daftar[j + 1] = daftar[j];
        j = j - 1;
    }
    
    daftar[j + 1] = kunci;
}

int main() {
    vector<Lagu> playlist;
    int pilihan;
    
    cout << "== PENGATUR DAFTAR PUTAR (Insertion Sort - Alfabetis) ==\n";
    
    do {
        cout << "\n----------------------------------------\n";
        cout << "1. Masukkan Lagu Baru\n";
        cout << "2. Tampilkan Daftar Putar Terurut\n";
        cout << "3. Keluar\n";
        cout << "Pilih menu (1-3): ";
        cin >> pilihan;
        cin.ignore();
        
        if (pilihan == 1) {
            Lagu laguBaru;
            
            cout << "\n--- Masukkan Data Lagu ---\n";
            cout << "Judul: ";
            getline(cin, laguBaru.judul); 
            
            insertLagu(playlist, laguBaru);
            
            cout << "\n[BERHASIL] Lagu '" << laguBaru.judul << "' disisipkan ke daftar putar.\n";
            
        } else if (pilihan == 2) {
            cout << "\n== DAFTAR PUTAR TERURUT (Berdasarkan Judul A-Z) ==\n";
            cetakDaftarLagu(playlist);
            
        } else if (pilihan == 3) {
            cout << "Terima kasih telah menggunakan program pengatur daftar putar. Sampai jumpa!\n";
        } else {
            cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }
        
    } while (pilihan != 3);
    
    return 0;
}