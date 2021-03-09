#include <stdio.h>
#include <stdlib.h>

//Chan Kai Yan
//1155126922
//1155126922@link.cuhk.edu.hk

BinaryTreeADT InsertNode(BinaryTreeADT t, TreeNodeADT n) {

 if (TreeIsEmpty(t)) return NonemptyBinaryTree(n,EmptyBinaryTree(), EmptyBinaryTree());
 else {
	int sign = strcmp(GetNodeKey(n), GetNodeKey(Root(t)));
	if (sign == 0) return NonemptyBinaryTree(n,LeftSubtree(t), RightSubtree(t));
	if (sign < 0) return NonemptyBinaryTree(Root(t),InsertNode(LeftSubtree(t),n), RightSubtree(t));
	return NonemptyBinaryTree(Root(t),LeftSubtree(t), InsertNode(RightSubtree(t),n));
	}
}

void InOrderTraversal(BinaryTreeADT t){
    if(TreeIsEmpty(t)){return;}
    InOrderTraversal(LeftSubtree(t));
    ExprNode(Root(t));
    InOrderTraversal(RightSubtree(t));
}


TreeNodeADT parent(BinaryTreeADT t, TreeNodeADT n)
{
    if (TreeIsEmpty(t)){return;}
    if (InOrderTraversal(LeftSubtree(t))==n){
        printf("Parent of %d is %d",n,t);}
    if (ExprNode(Root(t))==n){
        printf("Parent of %d dose not exist",n);}
    if (InOrderTraversal(RightSubtree(t))==n){
        printf("Parent of %d is %d",n,t);}

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
        printf("Tree %d\n",i+1);

        BinaryTreeADT t;
        TreeNodeADT x = getc(filech);
        while(x!='\n'){
            InsertNode(t,x);
            TreeNodeADT x = getc(filech);
        }

        parent(t,ExpoNode(t));
        printf("Done with Tree %d\n",i+1);
    }

}
