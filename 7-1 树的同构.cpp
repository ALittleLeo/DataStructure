#include <stdio.h>
#define OK 1
#define ERROR 0
#define MaxTree 10
#define Null -1
//������ϵͳ��NULL 0
#define ElementType char
typedef int Status;
typedef struct TreeNode
{
    ElementType data;
    int left;
    int right;
} Tree;
Tree T1[MaxTree], T2[MaxTree];
int BulidTree(Tree T[])
{
    int N, check[MaxTree], root = Null;
    //root = Null �����򷵻�Null
    char cl, cr;
    //���Һ������
    int i;
    scanf("%d\n",&N);
    if(N)
    {
        for(i = 0; i < N; i++)
            check[i] = 0;
        for(i = 0; i < N; i++)
        {
            scanf("%c %c %c\n",&T[i].data,&cl,&cr);
            //��root
            if(cl != '-')
            {
                T[i].left = cl - '0';
                check[T[i].left] = 1;
                //���Ǹ��ڵ�
            }
            else
            {
                T[i].left = Null;
            }
            if(cr != '-')
            {
                T[i].right = cr - '0';
                check[T[i].right] = 1;
                //���Ǹ��ڵ�
            }
            else
            {
                T[i].right = Null;
            }
        }
        for( i = 0; i < N; i++)
            //check[]=0��Ϊ���ڵ�
            if(!check[i])
            {
                root = i;
                break;
            }
    }
    return root;
}
Status Isomprphic(int root1, int root2)
{
    if( (root1 == Null) && (root2 == Null))
        //���ǿ� ��ͬ��
        return OK;
    if( (root1 == Null)&&(root2 != Null) || (root1 != Null)&&(root2 == Null))//����һ��Ϊ�գ���ͬ��
        return ERROR;
    if(T1[root1].data != T2[root2].data)
        //�����ݲ�ͬ,��ͬ��
        return ERROR;
    if( (T1[root1].left == Null) && (T2[root2].left == Null) )
        //������Ϊ�գ����ж�������
        return Isomprphic(T1[root1].right, T2[root2].right);
    if((T1[root1].left != Null) && (T2[root2].left != Null) &&
            ( T1[T1[root1].left].data == T2[T2[root2].left].data) )
        //�����������Բ��գ���ֵ���
        return (Isomprphic(T1[root1].left, T2[root2].left) &&
                //�ж�������
                Isomprphic(T1[root1].right, T2[root2].right) );
    else //������������һ����  ����  �Բ��յ�ֵ����
        return (Isomprphic(T1[root1].left, T2[root2].right) &&
                //�������������ж�
                Isomprphic(T1[root1].right, T2[root2].left) );
}
int main()
{
    int root1, root2;
    root1 = BulidTree(T1);
    root2 = BulidTree(T2);
    if(Isomprphic(root1, root2) )
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}

