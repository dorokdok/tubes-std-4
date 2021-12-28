#include "tubes.h"
//aa


void createNewChild(string namaKota, float suhu, adr_child &p){
    //Create new element kaya biasa aja
    p = new elm_child;
    next(p) = nil;
    prev(p) = nil;
    info(p).nama_kota = namaKota;
    info(p).suhu = suhu;
}

void insertNewChild(parentDLL &list, adr_parent S, adr_child K){
    //Sama kaya modul 10 logikanya
    adr_child p = kota(S);
    if (p == nil){
        kota(S) = K;
    } else{
        while (next(p) != nil){
            p = next(p);
        }
        prev(K) = p;
        next(p) = K;
    }
}

void deleteChild(parentDLL &List, adr_parent S, int n){
    adr_child p = kota(S);
    //Nyari data child ke n(nanti ada di menu)
    for (int i = 1; i < n; i++){
        p = next(p);
    }
    if (p == kota(S)){ //Buat delete first
        kota(S) = next(p);
        prev(kota(S)) = nil;
        next(p) = nil;
    } else if(next(p) == nil){ //Buat delete last
        next(prev(p)) = nil;
        prev(p) = nil;
    } else { //Buat delete di tengah"
        next(prev(p)) = next(p);
        prev(next(p)) = prev(p);
        next(p) = nil;
        prev(p) = nil;
    }
}

void showChildfromParent(parentDLL List, adr_parent S){
    adr_child p = kota(S);
    if (p == nil){
        cout << "Tidak terdapat data kota" << endl;
    } else {
        cout << "Daftar kota : " << endl;
        while (p != nil) {
            cout << "Kota: " << info(p).nama_kota << " Suhu: " << info(p).suhu << endl;
            p = next(p);
        }
    }
}

void findChild(parentDLL list, adr_parent S, string namaKota){
    adr_child p = kota(S);
    while (p != nil){
        if (info(p).nama_kota == namaKota){
            cout << "Terdapat Kota " << namaKota << " dengan Suhu " << info(p).suhu << endl;
            return;
        }
        p = next(p);
    }
    if (p == nil){
        cout << "Tidak terdapat kota pada provinsi " << info(S).nama_provinsi << endl;
    }
}

void findChildfromAll(parentDLL List, string namaKota){
    adr_parent p = first(List);
    while (p != nil){ //Buat looping parent
        adr_child q = kota(p);
        while (q != nil){ //Buat looping child
            if (info(q).nama_kota == namaKota){ //Buat cek
                cout << "Kota: " << info(q).nama_kota << " Suhu: " << info(q).suhu << endl;
                cout << "Provinsi: " << info(p).nama_provinsi << " Ibu Kota: " << info(p).ibu_kota << endl;
                return;
            }
            q = next(q);
        }
        p = next(p);
    }
    if (p == nil){
        cout << "Kota tidak ditemukan" << endl;
    }
}
