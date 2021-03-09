#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef struct stackCDT *stackADT;

typedef int stackElementT;

stackADT EmptyStack(void);
void Push(stackADT stack, stackElementT element);
stackElementT Pop(stackADT stack);
int StackDepth(stackADT stack);
int StackIsEmpty(stackADT stack);

#endif // STACK_H_INCLUDED
