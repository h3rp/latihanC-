#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main(){
    int ukuran;
    cout << "Masukkan Panjang Ukuran"<<endl;
    cin >> ukuran;

    int kode[ukuran];
    string nama[ukuran];
    int jumlah[ukuran];
    int harga[ukuran];
    int total[ukuran];
    int total_pembelian = 0;

    for (int i = 0; i < ukuran; i++)
    {
        cout << "Masukkan Kode Ke-" << i+1 <<":";
        cin >> kode[i];
        cout << "Masukkan Nama Ke-" << i+1 <<":";
        cin >> nama[i];
        cout << "Masukkan Jumlah Ke-" << i+1 <<":";
        cin >> jumlah[i];
        cout << "Masukkan Harga Ke-" << i+1 <<":";
        cin >> harga[i];
      
    }
     for (int i = 0; i < ukuran; i++)
     {
        total[i] = jumlah[i] * harga[i];
     }
     for (int i = 0; i < ukuran; i++)
     {
         total_pembelian = total_pembelian + total[i];
     }
     
     
    cout << "Kode" << setw(5) << "Nama" << setw(7) << "Jumlah" << setw(7) <<"Harga" << setw(7) <<"Total" << endl;
    for (int i = 0; i < ukuran; i++)
    {
        cout << kode[i] << setw(7) << nama[i] << setw(7) << jumlah[i] << setw(7) << harga[i] << setw(13) << total << endl;
    }
    cout << "Jumlah Item adalah : " << ukuran << endl;
    cout << "Total Pembelian adalah : " << total_pembelian << endl;

}
