#ifndef MULTI_H_INCLUDED
#define MULTI_H_INCLUDED
#include <iostream>
using namespace std;

#define info(P) (P)->info
#define next(P) (P)->next
#define nextjual(P) (P)-> nextjual
#define first(L) ((L).first)
#define nil NULL

typedef struct elm_sales *adr_sales;
typedef struct elm_jual *adr_jual;

struct sales{
    string nama, gol;
};

struct elm_sales{
    sales info;
    adr_sales next;
    adr_jual nextjual;
};

struct elm_jual{
    int info;
    adr_jual next;
};

struct mll{
    adr_sales first;
};

void create_list(mll &list_sales);
void newElm_Sales(sales info, adr_sales &S);
void newElm_Jual(int info, adr_jual &J);
void insertNew_Penjualan(mll &list_sales, adr_sales S, adr_jual J);
void insertLast_Sales(mll &list_sales, adr_sales S);
void deleteFirst_Penjualan(mll &list_sales, adr_sales S, adr_jual &J);
void deleteLast_Penjualan(mll &list_sales, adr_sales S, adr_jual &J);
void deleteAfter_Penjualan(mll &list_sales, adr_sales S, adr_jual prec, adr_jual &J);
void delete_penjualan(mll &list_sales);
void showData_Sales(mll list_sales);
adr_sales search_sales(mll list_sales, string nama_sales);

#endif // MULTI_H_INCLUDED
