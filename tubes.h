#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED
#include <iostream>
#include <string>
#include<bits/stdc++.h>

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

void createNewChild(string namaKota, float suhu, adr_child &p);
void insertNewChild(parentDLL &list, adr_parent S, adr_child K);
void deleteChild(parentDLL &List, adr_parent S, int n);
void showChildfromParent(parentDLL List, adr_parent S);
void findChild(parentDLL list, adr_parent S, string namaKota);
void findChildfromAll(parentDLL List, string namaKota);

void createParentList(parentDLL &list);
adr_parent createParent(provinsi dataProvinsi);
void insertParent(parentDLL &list, adr_parent S);
adr_parent findParent(parentDLL list, provinsi dataProvinsi);
void deleteParent(parentDLL &list, provinsi dataProvinsi);
void showParent(parentDLL list);

int menu();
void loopParent(parentDLL List, adr_parent &p, int n);
int countAllCity(parentDLL List);


#endif // TUBES_H_INCLUDED
