#include <iostream>
#include <string>
#include <cmath>
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

// Fungsi untuk membagi linked list menjadi dua bagian (Merge Sort)
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

// Fungsi untuk menggabungkan dua linked list secara ascending (Merge Sort)
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

// Fungsi untuk memisahkan bagian quicksort (Quick Sort)
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

// Fungsi Fibonacci Search (untuk tipe integer)
int fibonacciSearch(int arr[], int n, int x) {
    int fib2 = 0;
    int fib1 = 1;
    int fibM = fib2 + fib1;

    while (fibM < n) {
        fib2 = fib1;
        fib1 = fibM;
        fibM = fib2 + fib1;
    }

    int offset = -1;

    while (fibM > 1) {
        int i = min(offset + fib2, n - 1);
        if (arr[i] < x) {
            fibM = fib1;
            fib1 = fib2;
            fib2 = fibM - fib1;
            offset = i;
        } else if (arr[i] > x) {
            fibM = fib2;
            fib1 = fib1 - fib2;
            fib2 = fibM - fib1;
        } else {
            return i;
        }
    }

    if (fib1 && arr[offset + 1] == x) {
        return offset + 1;
    }

    return -1;
}

// Fungsi Jump Search (untuk tipe integer)
int jumpSearch(int arr[], int n, int x) {
    int step = sqrt(n);
    int prev = 0;

    while (arr[min(step, n) - 1] < x) {
        prev = step;
        step += sqrt(n);
        if (prev >= n) {
            return -1;
        }
    }

    while (arr[prev] < x) {
        prev++;
        if (prev == min(step, n)) {
            return -1;
        }
    }

    if (arr[prev] == x) {
        return prev;
    }

    return -1;
}

// Fungsi Boyer-Moore Search (untuk tipe string)

int max(int a, int b) {
    return (a > b) ? a : b;
}

// Fungsi untuk membangun tabel bad character
void badCharHeuristic(string pat, int size, int badchar[256]) {
    // Inisialisasi semua elemen tabel bad character dengan -1
    for (int i = 0; i < 256; i++) {
        badchar[i] = -1;
    }

    // Mengisi tabel bad character dengan indeks terakhir dari karakter yang muncul dalam pattern
    for (int i = 0; i < size; i++) {
        badchar[(int)pat[i]] = i;
    }
}

// Fungsi pencarian Boyer-Moore untuk mencari pattern dalam teks
void boyerMooreSearch(string txt, string pat) {
    int m = pat.size();  // panjang pattern
    int n = txt.size();  // panjang teks

    int badchar[256];

    // Membangun tabel bad character menggunakan pattern
    badCharHeuristic(pat, m, badchar);

    int s = 0;  // posisi geser dari pattern di sepanjang teks
    while (s <= (n - m)) {
        int j = m - 1;

        // Bandingkan pattern dengan teks dari belakang ke depan
        while (j >= 0 && pat[j] == txt[s + j]) {
            j--;
        }

        // Jika pattern cocok dengan teks pada posisi ini
        if (j < 0) {
            cout << "Pattern ditemukan pada indeks: " << s << endl;
            // Geser pattern sehingga karakter selanjutnya dalam teks disejajarkan dengan
            // kemunculan terakhir dari karakter yang sesuai di pattern
            s += (s + m < n) ? m - badchar[(int)txt[s + m]] : 1;
        } else {
            // Geser pattern berdasarkan tabel bad character heuristic
            s += max(1, j - badchar[(int)txt[s + j]]);
        
        int main() {
            string txt = "lapanganfutsal";
            string pat = "futsal";

        boyerMooreSearch(txt, pat);

        return 0;
    }

        }
    }
}
