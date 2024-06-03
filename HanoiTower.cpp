#include <iostream>
#include <vector>
using namespace std;

//Struktur untuk menyimpan pesan solusi dan selamat tinggal
struct Pesan {
    vector<string> Solusi;
    vector<string> SelamatTinggal;
};

//Struktur untuk menyimpan langkah-langkah perpindahan cakram
struct Langkah {
    int cakram;
    char src;
    char tgt;
};

//Kelas untuk memecahkan puzzle Menara Hanoi
class MenaraHanoi {
    public:
        Pesan Info; //Objek untuk menyimpan pesan
        Langkah langkah[200]; //Array untuk menyimpan langkah-langkah perpindahan (maksimal 200 langkah)
        int index = 0; //Inisialisasi langsung variabel indeks

        //Fungsi rekursif untuk memecahkan Menara Hanoi
        void ToH(int n, char src, char tgt, char aux) {
            if (n == 0) {
                return; //Jika tidak ada cakram, tidak ada yang perlu dipindahkan
            } else if (n > 0) {
                //Pindahkan n-1 cakram dari tiang sumber ke tiang bantu
                ToH(n - 1, src, aux, tgt);
                //Menyimpan langkah perpindahan cakram ke array
                langkah[index].cakram = n;
                langkah[index].src = src;
                langkah[index].tgt = tgt;
                index++;
                //Pindahkan n-1 cakram dari tiang bantu ke tiang target
                ToH(n - 1, aux, tgt, src);
            }
        }

        //Fungsi untuk menampilkan langkah-langkah solusi
        void LangkahLangkah() {
            for (int i = 0; i < index; ++i) {
                cout << "Pindahkan cakram " << langkah[i].cakram << " dari " << langkah[i].src << " ke " << langkah[i].tgt << "." << endl;
            }
        }

        //Fungsi untuk menampilkan pesan solusi
        void PesanSolusi() {
            cout << "-----------------------------------------\n";
            Info.Solusi.push_back("Puzzle Menara Hanoi berhasil diselesaikan.");
            for (int i = 0; i < Info.Solusi.size(); ++i) {
                cout << Info.Solusi[i];
            }
            puts("");
        }

        //Fungsi untuk menampilkan pesan selamat tinggal
        void PesanSelamatTinggal() {
            cout << "-----------------------------------------\n";
            Info.SelamatTinggal.push_back("Terima kasih telah menggunakan pemecah Menara Hanoi. Selamat tinggal!");
            for (int i = 0; i < Info.SelamatTinggal.size(); ++i) {
                cout << Info.SelamatTinggal[i];
            }
            puts("");
        }
};

int main() {
    system("CLS"); //Membersihkan layar konsol

    int JumlahCakram;
    int *ptr;
    char PecahkanLagi;

    //Pesan selamat datang
    cout << "   ## Selamat datang di Menara Hanoi ##\n"; 
    cout << "=========================================\n";
    cout << "Mari kita pecahkan puzzle Menara Hanoi!\n";

    do {  
        //Meminta pengguna memasukkan jumlah cakram
        do {
            cout << "Masukkan jumlah cakram : "; 
            cin >> JumlahCakram;
            ptr = &JumlahCakram;
            if (*ptr <= 0) {
                cout << "Silakan masukkan bilangan bulat positif yang valid.\n";
            }
        } while (*ptr <= 0);
        cout << "-----------------------------------------\n";

        MenaraHanoi Tampil;
        //Memanggil fungsi untuk memecahkan puzzle
        Tampil.ToH(*ptr, 'A', 'C', 'B');
        Tampil.LangkahLangkah(); // Menampilkan langkah-langkah solusi
        Tampil.PesanSolusi(); // Menampilkan pesan solusi

        //Menanyakan apakah pengguna ingin mencari solusi lain
        cout << "\nTemukan solusi lain? (Y/N): ";
        cin >> PecahkanLagi;
    } while (PecahkanLagi == 'Y' || PecahkanLagi == 'y');
    
    MenaraHanoi Tampil;
    Tampil.PesanSelamatTinggal(); //Menampilkan pesan selamat tinggal

    return 0;
}
