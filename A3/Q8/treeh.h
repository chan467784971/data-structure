#ifndef TREEH_H_INCLUDED
#define TREEH_H_INCLUDED

typedef struct BinaryTreeCDT *BinaryTreeADT;
typedef struct TreeNodeCDT *TreeNodeADT;
#define SpecialErrNode (TreeNodeADT) NULL

BinaryTreeADT NonemptyBinaryTree(TreeNodeADT,  BinaryTreeADT, BinaryTreeADT);
BinaryTreeADT EmptyBinaryTree(void);
BinaryTreeADT LeftSubtree(BinaryTreeADT);
BinaryTreeADT RightSubtree(BinaryTreeADT);
int TreeIsEmpty(BinaryTreeADT);
TreeNodeADT Root(BinaryTreeADT);
char *GetNodeKey(TreeNodeADT);

#endif // TREEH_H_INCLUDED
