#include <stdio.h>
#include <stdlib.h>

#define ERROR -1

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read()
{
    int n;
    scanf("%d",&n);
    List L;
    L->Next = NULL;
    L->Data = 0;
    int i;
    PtrToNode r = L->Next;
    PtrToNode p = L->Next;
    for (i=1; i<=n; i++) //ÿ��ѭ��������һ���½ڵ㣬�����½ڵ�ƴ��β�ڵ��
    {
        //PtrToNode p;//�����½��
        scanf("%d",&p->Data);
        p->Next = NULL;  //���һ���ڵ��next����
        r->Next = p;
        r = p;
    }
    return L;
} /* ϸ���ڴ˲��� */
void Print( List L )
{
     PtrToNode p=L->Next;  //pָ���һ��Ԫ�ؽ��
    while(p!=NULL)
    {
        if(p->Next!=NULL)
            printf("%c ",p->Data);
        else
            printf("%c",p->Data);
        p=p->Next;
    }
} /* ϸ���ڴ˲��� */

ElementType Find( List L, int m )
{
    if(L)
    {
        PtrToNode p1,p2;
        p1 = p2 = L->Next;
        int i = 1;
        while(p1->Next && i < m)
        {
            p1 = p1->Next;
            i++;
        }
        while(p1->Next)
        {
            p1 = p1->Next;
            p2 = p2->Next;
        }
        return p2->Data;
    }
}

int main()
{
    List L;
    int m;
    L = Read();
    scanf("%d", &m);
    printf("%d\n", Find(L,m));
    Print(L);
    return 0;
}
