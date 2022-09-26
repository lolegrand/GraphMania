#include "my_data_structure.h"
#include <stdlib.h>
#include <stdio.h>

MyDataStructure * createMyDataStructure(int val) {
    MyDataStructure * mds = (MyDataStructure *)malloc(sizeof(MyDataStructure));
    if (mds == NULL) {
        perror("Error while create a data structure");
        exit(EXIT_FAILURE);
    }
    *mds = val;
    return mds;
}

void freeMyDataStructure(MyDataStructure * mds) {
    free(mds);
    mds = NULL;
}

int compareMyDataStructure(const MyDataStructure * left, const MyDataStructure * right) {
    if (left < right) return -1;
    if (left > right) return 1;
    return 0;
}

void printMyDataStructure(FILE * file, const MyDataStructure * data) {
    fprintf(file,"%d", *data);
}
