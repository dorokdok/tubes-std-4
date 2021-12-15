#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED
#include <iostream>

using namespace std;

#define info(P) (P)->info
#define next(P) (P)->next
#define prev(P) (P)->prev
#define kota(P) (P)->kota
#define first(L) ((L).first)
#define last(L) ((L).last)
#define nil NULL

typedef struct elm_parent *adr_parent;
typedef struct elm_child *adr_child;

struct provinsi{
    string nama_provinsi;
    string ibu_kota;
};

struct datakota{
    string nama_kota;
    float suhu;
};

struct elm_parent{
    provinsi info;
    adr_parent next;
    adr_parent prev;
    adr_child kota;
};

struct elm_child{
    datakota info;
    adr_child next;
    adr_child prev;
};

struct parentDLL{
    adr_parent first;
    adr_parent last;
};

struct childDLL{
    adr_child first;
    adr_child last;
};


#endif // TUBES_H_INCLUDED
