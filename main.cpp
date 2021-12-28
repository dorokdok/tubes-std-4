#include "tubes.h"

int main()
{
    adr_parent parent;
    parentDLL list;
    provinsi dataProvinsi;
    createParentList(list);

    dataProvinsi.nama_provinsi = "Riau";
    dataProvinsi.ibu_kota = "Pekanbaru";
    parent = createParent(dataProvinsi);
    insertParent(list, parent);

    dataProvinsi.nama_provinsi = "Sumatra Utara";
    dataProvinsi.ibu_kota = "Medan";
    parent = createParent(dataProvinsi);
    insertParent(list, parent);

    dataProvinsi.nama_provinsi = "Jakarta";
    dataProvinsi.ibu_kota = "Jakarta";
    parent = createParent(dataProvinsi);
    insertParent(list, parent);
    showParent(list);

    dataProvinsi.nama_provinsi = "Sumatra Utara";
    dataProvinsi.ibu_kota = "Medan";
    parent = createParent(dataProvinsi);
    deleteParent(list, dataProvinsi);
    showParent(list);
}
