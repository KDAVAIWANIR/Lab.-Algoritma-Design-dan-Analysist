#include <iostream>
#include <string>
using namespace std;

// Node untuk linked list
struct Node {
    string nama;     // Menyimpan nama
    int angka;       // Menyimpan angka
    Node* next;      // Pointer ke node selanjutnya
};

// Queue dengan maksimal 3 elemen
class Queue {
private:
    Node* front;           // Pointer ke elemen depan queue
    Node* rear;            // Pointer ke elemen belakang queue
    int size;              // Jumlah elemen dalam queue
    const int MAX_SIZE;    // Maksimal kapasitas queue

public:
    Queue() : front(NULL), rear(NULL), size(0), MAX_SIZE(3) {}

    // Tambah elemen ke queue
    void enqueue(string nama, int angka) {
        if (size == MAX_SIZE) {
            cout << "Queue penuh. Tidak bisa enqueue.\n";
            return;
        }

        Node* newNode = new Node;   // Buat node baru
        newNode->nama = nama;      // Simpan nama
        newNode->angka = angka;    // Simpan angka
        newNode->next = NULL;      // Node baru tidak menunjuk ke apa-apa

        if (rear == NULL) {
            front = rear = newNode; // Jika kosong, front dan rear sama
        } else {
            rear->next = newNode;   // Tambahkan ke belakang
            rear = newNode;         // Update rear
        }

        size++;
        cout << "Enqueued: " << nama << " - " << angka << endl;
    }

    // Hapus elemen dari queue
    void dequeue() {
        if (front == NULL) {
            cout << "Queue kosong. Tidak bisa dequeue.\n";
            return;
        }

        Node* temp = front;
        cout << "Dequeued: " << temp->nama << " - " << temp->angka << endl;

        front = front->next;
        if (front == NULL)
            rear = NULL;

        delete temp;
        size--;
    }

    // Tampilkan isi queue
    void display() {
        if (front == NULL) {
            cout << "Queue kosong.\n";
            return;
        }

        cout << "Isi Queue:\n";
        Node* temp = front;
        while (temp != NULL) {
            cout << "- " << temp->nama << " : " << temp->angka << endl;
            temp = temp->next;
        }
    }

    // Destructor untuk membersihkan memori
    ~Queue() {
        while (front != NULL) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }
};

// Fungsi utama (menu)
int main() {
    Queue q;
    int choice;
    string nama;
    int angka;

    do {
        cout << "\nMenu:\n";
        cout << "1. Enqueue (Tambah Data)\n";
        cout << "2. Dequeue (Hapus Data)\n";
        cout << "3. Tampilkan Queue\n";
        cout << "0. Keluar\n";
        cout << "Pilihan: ";
        cin >> choice;

        cin.ignore(); // Menghindari masalah newline setelah cin

        switch (choice) {
            case 1:
                cout << "Masukkan nama: ";
                getline(cin, nama);
                cout << "Masukkan angka: ";
                cin >> angka;
                q.enqueue(nama, angka);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.display();
                break;
            case 0:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }

    } while (choice != 0);

    return 0;
}

