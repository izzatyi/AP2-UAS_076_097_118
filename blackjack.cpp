    #include <iostream>
    #include <stdio.h>
    using namespace std;

    void HanoiTower(int jumlah_cakram, char dari_tiang, char ke_tiang, char tiang_bantu) {
        
        if (jumlah_cakram == 0) 
        {
            return;
        }
        HanoiTower(jumlah_cakram - 1, dari_tiang, tiang_bantu, ke_tiang);

        cout << "|  Pindahkan cakram " << jumlah_cakram << " dari tiang " << dari_tiang << " ke tiang " 
        << ke_tiang << "                  |" << endl;

        HanoiTower(jumlah_cakram - 1, tiang_bantu, ke_tiang, dari_tiang);
    }

    int main() {
        system("CLS");
        int jumlah_cakram;
        printf("================================================================\n");
        printf("|                    Hanoi Tower Algorithm                     |\n");
        printf("================================================================\n");
        cout << "|  Masukkan jumlah cakram: ";
        cin >> jumlah_cakram;
        
        // A, B, dan C adalah nama-nama tiang
        HanoiTower(jumlah_cakram, 'A', 'C', 'B');
        printf("========================= SELESAI ==============================\n");

        return 0;
    }
