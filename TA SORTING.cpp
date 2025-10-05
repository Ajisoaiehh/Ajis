#include <iostream>
using namespace std;

void swap(int* xp, int* yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }
        
        if (swapped == false)
            break;
    }
}

void printAges(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " tahun ";
        if (i < size - 1) {
            cout << "| ";
        }
    }
    cout << endl;
}

int main() {
    int n;

    cout << "PROGRAM PENGURUTAN UMUR" << endl;
    cout << "Masukkan jumlah orang: ";
    cin >> n;

    int* ages = new int[n]; 

    cout << "\nMasukkan data umur:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> ages[i];
    }
    bubbleSort(ages, n);

    cout << "\nUrutan umur: " << endl;
    printAges(ages, n);
    
    return 0;
}