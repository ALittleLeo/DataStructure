//#include <iostream>
//using namespace std;
//
//void GetArr(int arr[],int n)
//{
//    int i;
//    for(i = 0; i < n; i++)
//    {
//        cin>>arr[i];
//    }
//}
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
//void Swap(int *a, int *b)
//{
//    int tem = *a;
//    *a = *b;
//    *b = tem;
//}
//int Partition(int arr[], int low, int high)
//{
//    int privotKey = arr[low];//��׼Ԫ��
//    while(low < high)//�ӱ�����˽������м�ɨ��
//    {
//        //��high ��ָλ����ǰ���������ൽlow+1 λ�á����Ȼ�׼Ԫ��С�Ľ������Ͷ�
//        while(low < high && arr[high] >= privotKey)
//            --high;
////        cout<<arr[low]<<" "<<arr[high]<<" ";
//        Swap(&arr[low],&arr[high]);
////        cout<<arr[low]<<" "<<arr[high]<<endl;
//
//        while(low < high && arr[low] <= privotKey)
//            ++low;
//        Swap(&arr[low],&arr[high]);
//    }
////    Print(arr,10);
//    return low;
//}
//void QuickSort(int arr[], int low, int high)
//{
//    if(low < high)
//    {
//        int privotLoc = Partition(arr, low, high);//����һ��Ϊ��
//        QuickSort(arr, low, privotLoc-1);//�ݹ�Ե��ӱ�ݹ�����
//        QuickSort(arr, privotLoc+1, high);//�ݹ�Ը��ӱ�ӹ�����
//    }
//}
//int main()
//{
//    int N,M;
//    cin>>N>>M;
//    if(N < M)
//        M = N;
//    int arr[N];
//    GetArr(arr, N);
//    QuickSort(arr, 0, N-1);
//    int i;
//    cout<<arr[N-1];
//    for(i = N-2; i >= N-M; i--)
//    {
//        cout<<" "<<arr[i];
//    }
//    return 0;
//}
#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
    int N,M,i;
//    cin>>N>>M;
    //scanfҪ��cin��ܶ࣬�������ݵ����������scanf
    scanf("%d%d",&N,&M);
    if(N < M)
        M = N;
    int arr[N];
    for(i = 0; i < N; i++)
    {
        scanf("%d",&arr[i]);
    }
    sort(arr,arr+N);
    printf("%d",arr[N-1]);
    for(i = N-2; i >= N-M;i--)
    {
        printf(" %d",arr[i]);
    }
}
