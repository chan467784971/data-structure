#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

//Chan Kai Yan
//1155126922
//1155126922@link.cuhk.edu.hk

//Q3
listADT SmallerList(listACT listA){
int pivot;
pivot = Head(listA);
if ListIsEmpty(Tail(listA)){return (EmptyList())};
if (Head(Tail(listA))<pivot){
    return (Cons(Head(Tail(listA)),SmallerList((Cons(Head(listA),Tail(Tail(listA)))))));
}else(return SmallerList((Cons(Head(listA),Tail(Tail(listA))))));
}


listADT LargerOrEqList(listADT listA){
int pivot;
pivot = Head(listA);
if ListIsEmpty(Tail(listA)){return (EmptyList())};
if (Head(Tail(listA))>pivot||Head(Tail(listA)==pivot)){
    return (Cons(Head(Tail(listA)),LargerOrEqList((Cons(Head(listA),Tail(Tail(listA)))))));
}else(return LargerOrEqList((Cons(Head(listA),Tail(Tail(listA))))));
}

listADT Concat(listADT L1,listADT L2){
if (ListIsEmpty(L1))return (L2);
return Cons(Head(L1),Concat(Tail(L1),L2));
}

listADT quicksortList(listADT listA){
if (ListLength(listA)==1)return(listA);
if (ListLength(listA)==0)return (EmptyList());
return (Concat(quicksortList(SmallerList(listA))),Cons(Head(listA),quicksortList(LargerOrEqList(listA))));
}


//Q4
listADT ListOf(int number,...){
va_list args;
int x;
listADT ListA = EmptyList();

va_start(args,number);
if (number < 0)exit(EXIT_FAILURE);
if (number == 0)va_end(EmptyList());
for (int i=0;i<number;i++){
    x = va_arg(args,int);
    Append(ListA,x);
}
va_end(ListA);
}


//Q5
listADT ListOf2(int number,int E[]){
    listADT ListA = EmptyList();

    if (number < 0)exit(EXIT_FAILURE);
    if (number == 0)va_end(EmptyList());
    for (int i=0;i<number;i++){
    x = E[i];
    Append(ListA,x);
}
    return (ListA);
}


//Q6
void PrintList(listADT listA){
    int x,y;
    y = 2*ListLength(listA);

    if(y==0){printf("[");}
    for (i=0;i<y;i++){
        if (i==0){printf("[");}
        if ((i%2)!=0){
            x = Head(listA);
            printf("%d",x);
            listA = Tail(listA);
        }
        if((i%2)==0){printf(",");}
    }
    printf("]");
}



int main()
{
    FILE *fileptr;
    int linecount = 0;
    char ch;
    char filech[40] = 'data.txt';

    fileptr = fopen(filech,"r");
    ch = getc(filech);
    while (ch != EOF){
        if (ch == '\n'){linecount = linecount + 1;}
        ch = getc(filech);
    }

    for (i=0;i<linecount;i++){
        printf("Line %d\n",i+1);

        char x;
        int y;
        listADT listA;
        listA = EmptyList();
        x = getc(filech);
        while(x!='\n'){
            y = x - '0';
            if (ListIsEmpty(listA)){listA = Cons(y,EmptyList());}
            else{listA = Append(listA,y);}
             x = getc(filech);
        }

        PrintList(listA);
        PrintList(quicksortList(listA));
        printf("Done with Line %d\n",i+1);
        printf("\n");
    }
}
