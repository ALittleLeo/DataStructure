//#include <iostream>
//using namespace std;
//#define MaxVertexNum 100
//#define INFINITY 65535
//typedef int Vertex;
//typedef int WeightType;
//
////����ͼ�ڵ�
//typedef struct
//{
//    int Nv;
//    int Ne;
//    WeightType G[MaxVertexNum][MaxVertexNum];
//    int IsFinish[MaxVertexNum][MaxVertexNum];
//}MGraph;
////��¼���·��
//typedef struct
//{
//    Vertex adjvex;
//    WeightType lowcost;
//}Closedge;
//Closedge closedge[MaxVertexNum];
//
////����ͼ
//int  CreateGraph(MGraph &Graph)
//{
//    int tem;
//    int village1,village2,cost,isfinish;
//    cin>>Graph.Nv;
//    int i;
//    for(i = 0; i < Graph.Nv*(Graph.Nv-1)/2; ++i)
//    {
//        cin>>village1>>village2;
//        cin>>cost>>isfinish;
//        if(isfinish == 1)
//            cost = 0;
//        Graph.G[village1-1][village2-1] = Graph.G[village2-1][village1-1] = cost;
//        Graph.IsFinish[village1-1][village2-1] = Graph.IsFinish[village2-1][village1-1] = isfinish;
//    }
//    return 1;
//}
//
////�����̱ߵ��±�
//Vertex Min(Closedge closedge[],int n)
//{
//    int i,index;
//    int mincost = INFINITY;
//    index = -1;
//    for(i = 0; i < n; ++i)
//    {
//        if(mincost > closedge[i].lowcost)
//        {
//            mincost = closedge[i].lowcost;
//            index = i;
//        }
//    }
//    return index;
//}
//
////Ѱ�����·��
//WeightType MiniSpanTree_Prim(MGraph Graph)
//{
//    //������Graph���ڽӾ�����ʽ���棬�Ӷ���0����������Graph����С������T
//    WeightType totalmincost = 0;
//    int i,j,h;
//    for(i = 0; i < Graph.Nv; ++i)
//    {
//        if(i != 0)
//        {
//            closedge[i] = {0,Graph.G[0][i]};
//        }
//    }
//    int k,u0,v0;
//    closedge[0].lowcost = INFINITY;
//    for(j = 1; j < Graph.Nv; ++j)
//    {
//        k = Min(closedge, Graph.Nv);
//        totalmincost += closedge[k].lowcost;
//        u0 = closedge[k].adjvex;
//        v0 = k;
//        closedge[k].lowcost = INFINITY;
//        for(h = 0; h < Graph.Nv; ++h)
//        {
//            if(Graph.G[k][h] < closedge[h].lowcost)
//                closedge[h] = {k, Graph.G[k][h]};
//        }
//        cout<<"totalmincost: "<<totalmincost<<endl;
//    }
//    return totalmincost;
//}
//
//int main()
//{
//    MGraph Graph;
//    CreateGraph(Graph);
//    cout<<"********"<<endl;
//    cout<<MiniSpanTree_Prim(Graph);
//}



#include "iostream"
#include "algorithm"
using namespace std;

#define Max 200
#define Sky 9999

int Top,Edge;

bool Move[Max];//����Ƿ񽨳�
int Dist[Max];//�������·��
int Map[Max][Max];//��ͼ�������������֮��ľ�����Ϣ

//int Prime()
//{
//    int Sum=0;//��·��
//    int i,j;
//    //��ʼ�����·�������飬��1�Ŵ�ׯ��ʼ
//    for(i=1;i<=Top;i++)
//    {
//        Dist[i]=Map[1][i];
//        Move[i]=false;
//    }
//
//    Move[1]=true;
//    Dist[1]=0;
//    //�ҵ���1�ų���·����̵���һ������
//    for(i=1;i<Top;i++)
//    {
//        int min=Sky,k=-1;
//        for(j=1;j<=Top;j++)
//        {
//            if(min>Dist[j]  && !Move[j])
//            {
//                min=Dist[j];
//                k=j;
//            }
//        }
//        Move[k]=true;
//        if(k!=-1)
//        {
//            Sum+=Dist[k];
//            for(j=1;j<=Top;j++)
//            {
//                if(Dist[j]>Map[k][j] && !Move[j])
//                {
//                    Dist[j]=Map[k][j];
//                }
//            }
//        }
//    }
//
//    return Sum;
//}


int Prime()
{
    int sum = 0;
    int i,j;
    for(i = 1; i <= Top; ++i)
    {
        Dist[i] = Map[1][i];
        Move[i] = false;
    }
    Move[1] = true;
    for(i = 1; i < Top; i++)
    {
        int min = Sky,k = -1;
        for(j = 1; j < Top; j++)
        {
            if(min > Dist[j] && !Move[j])
            {
                min = Dist[j];
                k = j;
            }
        }
        Move[k] = true;
        if(k != -1)
        {
            sum += Dist[k];
            for(j = 1; j < Top; ++j)
            {
                if(Dist[j] > Map[k][j] && !Move[j])
                {
                    Dist[j] = Map[k][j];
                }
            }
        }

    }
    return sum;
}
int main()
{

    //freopen("1.txt","r",stdin);
    cin>>Top;
    Edge=Top*(Top-1)/2;
    int i,j;
    //�ȳ�ʼ����ͼ�����ó����ֵ
    for(i=1;i<=Top;i++)
    for(j=1;j<=Top;j++)
    {
      Map[i][j]=Sky;
    }
    for(i=1;i<=Edge;i++)
    {
         int x,y,z,d;
         cin>>x>>y>>z>>d;
         if(d==1)
         {
             Map[x][y]=Map[y][x]=0;
         }
         else
         {
              Map[x][y]=Map[y][x]=z;
         }
    }
    cout<<Prime()<<endl;
    return 0;
}


