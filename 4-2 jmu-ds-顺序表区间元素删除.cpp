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


//˳����ʼ������
Status InitList_Sq(SqList &L)
{
    //����һ�οռ�
    L.elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    //��⿪���Ƿ�ɹ�
    if(!L.elem)
    {
        exit(OVERFLOW);
    }
    //��ֵ
    L.length = 0;
    L.listsize = LIST_INIT_SIZE;

    return OK;
}

//˳����������
void ListPrint_Sq(SqList L)
{
    ElemType *p = L.elem;//����Ԫ���õ�ָ��


    for(int i = 0; i < L.length; ++i)
    {
        if(i == L.length - 1)
        {
            printf("%d", *(p+i));
        }
        else
        {
            printf("%d ", *(p+i));
        }
    }
}
Status ListInsert_SortedSq(SqList &L, ElemType e)
{
    if(L.length == L.listsize)
        L.listsize += LISTINCREMENT;
    L.elem[L.length] = e;
    ++L.length;
    return OK;
}
int main()
{
    SqList L;
    InitList_Sq(L);
    int n,i,j,tem,x,y;
    scanf("%d",&n);
    for(i = 0; i < n; i++)
    {
        scanf("%d",&tem);
        ListInsert_SortedSq(L,tem);
    }
//    ListPrint_Sq(L);
    scanf("%d%d",&x,&y);
//    printf("%d%d\n",x,y);
//    for(i = 0; i < n; i++)
//    {
//        if(L.elem[i] >= x && L.elem[i] <= y)
//        {
//
//            for(j = i; j < n; j++)
//            {
//                L.elem[j] = L.elem[j+1];
//            }
//            L.length--;
//            i--;
//        }
//
//    }
    i = 0;
    j = n-1;
    while(i < j)
    {
        if(L.elem[i] >= x && L.elem[i] <= y)
        {
            if(L.elem[j] >= x && L.elem[j] <= y)
            {
                --L.length;
                --j;
            }
            else
            {
                L.elem[i] = L.elem[j];
                --L.length;
                ++i;
                --j;
            }
        }
        else
        {
            ++i;
        }
    }
    ListPrint_Sq(L);

}
