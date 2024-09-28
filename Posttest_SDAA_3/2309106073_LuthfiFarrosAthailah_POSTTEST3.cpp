#include <iostream>
#include <string>

using namespace std;

struct Penyewaan {
    int id;
    string nama_penyewa;
    string tanggal;
    int durasi_jam;
    string lapangan;
    Penyewaan* next;
};

Penyewaan* head = nullptr;
int jumlah = 0;

void tampilkanPenyewaan() {
    if (head == nullptr) {
        cout << "Belum ada data penyewaan.\n";
        return;
    }
    
    Penyewaan* current = head;
    while (current != nullptr) {
        cout << "ID Penyewaan: " << current->id << endl;
        cout << "Nama Penyewa: " << current->nama_penyewa << endl;
        cout << "Tanggal: " << current->tanggal << endl;
        cout << "Durasi (Jam): " << current->durasi_jam << endl;
        cout << "Lapangan: " << current->lapangan << endl;
        cout << "------------------------\n";
        current = current->next;
    }
}

void tambahPenyewaan() {
    Penyewaan* baru = new Penyewaan;
    baru->id = jumlah + 1;
    cout << "Masukkan nama penyewa: ";
    cin >> ws;
    getline(cin, baru->nama_penyewa);
    cout << "Masukkan tanggal (dd/mm/yyyy): ";
    cin >> ws;
    getline(cin, baru->tanggal);
    
    // Validasi input durasi_jam agar tidak negatif
    do {
        cout << "Masukkan durasi sewa (jam): ";
        cin >> baru->durasi_jam;
        if (baru->durasi_jam <= 0) {
            cout << "Durasi sewa harus lebih dari 0.\n";
        }
    } while (baru->durasi_jam <= 0);

    cout << "Masukkan nama lapangan: ";
    cin >> ws;
    getline(cin, baru->lapangan);

    baru->next = nullptr;

    // Menambahkan penyewaan baru ke akhir linked list
    if (head == nullptr) {
        head = baru;
    } else {
        Penyewaan* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = baru;
    }

    jumlah++;
    cout << "Penyewaan berhasil ditambahkan.\n";
}

void ubahPenyewaan() {
    if (head == nullptr) {
        cout << "Belum ada data penyewaan untuk diubah.\n";
        return;
    }

    int id;
    cout << "Masukkan ID penyewaan yang ingin diubah: ";
    cin >> id;

    Penyewaan* current = head;
    while (current != nullptr) {
        if (current->id == id) {
            cout << "Masukkan nama penyewa baru: ";
            cin >> ws;
            getline(cin, current->nama_penyewa);
            cout << "Masukkan tanggal baru (dd/mm/yyyy): ";
            cin >> ws;
            getline(cin, current->tanggal);
            
            do {
                cout << "Masukkan durasi sewa baru (jam): ";
                cin >> current->durasi_jam;
                if (current->durasi_jam <= 0) {
                    cout << "Durasi sewa harus lebih dari 0.\n";
                }
            } while (current->durasi_jam <= 0);

            cout << "Masukkan nama lapangan baru: ";
            cin >> ws;
            getline(cin, current->lapangan);

            cout << "Data penyewaan berhasil diubah.\n";
            return;
        }
        current = current->next;
    }
    cout << "ID penyewaan tidak ditemukan.\n";
}

void hapusPenyewaan() {
    if (head == nullptr) {
        cout << "Belum ada data penyewaan untuk dihapus.\n";
        return;
    }

    int id;
    cout << "Masukkan ID penyewaan yang ingin dihapus: ";
    cin >> id;

    Penyewaan* current = head;
    Penyewaan* previous = nullptr;

    while (current != nullptr) {
        if (current->id == id) {
            if (previous == nullptr) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            delete current;
            jumlah--;
            cout << "Penyewaan berhasil dihapus.\n";
            return;
        }
        previous = current;
        current = current->next;
    }
    cout << "ID penyewaan tidak ditemukan.\n";
}

int main() {
    int pilihan;

    do {
        cout << "\nManajemen Penyewaan Lapangan Futsal\n";
        cout << "1. Tampilkan Data Penyewaan\n";
        cout << "2. Tambah Penyewaan\n";
        cout << "3. Ubah Penyewaan\n";
        cout << "4. Hapus Penyewaan\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tampilkanPenyewaan();
                break;
            case 2:
                tambahPenyewaan();
                break;
            case 3:
                ubahPenyewaan();
                break;
            case 4:
                hapusPenyewaan();
                break;
            case 5:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 5);

    return 0;
}

