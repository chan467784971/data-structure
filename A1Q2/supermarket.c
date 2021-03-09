//SID:1155126922


#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

struct queueCDT {
  queueElementT Q[10000]; /* max length 10000 */
  int count;
};

queueADT EmptyQueue(){
  queueADT queue = (queueADT)malloc(sizeof(*queue));
  queue->count = 0;
  return queue;
}

void Enqueue(queueADT queue, queueElementT element){
  queue->Q[queue->count++] = element;
}
queueElementT Dequeue(queueADT queue){
  queueElementT result;

  if (QueueIsEmpty(queue)) exit(EXIT_FAILURE); /* error */
  result = queue->Q[0];
  for (int i=0; i<queue->count; i++)
  queue->Q[i] = queue->Q[i+1];
  queue->count--;
  return result;
}

int QueueLength(queueADT queue) {
  return queue->count;
}

int QueueIsEmpty(queueADT queue) {
  return  QueueLength(queue) == 0;
}

struct customer
{
int checkoutTime;
float payment;
};

struct cashier
{
int numberOfCustomersServed;
int totalCustomerWaitingTime;
float totalAmountReceived;
queueADT customerQ;
};

int main(){

//read file and store in customer array
char buff[255];
FILE *fp=fopen("supermarket.txt", "r" );
int a;
float b;

int i=0;
while (feof(fp)==0){
   fgets(buff,sizeof buff,fp);
   sscanf(buff,"%d %1f",&a,&b);
   queueElementT a[i]={
       .checkoutTime = a,
       .payment = b
   };
   i++;
}

for(int i = 0;i < 4;i++){
    cashierT cashier[i]={
    .numberOfCustomersServed = 0,
    .totalCustomerWaitingTime = 0,
    .totalAmountReceived = 0.0,
    .customerQ = EmptyQueue()
    }
}

for(int j = 0;j < i;j++)
{
    //when a new customer come
    //check which cashier is available
    int length[4];
    int c = 0;

    for(int x = 0;x<4;x++){
    length[x] = QueueLength(cashier[x].customerQ);
    }
    for(int x=0;x<3;x++){
     for(int y=x+1;y<4;y++){
         if(length[y]>length[x]){
            c = length[y];
            length[y] = length[x];
            length[x] = c;
         }
     }
    }

    for(int x = 0;x<4;x++){
    if(length[4] == QueueLength(cashier[x].customerQ)
       c = x;//cashier[c] is available
    }

    //go to cashier[c]
    Enqueue(cashier[c].customerQ,a[j]);

    //update cashier information
    //number of customer served
    cashier[c].numberOfCustomersServed++;
    //total amount received
    cashier[c].totalAmountReceived = cashier[c].totalAmountReceived + cashier[c].customerQ.Q.payment;

    for(int x = 0;x<4;x++){
            //update waiting time
        if (QueueLength(cashier[x].customerQ)>1){
            cashier[x].totalCustomerWaitingTime=cashier[x].totalCustomerWaitingTime+QueueLength(cashier[x].customerQ)-1;
        }
        //updating the customer checking out
        cashier[x].customerQ.Q.checkoutTime--;
        //if finish check out ,dequeue
        if((cashier[x].customerQ.Q.checkoutTime)==0){
            Dequeue(cashier[x].customerQ.Q);
        }
        //if all customer had enqueue
        //update remain customers waiting time to cashier
        if((j+1)==i){
                for(int y = 0;y < QueueLength(cashier[x].customerQ);y++){
            cashier[x].totalCustomerWaitingTime=cashier[x].totalCustomerWaitingTime+cashier[x].customerQ.Q.checkoutTime;
            Dequeue(cashier[x].customerQ);
            }
        }
    }

}
int h=0,k=0;
for (int j = 0;j<4;j++){
    h=h+cashier[j].numberOfCustomersServed;
    k=k+cashier[j].totalCustomerWaitingTime;
}
float avgtime = (k/h);
printf("The average time a customer needs to wait is ");
printf("%f",avgtime);
printf(" min(s).\n");

for(int j=0;j<4;j++){
        //output The total amount of money each of the cashiers receives
    printf("The total amount of money of the cashier ");
    printf("%d",j);
    printf("received is $");
    printf("%f",cashier[j].totalAmountReceived);
    printf(" .\n");
        //output The total number of customers each of the cashiers serves
    printf("The total number of customers of the cashier ");
    printf("%d",j);
    printf("served are ");
    printf("%d",cashier[j].numberOfCustomersServed);
    printf(" .\n");
}




}
