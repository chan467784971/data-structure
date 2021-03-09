#include <stdio.h>
#include <stdlib.h>

int main()
{
    int E[9,5,8,7];
    listADT L1 = ListOf2(4,E);
    return 0;
}

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
