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
int jumlah_penyewaan = 0;

// Fungsi untuk menampilkan data penyewaan
void tampilkanPenyewaan() {
    if (head == nullptr) {
        cout << "Belum ada data penyewaan.\n";
        return;
    }
    
    Penyewaan* penyewaan_sekarang = head;
    while (penyewaan_sekarang != nullptr) {
        cout << "ID Penyewaan: " << penyewaan_sekarang->id << endl;
        cout << "Nama Penyewa: " << penyewaan_sekarang->nama_penyewa << endl;
        cout << "Tanggal: " << penyewaan_sekarang->tanggal << endl;
        cout << "Durasi (Jam): " << penyewaan_sekarang->durasi_jam << endl;
        cout << "Lapangan: " << penyewaan_sekarang->lapangan << endl;
        cout << "------------------------\n";
        penyewaan_sekarang = penyewaan_sekarang->next;
    }
}

// Fungsi untuk menambah penyewaan baru
void tambahPenyewaan() {
    Penyewaan* penyewaan_baru = new Penyewaan;
    penyewaan_baru->id = jumlah_penyewaan + 1;
    cout << "Masukkan nama penyewa: ";
    cin >> ws;
    getline(cin, penyewaan_baru->nama_penyewa);
    cout << "Masukkan tanggal (dd/mm/yyyy): ";
    cin >> ws;
    getline(cin, penyewaan_baru->tanggal);
    
    // Validasi input durasi sewa agar tidak negatif atau nol
    do {
        cout << "Masukkan durasi sewa (jam): ";
        cin >> penyewaan_baru->durasi_jam;
        if (penyewaan_baru->durasi_jam <= 0) {
            cout << "Durasi sewa harus lebih dari 0.\n";
        }
    } while (penyewaan_baru->durasi_jam <= 0);

    cout << "Masukkan nama lapangan: ";
    cin >> ws;
    getline(cin, penyewaan_baru->lapangan);

    penyewaan_baru->next = nullptr;

    // Menambahkan penyewaan baru ke dalam linked list
    if (head == nullptr) {
        head = penyewaan_baru;
    } else {
        Penyewaan* penyewaan_sekarang = head;
        while (penyewaan_sekarang->next != nullptr) {
            penyewaan_sekarang = penyewaan_sekarang->next;
        }
        penyewaan_sekarang->next = penyewaan_baru;
    }

    jumlah_penyewaan++;
    cout << "Penyewaan berhasil ditambahkan.\n";
}

// Fungsi untuk mengubah data penyewaan
void ubahPenyewaan() {
    if (head == nullptr) {
        cout << "Belum ada data penyewaan untuk diubah.\n";
        return;
    }

    int id_penyewaan;
    cout << "Masukkan ID penyewaan yang ingin diubah: ";
    cin >> id_penyewaan;

    Penyewaan* penyewaan_sekarang = head;
    while (penyewaan_sekarang != nullptr) {
        if (penyewaan_sekarang->id == id_penyewaan) {
            cout << "Masukkan nama penyewa baru: ";
            cin >> ws;
            getline(cin, penyewaan_sekarang->nama_penyewa);
            cout << "Masukkan tanggal baru (dd/mm/yyyy): ";
            cin >> ws;
            getline(cin, penyewaan_sekarang->tanggal);
            
            do {
                cout << "Masukkan durasi sewa baru (jam): ";
                cin >> penyewaan_sekarang->durasi_jam;
                if (penyewaan_sekarang->durasi_jam <= 0) {
                    cout << "Durasi sewa harus lebih dari 0.\n";
                }
            } while (penyewaan_sekarang->durasi_jam <= 0);

            cout << "Masukkan nama lapangan baru: ";
            cin >> ws;
            getline(cin, penyewaan_sekarang->lapangan);

            cout << "Data penyewaan berhasil diubah.\n";
            return;
        }
        penyewaan_sekarang = penyewaan_sekarang->next;
    }
    cout << "ID penyewaan tidak ditemukan.\n";
}

// Fungsi untuk menghapus penyewaan
void hapusPenyewaan() {
    if (head == nullptr) {
        cout << "Belum ada data penyewaan untuk dihapus.\n";
        return;
    }

    int id_penyewaan;
    cout << "Masukkan ID penyewaan yang ingin dihapus: ";
    cin >> id_penyewaan;

    Penyewaan* penyewaan_sekarang = head;
    Penyewaan* penyewaan_sebelumnya = nullptr;

    while (penyewaan_sekarang != nullptr) {
        if (penyewaan_sekarang->id == id_penyewaan) {
            if (penyewaan_sebelumnya == nullptr) {
                head = penyewaan_sekarang->next;
            } else {
                penyewaan_sebelumnya->next = penyewaan_sekarang->next;
            }
            delete penyewaan_sekarang;
            jumlah_penyewaan--;
            cout << "Penyewaan berhasil dihapus.\n";
            return;
        }
        penyewaan_sebelumnya = penyewaan_sekarang;
        penyewaan_sekarang = penyewaan_sekarang->next;
    }
    cout << "ID penyewaan tidak ditemukan.\n";
}

int main() {
    int pilihan_menu;

    do {
        cout << "\nManajemen Penyewaan Lapangan Futsal\n";
        cout << "1. Tampilkan Data Penyewaan\n";
        cout << "2. Tambah Penyewaan\n";
        cout << "3. Ubah Penyewaan\n";
        cout << "4. Hapus Penyewaan\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan_menu;

        switch (pilihan_menu) {
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
    } while (pilihan_menu != 5);

    return 0;
}
