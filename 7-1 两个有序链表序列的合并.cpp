//�⺯��ͷ�ļ�����
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

//����״̬�붨��
#define TRUE        1
#define FALSE       0
#define OK          1
#define ERROR       0
#define INFEASIBLE -1
#define OVERFLOW   -2

typedef int  Status;
typedef int  ElemType; //�������Ա��е�Ԫ�ؾ�Ϊ����

typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode,*LinkList;

//��������
Status InitList(LinkList &L)
{
    L = new LNode;
    L->next = NULL;

    return OK;
}

Status CreatList(LinkList &L)
{
    L = new LNode;
    L->next = NULL;
    int i;
    LNode *r = L;
    LNode *p = L;
//    for (int i=1; i<=n; i++) //ÿ��ѭ��������һ���½ڵ㣬�����½ڵ�ƴ��β�ڵ��
//    {
//        p = new LNode;//�����½��
//        scanf("%d",&p->data);
//        p->next = NULL;  //���һ���ڵ��next����
//        r->next = p;
//        r = p;
//    }
    int tem;
    while(1)
    {
        scanf("%d",&tem);
        if(tem == -1)
        {
            break;
        }
        else
        {
            p = new LNode;
            p->data = tem;
            p->next = NULL;  //���һ���ڵ��next����
            r->next = p;
            r = p;
        }
    }
    return OK;
}



//����β��
//void LinkListInsert(LinkList &L, int k)
//{
//    LNode *p = L;
//    LNode *TemNode = NULL;
//    while(p->next != NULL)
//    {
//        p = p->next;
//    }
//    TemNode=(LNode*)malloc(sizeof (LNode));
//    TemNode->data = k;
//    TemNode->next = NULL;
//    p->next = TemNode;
//}
void ListPrint_L(LinkList &L)
{
//���������
    LNode *p=L->next;  //pָ���һ��Ԫ�ؽ��
    while(p!=NULL)
    {
        if(p->next!=NULL)
            printf("%d ",p->data);
        else
            printf("%d",p->data);
        p=p->next;
    }
}
int main()
{
    LinkList La,Lb,Lc;
    InitList(Lc);
    CreatList(La);
//    ListPrint_L(La);
//    printf("\n");
    CreatList(Lb);
//    ListPrint_L(Lb);
//    printf("\n");
    LNode *p1 = La->next;
    LNode *p2 = Lb->next;
    LNode *r = Lc;
    LNode *p = Lc;
    while(p1!=NULL&&p2!=NULL)
    {
        if(p1->data >= p2->data)
        {
            p = new LNode;
            p->data = p2->data;
            p->next = NULL;
            r->next = p;
            r = p;
            p2 = p2->next;
        }
        else
        {
            p = new LNode;
            p->data = p1->data;
            p->next = NULL;
            r->next = p;
            r = p;
            p1 = p1->next;
        }
    }

    while(p2)
    {
        p = new LNode;
        p->data = p2->data;
        p->next = NULL;
        r->next = p;
        r = p;
        p2 = p2->next;
    }
    while(p1)
    {
        p = new LNode;
        p->data = p1->data;
        p->next = NULL;
        r->next = p;
        r = p;
        p1 = p1->next;
    }
    if(Lc->next)
        ListPrint_L(Lc);
    else
        printf("NULL");

}
