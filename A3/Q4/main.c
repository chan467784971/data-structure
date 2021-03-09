#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int main()
{
    listADT L1 = ListOf(4,9,5,8,7);
    return 0;
}

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
