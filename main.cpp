#include "tubes.h"

int main()
{
    adr_parent parent;
    parentDLL List;
    provinsi dataProvinsi;
    createParentList(List);
    adr_child kota;
    string namaKota, namaKotaC;
    float suhuKota;
    int n=1, prov, j, nKota;
    while (n != 0){
        n = menu();
        if (n == 1){
            cout <<"Masukkan jumlah data Provinsi yang ingin ditambah: "; cin >> j;cin.ignore();
            for (int i = 0; i < j; i++){
                cout <<"Masukkan data Provinsi yang ingin ditambah" << endl;
                cout <<"Masukkan nama Provinsi: ";getline(cin, dataProvinsi.nama_provinsi);
                cout <<"Masukkan nama Ibu kota: ";getline(cin, dataProvinsi.ibu_kota);
                parent = createParent(dataProvinsi);
                insertParent(List, parent);
                cout << endl;
            }
            cout << endl;
        } else if (n == 2){
            cout <<"Masukkan data Provinsi yang ingin dihapus" << endl;
            cout <<"Masukkan nama Provinsi: ";cin.ignore();getline(cin, dataProvinsi.nama_provinsi);
            cout <<"Masukkan nama Ibu kota: ";getline(cin, dataProvinsi.ibu_kota);
            deleteParent(List, dataProvinsi);
            cout << endl;
        } else if (n == 3){
            showParent(List);
        } else if (n == 4){
            cout <<"Masukkan data Provinsi yang ingin dicari" << endl;
            cout <<"Masukkan nama Provinsi: ";cin.ignore();getline(cin, dataProvinsi.nama_provinsi);
            cout <<"Masukkan nama Ibu kota: ";getline(cin, dataProvinsi.ibu_kota); cout << endl;
            parent = findParent(List, dataProvinsi);
            cout << endl;
        }else if (n == 5) {
            if (first(List) != nil) {
                cout <<"Masukkan data kota yang ingin ditambah" << endl;
                cout <<"Masukkan nama Kota: ";cin.ignore();getline(cin, namaKota);
                cout <<"Masukkan Suhu kota: ";cin >> suhuKota;
                createNewChild(namaKota, suhuKota, kota);
                showParent(List);
                cout <<"Pilih Provinsi(dengan angka): "; cin >> prov;
                loopParent(List, parent, prov);
                insertNewChild(List, parent, kota);
                cout << endl;
            } else {
                cout << "Tidak ada data Provinsi" << endl; cout << endl;
            }
        } else if (n == 6) {
            if (first(List) != nil) {
                showParent(List);
                cout <<"Pilih Provinsi yang ingin dilihat datanya(dengan angka): "; cin >> prov;
                loopParent(List, parent, prov);
                showChildfromParent(List, parent);
                cout << endl;
            } else {
                cout << "Tidak ada data Provinsi" << endl; cout << endl;
            }
        } else if (n == 7) {
            if (first(List) != nil) {
                showParent(List);
                cout <<"Pilih Provinsi yang ingin dilihat datanya(dengan angka): "; cin >> prov;
                loopParent(List, parent, prov);
                showChildfromParent(List, parent);
                if (kota(parent) != nil) {
                    cout <<"Pilih Kota yang ingin dihapus(dengan angka): "; cin >> nKota;
                    deleteChild(List, parent, nKota);
                }
            } else {
                cout << "Tidak ada data Provinsi" << endl; cout << endl;
            }
        } else if (n==8){
            if (first(List) != nil){
                showParent(List);
                cout <<"Pilih Provinsi yang ingin dicari kotanya(dengan angka): "; cin>>prov;
                loopParent(List, parent, prov);
                cout <<"Masukkan nama kota yang dicari: "; cin.ignore(); getline(cin, namaKotaC); cout <<endl;
                findChild(List, parent, namaKotaC); cout <<endl;
            } else {
                cout << "Tidak ada Data Provinsi" << endl << endl;
            }
        } else if (n==9) {
            if (first(List) != nil){
                cout <<"Masukkan nama kota yang dicari: "; cin.ignore(); getline(cin, namaKotaC); cout <<endl;
                findChildfromAll(List, namaKotaC); cout <<endl;
            } else {
                cout << "Tidak ada Data Provinsi" << endl << endl;
            }
        } else if (n==10){
            if (countAllCity(List) == 0 ){
                cout << "Tidak ada kota pada list" << endl;
            } else {
                cout << "Pada list, terdapat sebanyak: " << countAllCity(List) << " kota" << endl;
            }
            cout << endl;
        } else if (n==11){
            if (maxDegree(List) == nil){
                cout << "Tidak ada kota yang tersedia" << endl;
            } else {
                cout << "Suhu tertinggi terdapat pada kota: " << info(maxDegree(List)).nama_kota << " dengan suhu: " << info(maxDegree(List)).suhu << endl;
            }
            cout << endl;
        }
    }
}
