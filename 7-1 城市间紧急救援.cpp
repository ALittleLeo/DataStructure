#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n, m, s,q;//����������·�����������У�Ŀ�ĳ���
int b[600];
int a[600][600];//��ͼ����
int c[600];//��¼���·��
int pre[600];
int inf;//������
int sx[600];
int toval[600];//��¼�ܵľ�Ԯ������
int main()
{
    memset(a, 0, sizeof(0));
    int pathnum[600];//�߹���·����
    inf=99999999;
    scanf("%d%d%d%d", &n, &m, &s, &q);
    int i;
    int j;
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
        {
            if(i==j)a[i][j]=0;
            else a[i][j]=inf;
        }
    for(i=0; i<n; i++)
        scanf("%d", &b[i]);
    for(i=0; i<m; i++)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        if(z<a[x][y])
            a[x][y]=a[y][x]=z;
    }
    int vis[600];//����Ƿ���ʹ�


    //��ʼ��
    for(i=0; i<n; i++)
    {
        vis[i]=0;
        c[i]=inf;
        toval[i]=0;
    }
    int k;
    c[s]=0;
    vis[s]=1;//�������б�Ƿ���
    pathnum[s]=1;
    toval[s]=b[s];//�ܵľ�Ԯ���������ڳ������еľ�Ԯ������


    {
        for(i=0; i<n; i++)
        {
            int mini, minn;
            mini=s;//ǰһ�����е��±�
            minn=inf;//��ʼ��һ����С���룬����Ϊ���ֵ
            for(j=0; j<n; j++)
            {
                //�Գ��б��������û�з��ʹ���������Сֵ���ڳ��е�
                if(vis[j]==0 && minn>c[j])
                {
                    mini=j;
                    minn=c[j];
//                    cout<<"��һ��ѭ�� mini:"<<mini<<"minn:"<<minn<<endl;
                }
            }
            vis[mini]=1;
            for(j=0; j<n; j++)
            {
                if(vis[j]==0)
                    if(c[mini]+a[mini][j]<c[j])
                    {
                        c[j]=c[mini]+a[mini][j];
                        pre[j]=mini;
                        toval[j]=b[j]+toval[mini];
                        pathnum[j]=pathnum[mini];
                    }
                    else if(c[mini]+a[mini][j]==c[j] )
                    {
                        if( toval[j]<b[j]+toval[mini])
                        {
                            toval[j]=b[j]+toval[mini];
                            pre[j]=mini;
                        }
                        pathnum[j]+=pathnum[mini];
                    }
            }
        }
    }
    int top=0;
    j=q;
    while(j!=s)
    {
        sx[top++]=j;
        j=pre[j];
    }
    sx[top]=j;
    printf("%d %d\n", pathnum[q], toval[q]);
    for(; top>=0; top--)
    {
        printf("%d", sx[top]);
        if(top!=0)printf(" ");
    }
    return 0;
}
