// dStruct.c

#include "dStruct.h"
#include <stdio.h>
#include <stdlib.h>

void dStruct_init(dStruct* ds) {
    ds->head = NULL;
    ds->size = 0;
}

void dStruct_destroy(dStruct* ds) {
    while (ds->head != NULL) {
        dStructEntry* temp = ds->head;
        ds->head = ds->head->next;
        free(temp);
    }
    ds->size = 0;
}

bool dStruct_pushEntry(dStruct* ds, int pid, int status, int niceness, float cputime, float procTime) {
    dStructEntry* newEntry = (dStructEntry*)malloc(sizeof(dStructEntry));
    if (newEntry == NULL) {
        printf("Memory allocation failed.\n");
        return false; // Failure
    }

    newEntry->pid = pid;
    newEntry->status = status;
    newEntry->niceness = niceness;
    newEntry->cputime = cputime;
    newEntry->procTime = procTime;

    // Insert at the beginning of the linked list
    newEntry->next = ds->head;
    ds->head = newEntry;
    ds->size++;

    return true; // Success
}

void dStruct_popEntry(dStruct* ds) {
    if (ds->head != NULL) {
        dStructEntry* temp = ds->head;
        ds->head = ds->head->next;
        free(temp);
        ds->size--;
    }
}

dStructEntry* dStruct_getEntryByPid(const dStruct* ds, int pid) {
    dStructEntry* current = ds->head;
    while (current != NULL) {
        if (current->pid == pid) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

dStructEntry* dStruct_getEntryByIndex(const dStruct* ds, unsigned int index) {
    dStructEntry* current = ds->head;
    unsigned int i = 0;
    while (current != NULL && i < index) {
        current = current->next;
        i++;
    }
    return current;
}

float dStruct_getCputimeByPid(const dStruct* ds, int pid) {
    dStructEntry* entry = dStruct_getEntryByPid(ds, pid);
    if (entry != NULL) {
        return entry->cputime;
    }
    return -1.0; // Indicate an error
}

void dStruct_setCputimeByPid(dStruct* ds, int pid, float cputime) {
    dStructEntry* entry = dStruct_getEntryByPid(ds, pid);
    if (entry != NULL) {
        entry->cputime = cputime;
    }
}

void dStruct_printAllEntries(const dStruct* ds) {
    printf("All Entries:\n");
    dStructEntry* current = ds->head;
    while (current != NULL) {
        printf("PID: %d, Status: %d, Niceness: %d, Cputime: %.2f, ProcTime: %.2f\n",
               current->pid, current->status, current->niceness,
               current->cputime, current->procTime);
        current = current->next;
    }
}
