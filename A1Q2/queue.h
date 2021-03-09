#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

/*
* File: queue.h
*/

typedef struct queueCDT *queueADT;
typedef struct customer *customerT;
typedef struct cashier cashierT;

typedef customerT queueElementT;

queueADT EmptyQueue(void);
void Enqueue(queueADT queue, queueElementT element);
queueElementT Dequeue(queueADT queue);
int QueueLength(queueADT queue);
int QueueIsEmpty(queueADT queue);


#endif // QUEUE_H_INCLUDED
