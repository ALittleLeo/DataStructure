#include <iostream>
#include <stdio.h>
using namespace std;

void GetArr(int arr[],int n)
{
    int i;
    for(i = 1; i < n; i++)
    {
//        cin>>arr[i];
        scanf("%d",&arr[i]);
    }
}
void Print(int arr[],int n)
{
    int i;
    printf("%d",arr[1]);
//    cout<<arr[1];
    for(i = 2; i < n; i++)
    {
        printf(" %d",arr[i]);
//        cout<<" "<<arr[i];
    }
//    cout<<endl;
    printf("\n");
}

//��һ����������Ϊ��������ʱ����������ֵ����ָ�������һ��Ԫ�ص�ָ�룬���Դ�ʱ���ݸ���������ָ��Ŀ�����
int Partition(int arr[], int low, int high)
{
    arr[0] = arr[low];
    int privotKey = arr[low];//��׼Ԫ��
    while(low < high)//�ӱ�����˽������м�ɨ��
    {
        //��high ��ָλ����ǰ���������ൽlow+1 λ�á����Ȼ�׼Ԫ��С�Ľ������Ͷ�
        while(low < high && arr[high] >= privotKey)
            --high;
        arr[low] = arr[high];
        while(low < high && arr[low] <= privotKey)
            ++low;
        arr[high] = arr[low];
    }
    arr[low] = arr[0];
//    Print(arr,10);
    return low;
}
void QuickSort(int arr[], int low, int high)
{
    if(low < high)
    {
        int privotLoc = Partition(arr, low, high);//����һ��Ϊ��
        QuickSort(arr, low, privotLoc-1);//�ݹ�Ե��ӱ�ݹ�����
        QuickSort(arr, privotLoc+1, high);//�ݹ�Ը��ӱ�ӹ�����
    }
}

int N;
int main()
{
    cin>>N;
    int arr[N+1];
    GetArr(arr, N+1);
    QuickSort(arr, 1, N);
    Print(arr,N+1);
}
//#include<iostream>
//#include<algorithm>
//#include<vector>
//using namespace std;
//void Print(int arr[],int n)
//{
//    int i = 0;
//    cout<<arr[0];
//    for(i = 1; i < n; i++)
//    {
//        cout<<" "<<arr[i];
//    }
//    cout<<endl;
//}
//int main()
//{
//    int N,i;
//    cin>>N;
//    int  arr[N];
//    for(i = 0; i < N; i++)
//    {
//        cin>>arr[i];
//    }
//    sort(arr,arr+N);
//    Print(arr, N);
//}







#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
const int maxn = 1000;
int a[maxn];
int quick_ss(int low,int high)
{
    a[0] = a[low];
    int tmp = a[low];
    while(low < high)
    {
        while(low < high && a[high] >= tmp)
            high--;
        a[low] = a[high];
        while(low < high&& a[low] <= tmp)
            low++;
        a[high] = a[low];
    }
    a[low] = a[0];
    return low;
}
void quick_sort(int low,int high)
{
    if(low < high)
    {
        int mid = quick_ss(low,high);
        quick_sort(low,mid-1);
        quick_sort(mid+1,high);
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 1; i <= n; i++)
        scanf("%d",&a[i]);
    }
    quick_sort(1,n);
    for(int i = 1; i <= n; i++)
    {
        printf(" %d",a[i]);
    }
    return 0;
}










