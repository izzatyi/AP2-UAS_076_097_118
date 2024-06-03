//Header seperti biasa
#include <iostream>
#include <vector>
using namespace std;

struct Pesan {
    vector<string>Selesai;  //untuk pesan selesai
    vector<string>Goodbye;  //simpan pesan goodbye
};

//kelas untuk nyelesaikan hanoi tower
class Hanoi_Tower {
    public:
        Pesan Info;
        //fungsi untuk menyelesaikan permainan hanoi tower
        void HT(int n, char dari_tiang, char ke_tiang, char tiang_bantu) {
            if (n == 0) {   //jika tidak ada disk yang harus dipindahkan, fungsi berhenti
                return;
            } else if (n > 0) { // melakukan rekursi
                HT(n - 1, dari_tiang, tiang_bantu, ke_tiang);
                cout << "Pindahkan disk " << n << " dari " << dari_tiang << " ke " << ke_tiang << "." << endl;
                HT(n - 1, tiang_bantu, ke_tiang, dari_tiang); //lakuin rekursi dengan nilai yg berbeda
            }
        }
        //fungsi untuk menyampaikan pesan bahwa Tower Hanoi sudah selesai
        void Penyelesaian() {
            cout << "-------------------------------------\n";
            Info.Selesai.push_back("Puzzle Tower Hanoi berhasil dipecahkan!");
            for (int i = 0; i < Info.Selesai.size(); ++i) { //perulangan untuk nampilin pesan selesai karena si pesan dalam bentuk vektor
                cout << Info.Selesai[i]; //perintah untuk menapilkan pesan di dalam var selesai
            }
            cout << endl; //untuk enter ke baris baru
        }
        //fungsi untuk menyampaikan pesan goodbye pada user
        void Bye() {
            cout << "-------------------------------------\n";
            Info.Goodbye.push_back("Terima kasih telah menggunakan program Tower Hanoi. Goodbye!");
            for (int i = 0; i < Info.Goodbye.size(); ++i) { //perulangan untuk menampilkan pesan goodnye
                cout << Info.Goodbye[i]; //tampilin pesannnya
            }
            cout << endl;
        }
};

int main() {
    system("CLS"); //mengahapus layar jika user melakukkan banyak percobaan

    //dibawah ini merupakan proses inisialisasi
    int Jml_Disk;
    int *jumlah_disk_ptr;
    char ulang;

    //header untuk di output nanti
    cout << "=====================================\n";
    cout << " ## Welcome to the Tower of Hanoi ##\n"; 
    cout << "=====================================\n";
    cout << " Ayo Selesaikan Puzzle Tower Hanoi!!!\n";

    do { //perulangan do while untuk bertanya diakhir apakah user ingin mengulang atau tidak
        
        do {
            cout << "Masukkan jumlah disk : "; //perintah buat masukin jumlah disk
            cin >> Jml_Disk;  //menerma inputan berapa banyak jumlah cakram/disk
            jumlah_disk_ptr = &Jml_Disk; //mengalihkan nilai dari var Jml_Disk ke jumlah_disk_jumlah_disk_ptr
            if (*jumlah_disk_ptr <= 0) { //klo si user masukin nilai negatif,
                cout << "Masukkan sebuah bilangan bulat positif!\n"; //maka bakalan nampilin ini
            }
        } while (*jumlah_disk_ptr <= 0); //dan melakukan perulangan sampe si user masukkin nilai positif
        
        cout << "-------------------------------------\n"; //cuma batas biasa, biar estetik
        
        Hanoi_Tower Show; //penamaan objek untuk class hanoi Tower
        //memanggil fungsi HT untuk menyelesaikan puzzle hanoi tower
        Show.HT(*jumlah_disk_ptr, 'A', 'C', 'B');
        Show.Penyelesaian(); //untuk nampilkan pesan di akhir

        //dibawah ini kode untuk bertanya kepada user apakah ingin mengulang
        cout << "\nTemukan solusi lain? (Y/N): ";
        cin >> ulang;
    } while (ulang == 'Y' || ulang == 'y'); //klo ya, dia bakalan ngulang ke pertanyaan awal di main program
    
    //klo jawabannya selain y, akan dianggap ga mau ngulang
    //dan nampilin besan bye-bye
    Hanoi_Tower Show;
    //menampilkan pesan goodbye
    Show.Bye();

    return 0; //opsional
}