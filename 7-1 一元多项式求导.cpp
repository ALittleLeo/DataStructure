//�⺯��ͷ�ļ�����
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<iostream>
//����״̬�붨��
#define TRUE        1
#define FALSE       0
#define OK          1
#define ERROR       0
#define INFEASIBLE -1
#define OVERFLOW   -2
using namespace std;
typedef int  Status;
typedef int  ElemType; //�������Ա��е�Ԫ�ؾ�Ϊ����

typedef struct LNode
{
    int data1;
    int data2;
    struct LNode *next;
} LNode,*LinkList;
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
    LNode *p = L;
    LNode *r = L;
    int tem1,tem2;
    char c;
//    for(i = 0; i < n; i++)
//    {
//        p = new LNode;
//        cin>>p->data1>>p->data2;
//        p->next = NULL;
//        r->next = p;
//        r = p;
//    }
    int flag = 0;
    while(c=cin.get()!='\n')
    {
        cin.unget();
        cin>>tem1;
        if(tem1 == 0)
            return ERROR;
        cin>>tem2;
        if(tem2 == 1)
        {
            if(flag == 0)
            {
                p = new LNode;
                p->data1 = tem1;
                p->data2 = tem2;
                p->next = NULL;
                r->next = p;
                r = p;
                flag = 1;
            }
            else
            p->data1 += tem1;
        }
        else
        {
            p = new LNode;
            p->data1 = tem1;
            p->data2 = tem2;
            p->next = NULL;
            r->next = p;
            r = p;
        }
    }
    return OK;
}


void ListPrint_L(LinkList &L)
{
//���������
    LNode *p=L->next;  //pָ���һ��Ԫ�ؽ��
    while(p!=NULL)
    {
        if(p->next!=NULL)
            cout<<p->data1<<" "<<p->data2<<" ";
        else
            cout<<p->data1<<" "<<p->data2;
        p=p->next;
    }
}

void GetDerivative(LinkList &La)
{
    LNode *p = La->next;
    int flag = 0;
    while(p!=NULL)
    {
        if(p!=NULL&&flag == 0&&p->data2!=0)
        {
            cout<<p->data1*p->data2<<" "<<p->data2-1;
            flag = 1;
        }
        else if(p!=NULL&&p->data2!=0)
        {
            cout<<" "<<p->data1*p->data2<<" "<<p->data2-1;
        }
        p=p->next;
    }
}
int main()
{
    LinkList La;
    InitList(La);
    if(CreatList(La))
        GetDerivative(La);
    else
        cout<<"����ʽ��0��ʽ";
}
