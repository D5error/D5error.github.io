#include<stdio.h>
#include<stdlib.h>

typedef struct BiTNode{
    int data;
    struct BiTNode *lchild,*rchild;
} BiTNode, *BiTree;

void CreateBiTree(BiTree &T){
    char ch;
    scanf("%c",&ch);
    if('#' == ch) T = NULL;
    else{
        if(!(T = (BiTNode *)malloc(sizeof(BiTNode)))) exit(-1);
        else{

            T -> data = ch;
            CreateBiTree(T -> lchild);
            CreateBiTree(T -> rchild);
        }
    }
}

int count(BiTree T){
    if (T == NULL) return 0;
    else if(T->lchild == NULL&& T->rchild!= NULL)
        return 1+count(T->rchild);
    else if(T->lchild!=NULL&&T->rchild==NULL)
        return 1+count(T->lchild);

        return count(T->lchild)+count(T->rchild);
}
int main()
{
    BiTree T;
    CreateBiTree(T);
    printf("%d",count(T));
    return 0;

}