#ifndef LISTH_H_INCLUDED
#define LISTH_H_INCLUDED
typedef struct listCDT *listADT;

typedef int listElementT;

listADT EmptyList(void);
listADT Cons(listElementT, listADT);
listElementT Head(listADT);
listADT Tail(listADT);
int ListIsEmpty(listADT);
int ListLength(listADT);
listADT Append(listADT,listElementT);

#endif // LISTH_H_INCLUDED
