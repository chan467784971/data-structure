/*
* File: symtab.c
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "symtab.h"
typedef struct cellT {char *key; symtabEntryT value;} cellT;

struct symtabCDT {
cellT **bucket; // An array of cellT*, which can be extended.
int nBuckets; // Current number of buckets (size of the bucket array)
int nEntries; // Current number of entries.
};

int Hash(char *s, int nBuckets) { // DO NOT MODIFY.
unsigned long hashcode = 0;
for (int i=0; s[i]!='\0'; i++) hashcode = (hashcode<<5) + s[i];
return (int) (hashcode % nBuckets);
}

symtabADT EmptySymbolTable() { // DO NOT MODIFY.
symtabADT T1 = (symtabADT) malloc(sizeof(*T1));
T1->bucket = (cellT*) malloc(5*sizeof(cellT*)); // Initial size is 5.
T1->nBuckets = 5; T1->nEntries = 0;
for (int i = 0; i < T1->nBuckets; i++) T1->bucket[i]=(cellT*)NULL;
return T1;
}

//part1
list Append(listADT L1,listElementT x){
if (ListIsEmpty(L1))
    return(Cons(x,EmptyList()));
else
    return(Cons(Head(L1),Append(Tail(L1),x)));
}

int Sumlist(listADT L1){
if (ListIsEmpty(L1))
    return(0);
else
    return(Head(L1)+Sumlist(Tail(L1)));
}
//sum all values in a list
void sumvalue(symtabADT T1){
for (int i = 0; i < T1->nBuckets; i++)
if (T1->bucket[i] != NULL)
T1->bucket[i]->value = Sumlist(T1->bucket[i]->value);
}

void Enter(symtabADT T1, char* K1, symtabEntryT V1) {
// You need to implement this.
int hashCode; cellT *cp;
hashCode = hash(K1,5);
int i=1;

while(i){
//extend bucket number by 7
if ((T1->nBuckets)==(T1->nEntries)){
    T1->nBuckets = T1->nBuckets+7;
}
//insert
if ((T1->nBuckets[hashCode])==Null){
 cp = (cellT*)malloc(sizeof(*cp));
 cp->key = (char*)malloc(sizeof(char)*(strlen(key)+1));
 strcpy(cp->key,K1);
 cp->value = V1;
 T1->nEntries++;
 i=0;
}else if((T1->bucket->key)==K1){
        Append(cp->value,Head(V1)); // same keys, add value to the list
        i=0;
}else{
        hashCode++;//move to next bucket
}
}

}

symtabEntryT Lookup(symtabADT T1, char* K1) {
// You need to implement this.
int hashCode; cellT *cp;
hashCode = hash(K1,5);

if ((T1->nBuckets[hashCode])==NULL) return(EmptyList());

int i=1;
while(i){
if (((T1->nBuckets[hashCode]!=NULL)&&(T1->bucket->key)==K1){//key match
    return(T1->bucket->value);
    i=0;
}else {//not same key means hash code need update
    hashCode++;
    }
}

void DisplayEntry(char *key, symtabEntryT L1){
printf("%s\t%d\n",key,Sumlist(L1));
}

void forEachEntryDo(symtabFnT f, symtabADT T1) { // DO NOT MODIFY.
for (int i = 0; i < T1->nBuckets; i++)
if (T1->bucket[i] != NULL)
f(T1->bucket[i]->key, T1->bucket[i]->value);
}

void printList(listADT L) { // DO NOT MODIFY.
if (ListIsEmpty(L))
printf("nil");
else {
printf("%d:", Head(L));
printList(Tail(L));
}
}

void ShowAll(symtabADT T1){ // DO NOT MODIFY.
for (int i = 0; i < T1->nBuckets; i++)
if (T1->bucket[i] != NULL) {
printf("Bucket %d\t Key:%s\t Value ", i, T1->bucket[i]->key);
printList(T1->bucket[i]->value);
printf("\n");
}
}





//part2

int main()
{
    FILE *ifp;
    char *mode = "r";
    ifp = fopen("data.txt",mode);
    if (!fp)
  {
    fprintf(stderr, "Error opening file '%s'\n", FILENAME);
    return EXIT_FAILURE;
  }
  //find no. of line in file.
  char cr;
  int count;
  cr = getc(ifp);
    while (cr != EOF)
    {
        if (cr == 'n')
        {
            count = count + 1;
        }
        cr = getc(ifp);
    }
    fclose(ifp);

    ifp = fopen("data.txt",mode);
    if (!fp)
  {
    fprintf(stderr, "Error opening file '%s'\n", FILENAME);
    return EXIT_FAILURE;
  }
   symtabADT T1;
   char str[100];
   int x;
   for(int i=0;i<count/2;i++){
   fscanf(ifp,str);
   x = getw(ifp);
   Enter(T1,str,x);
   }
   fclose(ifp);

   sumvalue(T1);//the function modify by myself, detail is at before
   forEachEntryDo(DisplayEntry,T1);

}
