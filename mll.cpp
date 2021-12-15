#include "multi.h"

void create_list(mll &list_sales){ //1301204001 Dio N
    first(list_sales) = nil;
}
void newElm_Sales(sales info, adr_sales &S){ //1301204001 Dio N
    S = new elm_sales;
    next(S) = nil;
    nextjual(S) = nil;
    info(S) = info;
}
void newElm_Jual(int info, adr_jual &J){ //1301204001 Dio N
    J = new elm_jual;
    next(J) = nil;
    info(J) = info;
}
void insertNew_Penjualan(mll &list_sales, adr_sales S, adr_jual J){ //1301204001 Dio N
    adr_jual p = nextjual(S);
    if (p == nil){
        nextjual(S) = J;
    } else if (p != nil){
        while (next(p) != nil){
                p = next(p);
        }
        next(p) = J;
    }
}

void insertLast_Sales(mll &list_sales, adr_sales S){ //1301204001 Dio N
    if(first(list_sales) == nil){
        first(list_sales) = S;
    } else {
        adr_sales p = first(list_sales);
        while (next(p) != nil){
            p = next(p);
        }
        next(p) = S;
    }
}
void deleteFirst_Penjualan(mll &list_sales, adr_sales S, adr_jual &J){ //1301204001 Dio N
    adr_jual p = nextjual(S);
    J = p;
    nextjual(S) = next(p);
    next(p) = nil;
}
void deleteLast_Penjualan(mll &list_sales, adr_sales S, adr_jual &J){ //1301204001 Dio N
    adr_jual p = nextjual(S);
    while (next(p) != J){
        p = next(p);
    }
    J = next(p);
    next(p) = next(J);
    next(J) = nil;
}
void deleteAfter_Penjualan(mll &list_sales, adr_sales S, adr_jual prec, adr_jual &J){ //1301204001 Dio N
    next(prec) = next(J);
    next(J) = nil;
}
void showData_Sales(mll list_sales){
    adr_sales p = first(list_sales);
    while (p != nil){
        cout << info(p).nama << endl;
        adr_jual q = nextjual(p);
        while (q != nil){
            cout << info(q) << " ";
            q = next(q);
        }
        cout << endl;
        p = next(p);
    }
}
adr_sales search_sales(mll list_sales, string nama_sales){ //1301204001 Dio N
    adr_sales p = first(list_sales);
    while (p != nil){
        if(info(p).nama == nama_sales){
            return p;
        }
        p = next(p);
    }
    return nil;
}


void delete_penjualan(mll &list_sales){ //1301204001 Dio N
    adr_sales p = first(list_sales);
    adr_jual J;
    while (p != nil){
        adr_jual q = nextjual(p);
        while (q != nil){
            if (info(q) < 3){
                if (q == nextjual(p)){
                    deleteFirst_Penjualan(list_sales,p,J);
                } else if(next(q) != nil){
                    adr_jual q1 = nextjual(p);
                    while (next(q1) != q){
                        q1 = next(q1);
                    }
                    deleteAfter_Penjualan(list_sales,p,q1,q);
                } else if (next(q) == nil){
                    adr_jual q1 = nextjual(p);
                    while (next(q1) != q){
                        q1 = next(q1);
                    }
                    next(q1) = nil;
                }
            }
            q = next(q);
        }
        p = next(p);
    }
}
