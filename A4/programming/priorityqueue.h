#ifndef PRIORITYQUEUE_H_INCLUDED
#define PRIORITYQUEUE_H_INCLUDED

#include <stdbool.h>
#include "graph.h"

typedef struct priortyQueueCDT * priorityQueueADT;


priorityQueueADT EmptyPriorityQueue(void);
void PriorityEnqueue(priorityQueueADT,ArcADT);
ArcADT PriorityDequeue(priorityQueueADT);
bool PriorityQueueIsEmpty(priorityQueueADT);

#endif // PRIORITYQUEUE_H_INCLUDED