#include<bits/stdc++.h>
using namespace std;
#define MAX 1000005
void BubbleSort(int data[],int N)//ð������ ����45678������
{
    int tmp;
    for(int i=0; i<N-1; i++)
    {
        for(int j=1; j<N; j++)
        {
            if(data[j]<data[j-1])
            {
                tmp = data[j-1];
                data[j-1] = data[j];
                data[j] = tmp;
            }
        }
    }
}
void InsertSort(int data[],int N)//ֱ�Ӳ������� ����6������
{
    int tmp,j;
    for(int i=1; i<N; i++)
    {
        tmp = data[i];
        for(j=i; j>0&&data[j-1]>tmp; j--)
            data[j] = data[j-1];
        data[j] = tmp;
    }
}
void BInsertSort(int data[],int N)//�۰��������
{
    int tmp,j;
    for(int i=1; i<N; i++)
    {
        tmp = data[i];
        int low = 0,high = i-1;
        while(low<=high)
        {
            int m = (low+high)/2;
            if(data[m]>data[i])high = m-1;
            else low = m+1;
        }
        //cout<<low<<endl;
        //  int flag=1;
        for(j=i; j>low; j--)
        {
            //flag=0;
            data[j]=data[j-1];
        }
        // cout<<flag<<endl;
        data[low] = tmp;
    }
    //cout<<endl;
}
void ShellInsert(int data[],int N)//ϣ������ ����ȫ��
{
    /*for(int gap=N/2; gap>0; gap/=2)//�����𽥼���
    {
        for(int i=0; i<gap; i++)
        {
            for(int j=i+gap; j<N; j+=gap)
                if(data[j]<data[j-gap])
                {
                    int tmp  = data[j];
                    int k = j-gap;
                    while(k>=0&&data[k]>tmp)//��¼���ƣ�ֱ���ҵ�����λ��
                    {
                        data[k+gap] = data[k];
                        k-=gap;
                    }
                    data[k+gap] = tmp;
                }
        }
    }*/
    //�򻯣�
    for(int gap=N/2; gap>0; gap/=2)//�����𽥼���
    {
        for(int j=gap; j<N; j++)
            if(data[j]<data[j-gap])
            {
                int tmp  = data[j];
                int k = j-gap;
                while(k>=0&&data[k]>tmp)//��¼���ƣ�ֱ���ҵ�����λ��
                {
                    data[k+gap] = data[k];
                    k-=gap;
                }
                data[k+gap] = tmp;
            }

    }


    for(int gap = N/2; gap >0; gap/=2);
    for(int j = gap; j< N; j++)
    {
        if(data[j] < data[j-gap])
        {
            int tem = data[j];
            int k = j-gap;
            while(k >= 0 && data[k] > tem)
            {
                data[k+gap] = data[k];
                k-=gap;
            }
            data[k+gap] = tem;
        }
    }

}
void Print(int data[],int N)
{
    cout<<data[0];
    for(int i=1; i<N; i++)
        cout<<' '<<data[i];
}
//��������
int Partition(int data[],int low,int high)
{
    int tmp = data[low];
    int prvokey = data[low];
    while(low<high)
    {
        while(low<high&&data[high]>=prvokey)--high;
        data[low] = data[high];
        while(low<high&&data[low]<=prvokey)++low;
        data[high] = data[low];
    }
    data[low] = tmp;
    return low;
}
void Qsort(int data[],int low,int high)
{
    if(low<high)
    {
        int pivotloc = Partition(data,low,high);
        Qsort(data,low,pivotloc-1);
        Qsort(data,pivotloc+1,high);
    }
}
void QuickSort(int data[],int N)
{
    Qsort(data,0,N-1);
}
//��ѡ������
void SelectSort(int data[],int N)
{
    for(int i=0; i<N; i++)
    {
        int k=i;
        for(int j=i+1; j<N; j++)
            if(data[j]<data[k])
                k=j;
        if(k!=i)
        {
            int tmp = data[i];
            data[i] = data[k];
            data[k] = tmp;
        }
    }
}
//������
void HeapAdjust(int data[],int s,int m)
{
    int rc=data[s];//ȡ�����ڵ�
    for(int j=2*s; j<=m; j*=2)
    {
        if(j<m&&data[j]<data[j+1])j++;
        if(rc>=data[j])break;
        data[s]=data[j];
        s=j;
    }
    data[s]=rc;

}

void CreatHeap(int data[],int N)
{
    for(int i=N/2-1; i>=0; i--) //��������ѣ������±��0��ʼ�����һ��Ԫ�صĸ��ڵ���N/2-1
        HeapAdjust(data,i,N);
}
void HeapSort(int data[],int N)
{
    CreatHeap(data,N);
    for(int i=N-1; i>0; i--)
    {
        int x=data[0];//���Ѷ���¼�͵�ǰδ�������������е����һ����¼����
        data[0]=data[i];
        data[i]=x;
        HeapAdjust(data,0,i-1);
    }
}
//�鲢����
void Merge(int A[], int TmpA[], int L, int R, int RightEnd )
{
    //�������A[L]~A[R-1]��A[R]~A[RightEnd]�鲢��һ����������
    int LeftEnd, NumElements, Tmp;
    int i;
    LeftEnd = R - 1;    //����յ�λ��
    Tmp = L;    //�������е���ʼλ��
    NumElements = RightEnd - L + 1;     //Ԫ���ܸ���
    while( L <= LeftEnd && R <= RightEnd )
    {
        if( A[L] <= A[R] )
            TmpA[Tmp++] = A[L++];   //�����Ԫ�ظ��Ƶ�TmpA
        else
            TmpA[Tmp++] = A[R++];   //���ұ�Ԫ�ظ��Ƶ�TmpA
    }
    while( L <= LeftEnd )
        TmpA[Tmp++] = A[L++];   //ֱ�Ӹ������ʣ�µ�
    while( R <= RightEnd )
        TmpA[Tmp++] = A[R++];   //ֱ�Ӹ����ұ�ʣ�µ�
    for( i = 0; i < NumElements; i++, RightEnd-- )
        A[RightEnd] = TmpA[RightEnd];   //�������TmpA���ƻ�A
}
void Msort(int R[],int T[],int low,int high)
{
    if(low<high)
    {
        int mid = (low+high)/2;
        Msort(R,T,low,mid);
        Msort(R,T,mid+1,high);
        Merge(R,T,low,mid+1,high);
    }
}
void MergeSort(int data[],int N)
{
    int tmpA[N];
    Msort(data,tmpA,0,N-1);
}
int main()
{
    int N,M;
    int data[MAX];
    cin>>N>>M;
    for(int i=0; i<N; i++)
    {
        scanf("%d",&data[i]);
    }
    //BubbleSort(data,N);
    //InsertSort(data,N);
    //BInsertSort(data,N);
    ShellInsert(data,N);
    //QuickSort(data,N);
    //SelectSort(data,N);
    //HeapSort(data,N);
    //MergeSort(data,N);
    //Print(data,N);
    if(N<M)M=N;
    printf("%d",data[N-1]);
    for(int i=1; i<M; i++)
        printf(" %d",data[N-i-1]);
    return 0;
}
