//header seperti biasa
#include <iostream>
#include <stdio.h>
using namespace std;

//fungsi untuk bermain hanoi tower dengan algoritma rekursi
void HanoiTower(int jumlah_cakram, char dari_tiang, char ke_tiang, char tiang_bantu) 
{    
    if (jumlah_cakram == 0) //klo nnti cakram yg mau dipindahi == 0, fungsinya akan berhenti
    {
        return; //ibaratnya break-nya si function
    }

    HanoiTower(jumlah_cakram - 1, dari_tiang, tiang_bantu, ke_tiang); //manggil function/lakuin rekursi 
    //menampilkan output untuk langkah permainan 
    cout << "|  Pindahkan cakram " << jumlah_cakram << " dari tiang " << dari_tiang << " ke tiang " 
    << ke_tiang << "                  |" << endl;

    //setelah itu, panggil function lagi/melakukan rekursi, tapi dengan nilai yang diubah.
    //awalnya "dari_tiang" ke "tian_bantu", dari "tiang_bantu" ke "ke_tiang", dan dari "ke_tiang" ke "dari_tiang"
    HanoiTower(jumlah_cakram - 1, tiang_bantu, ke_tiang, dari_tiang);
}

//main program
int main() 
{
    system("CLS"); //untuk menghapus layar klo user melakukan banyak percobaan
    int jumlah_cakram; //as known as deklarasi variabel

    //untuk header di output nanti
    printf("================================================================\n");
    printf("|                    Hanoi Tower Algorithm                     |\n");
    printf("================================================================\n");
    cout << "|  Masukkan jumlah cakram: "; //user diminta masukkan banyak cakra di hanoi tower
    cin >> jumlah_cakram; //untuk menerima inputan user

    // A, B, dan C adalah nama-nama tiang
    HanoiTower(jumlah_cakram, 'A', 'C', 'B'); //manggil function
    printf("========================= SELESAI ==============================\n");
    //output untuk footer

    return 0; //opsional
}
