

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


struct stackCDT {
stackElementT elements[100];
int count;
};

stackADT EmptyStack(void) {
stackADT stack;
stack=(stackADT)malloc(sizeof(*stack));
stack->count=0;
return(stack);
}

void Push(stackADT stack, stackElementT element) {
stack->elements[(stack->count)++]=element;
}

stackElementT Pop(stackADT stack) {
return(stack->elements[--(stack->count)]);
}

int StackDepth(stackADT stack) {
return(stack->count);
}

int StackIsEmpty(stackADT stack) {
return(stack->count==0);
}


int main(void)
{
    printf("Please input the string of parenthesis:");
    stackADT bracketsStack;
    char op,str1[80];

    bracketsStack = EmptyStack();
    do
    {
        scanf("%c",str1);
        op = str1[0];

        switch(op)
        {
            case ')' ://round parentheses
            case ']' ://square brackets
            case '}' ://brace
                PairBracket(op,bracketsStack);
            case '\n':
                if (StackDepth(bracketsStack) == 0)
                {
                    printf("Yes, the input is a well-formed string of parentheses. ");
                }else{
                    printf("No, the input is NOT a well-formed string of parentheses. ");
                }
            default:
                Push(bracketsStack,atoi(str1));
        }



    }while(op!='\n');

    static void PairBracket(char op,stackADT bracketsStack)
    {
        stackElementT lhs, rhs;
        rhs = Pop(bracketsStack);
        lhs = Pop(bracketsStack);
        switch(op)
        {
            case ')' :if (lhs == '('){lhs = '\0'; rhs = '\0';break;}
            case ']' :if (lhs == '['){lhs = '\0'; rhs = '\0';break;}
            case '}' :if (lhs == '{'){lhs = '\0'; rhs = '\0';break;}
            default :
                {
                 Push(bracketsStack,lhs);
                 Push(bracketsStack,rhs);
                }

        }

    }



}
