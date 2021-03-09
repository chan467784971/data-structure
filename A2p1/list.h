#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

typedef struct listCDT *listADT;
typedef int listElementT;

listADT EmptyList(void);
listADT Cons(listElementT, listADT);
listElementT Head(listADT);
listADT Tail(listADT);
listADT Append(listADT, listElementT);
int Sumlist(listADT);
int ListIsEmpty(listADT);


#endif // LIST_H_INCLUDED
