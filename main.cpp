#include <iostream>
#include "multi.h"
int main()
{
    mll L;
    create_list(L);
    adr_sales S;
    adr_jual J;
    sales infomasuk;
    infomasuk.nama = "Siska";infomasuk.gol = "Gol A"; newElm_Sales(infomasuk, S);
    insertLast_Sales(L, S);
    newElm_Jual(5, J); insertNew_Penjualan(L, S, J); newElm_Jual(3, J); insertNew_Penjualan(L, S, J);
    newElm_Jual(4, J); insertNew_Penjualan(L, S, J); newElm_Jual(2, J); insertNew_Penjualan(L, S, J);
    infomasuk.nama = "Affan";infomasuk.gol = "Gol C"; newElm_Sales(infomasuk, S);
    insertLast_Sales(L, S);
    newElm_Jual(1, J); insertNew_Penjualan(L, S, J); newElm_Jual(3, J); insertNew_Penjualan(L, S, J);
    infomasuk.nama = "Cahya";infomasuk.gol = "Gol A"; newElm_Sales(infomasuk, S);
    insertLast_Sales(L, S);
    newElm_Jual(5, J); insertNew_Penjualan(L, S, J); newElm_Jual(0, J); insertNew_Penjualan(L, S, J);
    newElm_Jual(2, J); insertNew_Penjualan(L, S, J);
    infomasuk.nama = "Lia";infomasuk.gol = "Gol C"; newElm_Sales(infomasuk, S);
    insertLast_Sales(L, S);
    infomasuk.nama = "Hafidz";infomasuk.gol = "Gol B"; newElm_Sales(infomasuk, S);
    insertLast_Sales(L, S);
    newElm_Jual(1, J); insertNew_Penjualan(L, S, J);
    showData_Sales(L);
    cout << endl; cout << endl;
    delete_penjualan(L);
    showData_Sales(L); cout << endl;
    showData_Sales(L); cout << endl;
}
