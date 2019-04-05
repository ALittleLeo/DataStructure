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

//˳���Ĵ洢�ṹ����
#define LIST_INIT_SIZE  100
#define LISTINCREMENT   10
typedef int ElemType;  //�������Ա��е�Ԫ�ؾ�Ϊ����
typedef struct
{
    ElemType* elem;   //�洢�ռ����ַ
    int length;       //����Ԫ�صĸ���
    int listsize;     //��������С
} SqList;   //˳������Ͷ���

//��������
Status ListInsert_SortedSq(SqList *L, int n, ElemType e)
{
    if(L->length == L->listsize)
        L->listsize += LISTINCREMENT;
    int j,i;



    ++L->length;
    return OK;
}

//˳����ʼ������
Status InitList_Sq(SqList *L)
{
    //����һ�οռ�
    L->elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    //��⿪���Ƿ�ɹ�
    if(!L->elem)
    {
        exit(OVERFLOW);
    }
    //��ֵ
    L->length = 0;
    L->listsize = LIST_INIT_SIZE;

    return OK;
}

//˳����������
void ListPrint_Sq(SqList *L)
{
    ElemType *p = L->elem;//����Ԫ���õ�ָ��


    printf("nn=%d\n",L->length);
    for(int i = 0; i < L->length; ++i)
    {
        if(i == L->length - 1)
        {
            printf("%d", *(p+i));
        }
        else
        {
            printf("%d ", *(p+i));
        }
    }
}
int main()
{
    //����һ��˳���
    SqList L;
    //��ʼ��˳���
    InitList_Sq(&L);
    ListPrint_Sq(&L);



    return  0;
}
