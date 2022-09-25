#ifndef GRANDELIA_MY_DATA_STRUCTURE_H
#define GRANDELIA_MY_DATA_STRUCTURE_H

#include <mbstring.h>

typedef int MyDataStructure;

MyDataStructure * createMyDataStructure(int val);

void freeMyDataStructure(MyDataStructure * mds);

int compareMyDataStructure(const MyDataStructure * left, const MyDataStructure * right);

void printMyDataStructure(FILE * file,const MyDataStructure * data);

#endif //GRANDELIA_MY_DATA_STRUCTURE_H
