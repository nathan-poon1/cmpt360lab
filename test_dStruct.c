// test_dStruct.c

#include "dStruct.h"
#include <stdio.h>

int main() {
    // Create a dStruct instance
    dStruct ds;
    dStruct_init(&ds);

    // Push entries
    dStruct_pushEntry(&ds, 1302, 3, 2, 34.5, 65.6);
    dStruct_pushEntry(&ds, 12, 2, 4, 0.03, 12.2);

    // Print all entries
    dStruct_printAllEntries(&ds);

    // Get and print specific entries
    dStruct_printEntryByPid(&ds, 1302);
    dStruct_printEntryByPid(&ds, 12);

    // Set and print updated values
    dStruct_setCputimeByPid(&ds, 1302, 40.0);
    //dStruct_setNicenessByPid(&ds, 12, 5);
    //dStruct_setStatusByPid(&ds, 12, 3);

    dStruct_printAllEntries(&ds);

    // Search for entries
    //dStruct_searchByNicenessAndStatus(&ds, 2, 3);

    // Pop an entry and print remaining entries
    dStruct_popEntry(&ds);
    dStruct_printAllEntries(&ds);

    // Destroy the data structure
    dStruct_destroy(&ds);

    return 0;
}
