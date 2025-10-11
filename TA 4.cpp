#include <iostream>

using namespace std;

const int MAX_SIZE = 5;

class AgeQueue {
private:
    int ages[MAX_SIZE];
    int front = 0;
    int rear = -1;
    int count = 0;

public:
    void enqueue(int age) {
        if (count == MAX_SIZE) {
            cout << "Queue Penuh! Tidak dapat menambahkan umur " << age << "." << endl;
            return;
        }
        rear = (rear + 1) % MAX_SIZE;
        ages[rear] = age;
        count++;
        cout << "Enqueue: Umur " << age << " ditambahkan." << endl;
    }

    void dequeue() {
        if (count == 0) {
            cout << "Queue Kosong! Tidak ada umur yang dihapus." << endl;
            return;
        }
        int removedAge = ages[front];
        front = (front + 1) % MAX_SIZE;
        count--;
        cout << "Dequeue: Umur " << removedAge << " dihapus." << endl;
    }

    int peek() {
        if (count == 0) {
            return -1;
        }
        return ages[front];
    }

    void displayQueue() {
        if (count == 0) {
            cout << "Queue saat ini kosong." << endl;
            return;
        }

        cout << "Isi Queue Umur (" << count << "/" << MAX_SIZE << "): ";
        int current = front;
        for (int i = 0; i < count; ++i) {
            cout << ages[current] << (i < count - 1 ? " tahun, " : " tahun");
            current = (current + 1) % MAX_SIZE;
        }
        cout << endl;
    }
};

int main() {
    AgeQueue q;
    int choice;
    int ageInput;

    do {
        cout << "      MENU QUEUE INPUT UMUR        " << endl;
        cout << "1. Enqueue (Masukkan Umur)" << endl;
        cout << "2. Dequeue (Hapus Umur Depan)" << endl;
        cout << "3. Peek (Lihat Umur Depan)" << endl;
        cout << "4. Tampilkan Semua Umur" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih operasi (0-4): ";

        if (!(cin >> choice)) {
            cout << "Input tidak valid. Silakan masukkan angka." << endl;
            cin.clear();
            cin.ignore(256, '\n');
            continue;
        }

        switch (choice) {
            case 1:
                cout << "Masukkan umur (integer) untuk di-Enqueue: ";
                if (cin >> ageInput) {
                    q.enqueue(ageInput);
                } else {
                    cout << "Input umur tidak valid!" << endl;
                    cin.clear();
                    cin.ignore(256, '\n');
                }
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                {
                    int frontAge = q.peek();
                    if (frontAge != -1) {
                         cout << "Umur Terdepan (Peek): " << frontAge << endl;
                    } else {
                         cout << "Queue Kosong! Tidak ada umur di depan." << endl;
                    }
                }
                break;
            case 4:
                q.displayQueue();
                break;
            case 0:
                cout << "Program selesai. Terima kasih!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while (choice != 0);

    return 0;
}