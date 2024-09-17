#include <iostream>
using namespace std;

void pindahkanPiringan(int jumlahPiringan, char menaraAsal, char menaraTujuan, char menaraSementara) {
    if (jumlahPiringan == 1) {
        cout << "Pindahkan piringan 1 dari menara " << menaraAsal << " ke menara " << menaraTujuan << endl;
        return;
    }
    pindahkanPiringan(jumlahPiringan - 1, menaraAsal, menaraSementara, menaraTujuan);
    cout << "Pindahkan piringan " << jumlahPiringan << " dari menara " << menaraAsal << " ke menara " << menaraTujuan << endl;
    pindahkanPiringan(jumlahPiringan - 1, menaraSementara, menaraTujuan, menaraAsal);
}

int main() {
    int jumlahPiringan = 3; 
    char menaraAsal = 'A';
    char menaraTujuan = 'C';
    char menaraSementara = 'B';

    pindahkanPiringan(jumlahPiringan, menaraAsal, menaraTujuan, menaraSementara);
    
    return 0;
}
