#include "tubes.h"


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

void createParentList(parentDLL &list){
    first(list) = nil;
    last(list) = nil;
}

// Mengembalikan address parent yang berisikan data provinsi
adr_parent createParent(provinsi dataProvinsi){
    adr_parent Parent;
    Parent = new elm_parent;
    info(Parent).nama_provinsi = dataProvinsi.nama_provinsi;
    info(Parent).ibu_kota = dataProvinsi.ibu_kota;
    next(Parent) = nil;
    prev(Parent) = nil;
    kota(Parent) = nil;
    return (Parent);
}

// Pada insert parent, kami menggunakan insert last
void insertParent(parentDLL &list, adr_parent S){
    if (first(list) == nil){
        first(list) = S;
        last(list) = S;
    } else {
        next(last(list)) = S;
        prev(S) = last(list);
        last(list) = S;
    }
}

// Mencari parent berdasarkan data provinsi
adr_parent findParent(parentDLL list, provinsi dataProvinsi){
    adr_parent found;
    if (first(list) == nil){
        cout << "Tidak ada data pada list" << endl;
    } else {
        found = first(list);
        while (found != nil && info(found).ibu_kota != dataProvinsi.ibu_kota && info(found).nama_provinsi != dataProvinsi.nama_provinsi){
            found = next(found);
        }
        if (info(found).ibu_kota == dataProvinsi.ibu_kota && info(found).nama_provinsi == dataProvinsi.nama_provinsi){
            return found;
        } else {
            found = nil;
            cout << "Data tersebut tidak ditemukan pada list" << endl;
            return found;
        }
    }
}

// Menggunakan fungsi find dalam pengaplikasian prosedur delete tersebut
void deleteParent(parentDLL &list,  provinsi dataProvinsi){
    adr_parent parent;
    parent = findParent(list, dataProvinsi);
    if (parent != nil){
        if (first(list) == parent){
            first(list) = next(first(list));
            next(prev(first(list))) = nil;
            prev(first(list)) = nil;
        } else if (last(list) == parent){
            last(list) = prev(last(list));
            prev(next(last(list))) = nil;
            next(last(list)) = nil;
        } else {
            prev(next(parent)) = prev(parent);
            next(prev(parent)) = next(parent);
            prev(parent) = nil;
            next(parent) = nil;
        }
    }
}

// Menampilkan data provinsi dari list yang ada
void showParent(parentDLL list){
    adr_parent p;
    if (first(list) == nil){
        cout << "Tidak ada data pada list" << endl;
    } else {
        p = first(list);
        int i = 1;
        cout << "Berikut data dari seluruh list: " << endl;
        while (p != nil){
            cout << "[" << i << "]" << endl;
            cout << "Nama Provinsi: " << info(p).nama_provinsi << endl;
            cout << "Nama Ibu Kota: " << info(p).ibu_kota << endl;
            p = next(p);
            i++;
        }
        cout << endl;
    }
}
