#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;


//�α�
void get_next(string T, int next[],int n)
{
    int i = 1;
    next[1] = 0;
    int j = 0;
    while(i <= n)
    {
        if(j==0||T[i-1]==T[j-1])
        {
            ++i;
            ++j;
            next[i] = j;
        }
        else
            j = next[j];
    }
}



//�����ҵ�
//void get_next(string p,int next[],int n)
//{
//    int j,k;
//    next[1]=0;
//    j=1;
//    k=0;
//    while(j<n-1)
//    {
//        if(k==0||p[j]==p[k])    //ƥ��������,p[j]==p[k]��next[j+1]=k+1;
//        {
//            j++;
//            k++;
//            next[j]=k;
//        }
//        else                   //p[j]!=p[k]��k=next[k]
//            k=next[k];
//    }
//}

//void get_nextval(String T, int *nextval)
//{
//    int i,j;
//    i=1;
//    j=0;
//    nextval[1]=0;
//    while (i<T[0])  /* �˴�T[0]��ʾ��T�ĳ��� */
//    {
//        if(j==0 || T[i]== T[j])     /* T[i]��ʾ��׺�ĵ����ַ���T[j]��ʾǰ׺�ĵ����ַ� */
//    {
//                ++i;
//                ++j;
//        if (T[i]!=T[j])      /* ����ǰ�ַ���ǰ׺�ַ���ͬ */
//                nextval[i] = j; /* ��ǰ��jΪnextval��iλ�õ�ֵ */
//            else
//            nextval[i] = nextval[j];    /* �����ǰ׺�ַ���ͬ����ǰ׺�ַ��� */
//                            /* nextvalֵ��ֵ��nextval��iλ�õ�ֵ */
//        }
//    else
//        j= nextval[j];          /* ���ַ�����ͬ����jֵ���� */
//    }
//}
int main()
{
    int i;
    string T;
    cin>>T;
    int n = T.size();
    int next[n+1];
    get_next(T,next,n);
    for(i = 1; i <= n; i++)
    {
        printf("%d",next[i]);
    }
}
