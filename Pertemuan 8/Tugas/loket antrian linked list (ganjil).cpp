#include <iostream>
#include <string>
using namespace std;

// Node dari linked list
struct Node {
    string nama;
    Node* next;
};

// Queue dengan linked list
class AntrianLoket {
private:
    Node* depan;
    Node* belakang;

public:
    AntrianLoket() {
        depan = NULL;
        belakang = NULL;
    }

    // Menambahkan orang ke antrian
    void enqueue(string nama) {
        Node* baru = new Node();
        baru->nama = nama;
        baru->next = NULL;

        if (belakang == NULL) {
            depan = belakang = baru;
        } else {
            belakang->next = baru;
            belakang = baru;
        }

        cout << nama << " telah masuk ke dalam antrian." << endl;
    }

    // Melayani orang di depan antrian
    void dequeue() {
        if (depan == NULL) {
            cout << "Antrian kosong, tidak ada yang bisa dilayani." << endl;
            return;
        }

        Node* temp = depan;
        cout << temp->nama << " telah dilayani dan keluar dari antrian." << endl;
        depan = depan->next;

        if (depan == NULL)
            belakang = NULL;

        delete temp;
    }

    // Menampilkan isi antrian
    void tampilkanAntrian() {
        if (depan == NULL) {
            cout << "Antrian kosong." << endl;
            return;
        }

        cout << "Daftar antrian saat ini:" << endl;
        Node* temp = depan;
        int posisi = 1;
        while (temp != NULL) {
            cout << posisi << ". " << temp->nama << endl;
            temp = temp->next;
            posisi++;
        }
    }

    // Destructor untuk membersihkan memori
    ~AntrianLoket() {
        while (depan != NULL) {
            Node* temp = depan;
            depan = depan->next;
            delete temp;
        }
    }
};

// Program utama
int main() {
    AntrianLoket loket;
    int pilihan;
    string nama;

    do {
        cout << "\n=== Sistem Antrian Loket Tiket ===" << endl;
        cout << "1. Tambah Antrian" << endl;
        cout << "2. Layani Antrian" << endl;
        cout << "3. Lihat Antrian" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilihan Anda: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan nama: ";
                cin >> nama;
                loket.enqueue(nama);
                break;
            case 2:
                loket.dequeue();
                break;
            case 3:
                loket.tampilkanAntrian();
                break;
            case 4:
                cout << "Terima kasih. Program selesai." << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
        }
    } while (pilihan != 4);

    return 0;
}

