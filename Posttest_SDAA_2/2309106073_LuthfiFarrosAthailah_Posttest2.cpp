#include <iostream>
#include <string>

using namespace std;

const int MAX_LAPANGAN = 10;

struct Penyewaan {
    int id;
    string nama_penyewa;
    string tanggal;
    int durasi_jam;
    string lapangan;
};

void tampilkanPenyewaan(Penyewaan *penyewaan, int jumlah) {
    if (jumlah == 0) {
        cout << "Belum ada data penyewaan.\n";
    } else {
        for (int i = 0; i < jumlah; i++) {
            cout << "ID Penyewaan: " << penyewaan[i].id << endl;
            cout << "Nama Penyewa: " << penyewaan[i].nama_penyewa << endl;
            cout << "Tanggal: " << penyewaan[i].tanggal << endl;
            cout << "Durasi (Jam): " << penyewaan[i].durasi_jam << endl;
            cout << "Lapangan: " << penyewaan[i].lapangan << endl;
            cout << "------------------------\n";
        }
    }
}

void tambahPenyewaan(Penyewaan *penyewaan, int *jumlah) {
    if (*jumlah >= MAX_LAPANGAN) {
        cout << "Tidak dapat menambah penyewaan lagi, kapasitas penuh!\n";
        return;
    }

    Penyewaan baru;
    baru.id = *jumlah + 1;
    cout << "Masukkan nama penyewa: ";
    cin >> ws;
    getline(cin, baru.nama_penyewa);
    cout << "Masukkan tanggal (dd/mm/yyyy): ";
    cin >> ws;
    getline(cin, baru.tanggal);
    cout << "Masukkan durasi sewa (jam): ";
    cin >> baru.durasi_jam;
    cout << "Masukkan nama lapangan: ";
    cin >> ws;
    getline(cin, baru.lapangan);

    penyewaan[*jumlah] = baru;
    (*jumlah)++;

    cout << "Penyewaan berhasil ditambahkan.\n";
}

void ubahPenyewaan(Penyewaan *penyewaan, int jumlah) {
    if (jumlah == 0) {
        cout << "Belum ada data penyewaan untuk diubah.\n";
        return;
    }

    int id;
    cout << "Masukkan ID penyewaan yang ingin diubah: ";
    cin >> id;

    for (int i = 0; i < jumlah; i++) {
        if (penyewaan[i].id == id) {
            cout << "Masukkan nama penyewa baru: ";
            cin >> ws;
            getline(cin, penyewaan[i].nama_penyewa);
            cout << "Masukkan tanggal baru (dd/mm/yyyy): ";
            cin >> ws;
            getline(cin, penyewaan[i].tanggal);
            cout << "Masukkan durasi sewa baru (jam): ";
            cin >> penyewaan[i].durasi_jam;
            cout << "Masukkan nama lapangan baru: ";
            cin >> ws;
            getline(cin, penyewaan[i].lapangan);

            cout << "Data penyewaan berhasil diubah.\n";
            return;
        }
    }
    cout << "ID penyewaan tidak ditemukan.\n";
}

void hapusPenyewaan(Penyewaan *penyewaan, int *jumlah) {
    if (*jumlah == 0) {
        cout << "Belum ada data penyewaan untuk dihapus.\n";
        return;
    }

    int id;
    cout << "Masukkan ID penyewaan yang ingin dihapus: ";
    cin >> id;

    for (int i = 0; i < *jumlah; i++) {
        if (penyewaan[i].id == id) {
            for (int j = i; j < *jumlah - 1; j++) {
                penyewaan[j] = penyewaan[j + 1];
            }
            (*jumlah)--;
            cout << "Penyewaan berhasil dihapus.\n";
            return;
        }
    }
    cout << "ID penyewaan tidak ditemukan.\n";
}

int main() {
    Penyewaan penyewaan[MAX_LAPANGAN];
    int jumlah = 0;
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
                tampilkanPenyewaan(penyewaan, jumlah);
                break;
            case 2:
                tambahPenyewaan(penyewaan, &jumlah);
                break;
            case 3:
                ubahPenyewaan(penyewaan, jumlah);
                break;
            case 4:
                hapusPenyewaan(penyewaan, &jumlah);
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
