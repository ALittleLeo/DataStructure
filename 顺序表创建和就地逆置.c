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
typedef struct{
    ElemType* elem;   //�洢�ռ����ַ
    int length;       //����Ԫ�صĸ���
    int listsize;     //��������С
}SqList;    //˳������Ͷ���

Status ListCreate_Sq(SqList &L);
void ListReverse_Sq(SqList &L);

int main() {
    SqList L;
    ElemType *p;

    if(ListCreate_Sq(L)!= OK) {
        printf("ListCreate_Sq: ����ʧ�ܣ�����\n");
        return -1;
    }

    ListReverse_Sq(L);

    if(L.length){
				for(p=L.elem;p<L.elem+L.length-1;++p){
				    printf("%d ",*p);
				}
				printf("%d",*p);
    }
    return 0;
}
Status ListCreate_Sq(SqList &L)
{
    L.elem = new ElemType(LIST_INIT_SIZE);
    if(!L.elem)
        exit(OVERFLOW);
    L.Length = 0;
    return OK;
}
void ListReverse_Sq(SqList &L)
{
    int tem;
    int len = ListLenth(L);
    int i;
    for(i = 0;i < len/2-1; i++)
    {
         tem = L.elem(i);
         L.elem(i) = L.elem(len-j-1);
         L.elem(len-j-1) = tem;
    }


}
