#include<iostream>
#include <stdio.h>
#include <vector>
using namespace std;

void tampil_data (vector<int>& angka)
{
    printf("Data yang tersedia adalah : \n");
    for (int a = 0; a < angka.size(); a++)
    {
        cout << "Index ke-" << a << " : " << angka[a] << endl;
    }
}

void urutkan_Datanya_dulu(vector<int>& angka) 
{
    for (int i = 0; i < angka.size() - 1; i++) 
    {
        for (int j = 0; j < angka.size() - i - 1; j++) 
        {
            if (angka[j] > angka[j + 1]) 
            {
                int temp = angka[j];
                angka[j] = angka[j + 1];
                angka[j + 1] = temp;
            }
        }
    }
}
int main() {

    int dtCari, hasilCari;
    string input_awal;

    system("cls");
    printf("################## BINARY SEARCH ################## ");
    printf("\nInput Data (tanpa spasi, dengan koma): ");
    getline(cin, input_awal);
    printf("\n####################################################\n");

    vector<int> angka;
    string temp = "";

    for (char sementara : input_awal) {
        if (sementara == ',') {
            angka.push_back(stoi(temp));
            temp = "";
        } else {
            temp += sementara;
        }
    }
    angka.push_back(stoi(temp));

    printf("Data yang dicari : ");
    cin >> dtCari;

    urutkan_Datanya_dulu(angka);
    for (int a = 0; a<angka.size(); a++)
    {
        if(dtCari == angka[a]){
            hasilCari++;
        }
    }

    if (hasilCari == 0)
    {
        printf("Data tidak ditemukan!");
    }
    else
        cout << "Data " << dtCari << " ditemukan di : ";
        for (int a = 0; a < angka.size(); a++)
        {
            if(angka[a] == dtCari)
            {
                cout << "Index ke-" << a << endl;
            }
        }

    printf("\n####################################################\n");

    printf("Apakah Ingin melihat data yang dimasukkan? (y/n): ");
    char jawaban;
    cin >> jawaban;
    if (jawaban == 'y' || jawaban == 'Y')
    {
        tampil_data(angka);
    }
    

}