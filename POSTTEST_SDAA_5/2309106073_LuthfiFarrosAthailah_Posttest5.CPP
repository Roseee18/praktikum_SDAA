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

// Fungsi untuk membagi linked list menjadi dua bagian
Penyewaan* mergeSortSplit(Penyewaan* head) {
    Penyewaan* fast = head->next;
    Penyewaan* slow = head;
    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
    }
    Penyewaan* temp = slow->next;
    slow->next = nullptr;
    return temp;
}

// Fungsi untuk menggabungkan dua linked list secara ascending
Penyewaan* mergeAscending(Penyewaan* left, Penyewaan* right) {
    if (!left) return right;
    if (!right) return left;
    
    if (left->id < right->id) {
        left->next = mergeAscending(left->next, right);
        return left;
    } else {
        right->next = mergeAscending(left, right->next);
        return right;
    }
}

// Fungsi utama Merge Sort untuk ascending
Penyewaan* mergeSortAscending(Penyewaan* head) {
    if (!head || !head->next) return head;
    Penyewaan* right = mergeSortSplit(head);
    Penyewaan* left = head;
    
    left = mergeSortAscending(left);
    right = mergeSortAscending(right);
    
    return mergeAscending(left, right);
}

// Fungsi untuk memisahkan bagian quicksort
Penyewaan* partitionDescending(Penyewaan* head, Penyewaan** left, Penyewaan** right) {
    Penyewaan* pivot = head;
    Penyewaan* penyewaan_sekarang = head->next;
    Penyewaan* leftTail = nullptr, *rightTail = nullptr;

    while (penyewaan_sekarang != nullptr) {
        if (penyewaan_sekarang->id > pivot->id) {
            if (!*left) *left = penyewaan_sekarang;
            else leftTail->next = penyewaan_sekarang;
            leftTail = penyewaan_sekarang;
        } else {
            if (!*right) *right = penyewaan_sekarang;
            else rightTail->next = penyewaan_sekarang;
            rightTail = penyewaan_sekarang;
        }
        penyewaan_sekarang = penyewaan_sekarang->next;
    }
    if (leftTail) leftTail->next = nullptr;
    if (rightTail) rightTail->next = nullptr;
    pivot->next = nullptr;
    return pivot;
}

// Fungsi utama Quick Sort untuk descending
Penyewaan* quickSortDescending(Penyewaan* head) {
    if (!head || !head->next) return head;
    
    Penyewaan* left = nullptr, *right = nullptr;
    Penyewaan* pivot = partitionDescending(head, &left, &right);
    
    left = quickSortDescending(left);
    right = quickSortDescending(right);
    
    Penyewaan* penyewaan_sekarang = left;
    if (!left) penyewaan_sekarang = pivot;
    else {
        while (penyewaan_sekarang->next != nullptr) penyewaan_sekarang = penyewaan_sekarang->next;
        penyewaan_sekarang->next = pivot;
    }
    pivot->next = right;
    return left ? left : pivot;
}

// Fungsi untuk mengurutkan penyewaan secara ascending dengan Merge Sort
void urutkanAscending() {
    head = mergeSortAscending(head);
    cout << "Data penyewaan telah diurutkan secara ascending.\n";
}

// Fungsi untuk mengurutkan penyewaan secara descending dengan Quick Sort
void urutkanDescending() {
    head = quickSortDescending(head);
    cout << "Data penyewaan telah diurutkan secara descending.\n";
}

// Fungsi untuk mengubah data penyewaan
void ubahPenyewaan() {
    // isi tetap sama
}

// Fungsi untuk menghapus penyewaan
void hapusPenyewaan() {
    // isi tetap sama
}

int main() {
    int pilihan_menu;

    do {
        cout << "\nManajemen Penyewaan Lapangan Futsal\n";
        cout << "1. Tampilkan Data Penyewaan\n";
        cout << "2. Tambah Penyewaan\n";
        cout << "3. Ubah Penyewaan\n";
        cout << "4. Hapus Penyewaan\n";
        cout << "5. Urutkan Penyewaan (Ascending)\n";
        cout << "6. Urutkan Penyewaan (Descending)\n";
        cout << "7. Keluar\n";
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
                urutkanAscending();
                break;
            case 6:
                urutkanDescending();
                break;
            case 7:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan_menu != 7);

    return 0;
}