#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int target);
int main() {
    int nomorKamar[] = {101, 105, 112, 201, 205, 301, 310, 315};
    int n = sizeof(nomorKamar) / sizeof(nomorKamar[0]);
    int kamarDicari; 

    cout << "Daftar Nomor Kamar yang Tersedia: ";
    for (int i = 0; i < n; ++i) {
        cout << nomorKamar[i] << " ";
    }
    cout << endl;
    cout << "Masukkan nomor kamar yang ingin Anda cari: ";
    cin >> kamarDicari;

    int hasil = binarySearch(nomorKamar, n, kamarDicari);
    if (hasil != -1) {
        cout << "Nomor kamar " << kamarDicari 
             << " ditemukan pada posisi (indeks) ke-" << hasil << " dalam daftar." << endl;
    } else {
        cout << "Nomor kamar " << kamarDicari << " tidak ditemukan." << endl;
    }
    return 0;
}

int binarySearch(int arr[], int n, int target) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2; 

        if (arr[mid] == target) {
            return mid;
        } 
        
        if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}