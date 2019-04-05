#include<iostream>
#include<malloc.h>
#include<iomanip>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW   -2
#define MAXQSIZE 1001
using namespace std;
typedef int Status;
int main()
{
    int n,m;
    cin>>n;
    int t1,t2,i,j;
    int waittime,maxwt,sumwait,finishtime;
    waittime = maxwt = sumwait = finishtime= 0;
    int CurrentTime = 0;//���ڵ�ʱ��
    int arr[n][2];
    //�ѵ���ʱ��ʹ���ʱ����ڶ�ά������
    for(i = 0; i < n; i++)
    {
        cin>>t1>>t2;
        if(t2 > 60)
            t2 = 60;
        arr[i][0] = t1;
        arr[i][1] = t2;
    }
    cin>>m;
    int w1[m],w2[m];//�ֱ��¼ÿ�����ڴ����굽��ʱ��ĽӴ��Ŀͻ�����
    for(i = 0; i < m; i++)
    {
        //��0
        w1[i] = w2[i] = 0;
    }
    CurrentTime = 0;
    for(i = 0; i < n; i++)
    {
        int flag = 0;
        for(j = 0; j < m; j++)
        {
            //�ͻ�����ʱ����ڴ��ڴ���ʱ��
            if(w1[j] <= arr[i][0])
            {
                flag = 1;
                //��������ʱ��
                CurrentTime = arr[i][0];
                //���´��ڴ���ʱ��
                w1[j] = CurrentTime + arr[i][1];
                //����������1
                w2[j]++;
                break;
            }
        }

        CurrentTime = arr[i][0];
        //�ͻ�����ʱ��С�ڴ���ʱ�䣬��Ҫ�ȴ�
        if(flag == 0)
        {
            //������С����ʱ��Ĵ���
            int mint = w1[0];
            int tem = 0;
            for(j = 1; j < m; j++)
            {
                if(mint > w1[j])
                {
                    mint = w1[j];
                    tem = j;
                }
            }
            //����ʱ���ٵĴ��ڽ��в���
            waittime = w1[tem] - arr[i][0];
            if(maxwt < waittime)
                maxwt = waittime;
            sumwait += waittime;
            cout<<"sumwait:"<<sumwait<<endl;
            w1[tem] += arr[i][1];
            w2[tem]++;
        }
    }
    //��ȡ���ʱ��
    for(i = 0; i < m; i++)
    {
        if(finishtime < w1[i])
            finishtime=w1[i];
    }
    double avg;
    avg = sumwait*1.0/n;
    cout << setiosflags(ios::fixed)<< setprecision(1)<<avg<<" ";
    cout<<maxwt<<" ";
    cout<<finishtime<<endl;
    for(i =  0; i < m; i++)
    {
        if(i == 0)
            cout<<w2[i];
        else
            cout<<" "<<w2[i];
    }
    return 0;
}
