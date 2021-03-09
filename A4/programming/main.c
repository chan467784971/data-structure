//1155126922
//CHAN Kai Yan
//1155126922@link.cuhk.edu.hk


#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "list.h"
#include "priorityqueue.h"
#include <stdbool.h>
#include <math.h>
#define MAX_N 100 /* Possible nodes are node 0, node 1, ..., node 99. */

struct GraphCDT {
    float W[MAX_N*(MAX_N+1)/2];
    bool NodeExists[MAX_N];
    };

struct ArcCDT {
    Node i, j; /* make sure that both nodes exist, and i <= j */
};

//part 1

GraphADT EmptyGraph(void){
    GraphADT G;
    G = (GraphADT)malloc(sizeof(*G));
    G->W=NULL;
    G->NodeExists=NULL;
    return(G);

}

bool GraphIsEmpty(GraphADT G){
    return(G == null);
}

bool AddNode(GraphADT G,Node n){
    if(!G->NodeExists[n]){return(G->NodeExists[n]=true);}
    return false;
}

bool NodeExists(GraphADT G, Node n){
    return G->NodeExists[n];
}

listADT AdjacentNodes(GraphADT G,Node n){
    if(!ArcExists(G,n))exit(EXIT_FAILURE);
    listADT L1 = EmptyList();
    for (int i=0;i<MAX_N*(MAX_N+1)/2;i++){
        if (ArcExists(G->W[i])){//if there is an arc
                //if the arc is about node n
            if (NodeI(IndextoArc(G,i))==n)
                L1=Cons(NodeJ(IndextoArc(G,i)),L1);
            if (NodeJ(IndextoArc(G,i))==n)
                L1=Cons(NodeI(IndextoArc(G,i)),L1);
        }
    }
    return L1;
}

int Degree(GraphADT G,node N){
    if(!ArcExists(G,n))exit(EXIT_FAILURE);
    return(ListLength(AdjacentNodes(G,n)));
}

ArcADT Arc(Node n, Node m){
    ArcADT a;
    a->i=n;
    a->j=m;
    return a;
}

Node NodeI(ArcADT a){
    int n,m;
    n=a->i;
    m=a->j;
    if (n>m){return m;}else{return n;}

}

Node NodeJ(ArcADT a){
    int n,m;
    n=a->i;
    m=a->j;
    if (n>m)(return n;)else{return m;}
}

bool AddArc(GraphADT G,ArcADT a, float w){
    if ((G->NodeExists[NodeI(a)])||(G->NodeExists[NodeJ(a)])
        {
            G->W[ArctoIndex(G,a)] = w;
            return true;
        }else{return false;}
}

float ArcWeight(GraphADT G, ArcADT a){
    if(!ArcExists(G,a))exit(EXIT_FAILURE);
    return G->W[ArctoIndex(Arc a)];
}

bool ArcExists(GraphADT G, ArcADT a){
    return (G->W[ArctoIndex(G,a)]);

}

int ArctoIndex(GraphADT G, ArcADT a) {
    if (!ArcExists(G, a)) exit(EXIT_FAILURE);
    return a->j + a->i*MAX_N - a->i*(a->i+1)/2;
    }

ArcADT IndextoArc(GraphADT G, int x) {
    ArcADT a = (ArcADT) malloc(sizeof(*a));
    int x1; a->i = 1;
    while (x >= (x1 = (a->i) * MAX_N - (a->i) * (a->i - 1) / 2)) a->i++;
    a->i--; a->j = MAX_N + x - x1;
    return a; /* whether the arc exists is not checked! */
    }

void PrintAllNodes(GraphADT G){
 if(GraphIsEmpty(G))exit(EXIT_FAILURE);
 for(int i=0;i<MAX_N;i++){
    if (G->NodeExists[i]){
        printf("%d",i);
    }
 }
}

void PrintAllArcs(GraphADT G){
    if(GraphIsEmpty(G))exit(EXIT_FAILURE);
     for(int i=0;i<MAX_N;i++){
        if (G->NodeExists[i]){
        listADT L1 = EmptyList();
        L1 = AdjacentNodes(G,i);
        int x = listlength(L1);
        for(j=0;j<listlength;j++){
            printf('(');
            printf("%d",i);
            printf(',');
            printf("%d",(Head(L1)));
            printf(')');
            printf("%d\n",ArctoIndex(G,Arc(i,Head(L1))));
            L1 = Tail(L1);
        }
    }
 }

}

//part 2
struct priorityQueueCDT{
    pQueueElementT heap[1000];
    int numOfElem;
};

priorityQueueADT EmptyPriorityQueue(){
    priorityQueueADT queue;
    queue = (priorityQueueADT)malloc(sizeof(*queue));
    queue->numOfElem=0;
    return queue;
}

void PriorityEnqueue(priorityQueueADT queue,ArcADT element){

    int hole;
    for (hole=(queue->numOfElem)++;
         hole == 0?
            false : queue->heap[(hole-1)/2]>element;
         hole = (hole-1)/2)
         queue->heap[hole] = queue->heap[(hole-1)/2];

    queue->heap[hole]=element;
}
ArcADT PriorityDequeue(priorityQueueADT queue){
    pQueueElementT result,v; int hole,child;

    if(PriorityQueueIsEmpty(queue)))exit(EXIT_FAILURE);
    result = queue->heap[0];
    v = queue->heap[--(queue->numOfElem)];
    for (hole=0;2*hole+1<queue->numOfElem;hole = child){
        child = 2*hole+1;
        if (child+1<queue->numOfElem &&
            queue->heap[child+1]<queue->heap[child])child++;
        if (v > queue->heap[child+])
            queue->heap[hole]=queue->heap[child];
        else
            break;
    }
    queue->heap[hole] = v;
    return result;
}

GraphADT mspK(GraphADT G){
    priorityQueueADT queue = EmptyPriorityQueue();

    for(int i=0;i<MAX_N*(MAX_N+1)/2;i++){
        if(ArcExists(G,IndextoArc(G,i))){
            PriorityEnqueue(queue,IndextoArc(G,i));
        }
    }


if (!((Find(NodeI(IndextoArc(G,x))))==(Find(NodeJ(IndextoArc(G,x))))))
{
   SetUnion(NodeI(IndextoArc(G,x)),NodeJ(IndextoArc(G,x)));
}

PrintAllNodes(G);
PrintAllArcs(G);
}



int main()//part1
{
    FILE *fileptr
    int linecount = 0;
    char ch;
    char filech[40] = 'GraphData.dat';

    fileptr = fopen(filech,"r");
    ch = getc(filech);
    while (ch != EOF){
        if (ch == '\n'){linecount = linecount + 1;}
        ch = getc(filech);
    }

    fclose(fileptr);

    fileptr = fopen(filech,"r");
    GraphADT G = EmptyGraph();
    for(int i=0;i< linecount;i++){
        int m,n;
        float w;
        char c;
        scanf("%c",&c);

        if(c == 'n'){
            scanf("%d",&m);
            AddNode(G,m);
        }

        if(c == 'a'){
            scanf("%d%d%f",&m,&n,&w);
            if(NodeExists(m)&&NodeExists(n)){
            AddArc(G,Arc(m,n),w);
            }
        }
    }

    PrintAllNodes(G);
    PrintAllArcs(G);
    return 0;
}
