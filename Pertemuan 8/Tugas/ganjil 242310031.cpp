#include <iostream> // Mengimpor library untuk input dan output standar (cin, cout)
using namespace std; // Menggunakan namespace standar agar tidak perlu menulis std:: di setiap penggunaan

// Node untuk linked list
struct Node {
    int data;      // Menyimpan data dari node
    Node* next;    // Menyimpan alamat node berikutnya (pointer ke node selanjutnya)
};

// Queue dengan maksimal 3 elemen
class Queue {
private:
    Node* front;         // Pointer ke elemen pertama dalam queue (antrian)
    Node* rear;          // Pointer ke elemen terakhir dalam queue
    int size;            // Menyimpan jumlah elemen saat ini dalam queue
    const int MAX_SIZE;  // Batas maksimal elemen dalam queue (konstanta)

public:
    Queue() : front(NULL), rear(NULL), size(0), MAX_SIZE(3) {} // Konstruktor: inisialisasi semua pointer ke NULL dan ukuran ke 0

    // Fungsi untuk menambahkan elemen ke queue
    void enqueue(int value) {
        if (size == MAX_SIZE) { // Jika queue sudah penuh
            cout << "Queue penuh. Tidak bisa enqueue.\n";
            return;
        }

        Node* newNode = new Node;   // Membuat node baru secara dinamis
        newNode->data = value;      // Mengisi data node dengan nilai yang diberikan
        newNode->next = NULL;       // Node baru menunjuk ke NULL (belum ada node setelahnya)

        if (rear == NULL) {         // Jika queue kosong (rear NULL)
            front = rear = newNode; // Node baru menjadi front dan rear
        } else {
            rear->next = newNode;   // Sambungkan node baru di akhir queue
            rear = newNode;         // Update rear ke node yang baru
        }

        size++;                     // Tambahkan ukuran queue
        cout << "Enqueued: " << value << endl; // Tampilkan pesan berhasil enqueue
    }

    // Fungsi untuk menghapus elemen dari queue
    void dequeue() {
        if (front == NULL) { // Jika queue kosong
            cout << "Queue kosong. Tidak bisa dequeue.\n";
            return;
        }

        Node* temp = front;           // Simpan pointer ke node paling depan
        cout << "Dequeued: " << temp->data << endl; // Tampilkan nilai yang akan dihapus

        front = front->next;          // Pindahkan front ke node berikutnya
        if (front == NULL)           // Jika setelah dequeue, queue jadi kosong
            rear = NULL;             // Maka rear juga di-set ke NULL

        delete temp;                 // Hapus node lama dari memori
        size--;                      // Kurangi ukuran queue
    }

    // Fungsi untuk menampilkan isi queue
    void display() {
        if (front == NULL) { // Jika queue kosong
            cout << "Queue kosong.\n";
            return;
        }

        cout << "Isi Queue: ";
        Node* temp = front;          // Mulai dari front
        while (temp != NULL) {       // Selama belum mencapai akhir (NULL)
            cout << temp->data << " -> "; // Tampilkan data
            temp = temp->next;            // Pindah ke node berikutnya
        }
        cout << "NULL\n";            // Akhir dari queue
    }

    // Destructor: membersihkan semua node saat objek Queue dihancurkan
    ~Queue() {
        while (front != NULL) {      // Selama masih ada node
            Node* temp = front;      // Simpan node yang akan dihapus
            front = front->next;     // Pindah ke node berikutnya
            delete temp;             // Hapus node
        }
    }
};

// Fungsi utama: menu interaktif
int main() {
    Queue q;                     // Membuat objek queue
    int choice, value;           // Variabel untuk pilihan menu dan nilai input

    do {
        // Tampilkan menu
        cout << "\nMenu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Tampilkan Queue\n";
        cout << "0. Keluar\n";
        cout << "Pilihan: ";
        cin >> choice;           // Input pilihan menu dari user

        // Proses pilihan user
        switch (choice) {
            case 1: // Enqueue
                cout << "Masukkan nilai: ";
                cin >> value;
                q.enqueue(value); // Panggil fungsi enqueue
                break;
            case 2: // Dequeue
                q.dequeue();      // Panggil fungsi dequeue
                break;
            case 3: // Tampilkan isi queue
                q.display();      // Panggil fungsi display
                break;
            case 0: // Keluar
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n"; // Jika pilihan tidak sesuai
        }

    } while (choice != 0); // Ulangi selama pilihan bukan 0

    return 0; // Program selesai
}

