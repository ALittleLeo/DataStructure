#include<iostream>
#include<string>
#include<stack>
#include<stdio.h>
using namespace std;

int main()
{
    int n,content,i;
    cin>>n>>content;
    getchar();
    for(i = 0; i < n; i++)
    {
        int flag = 0;
        string str;
        stack<char> small;
        getline(cin,str);
        for(int i=0; i<str.size(); i++)
        {
//            cout<<str[i]<<endl;
            switch(str[i])
            {
            case 'S':
                small.push(str[i]);    //����������ѹ��ȥ
                break;
            case 'X':
                if(!small.empty())
                {
                    small.pop();     //����������������
                    break;
                }
                if(small.empty())     //ѭ���ʽ���������ʱΪ����ʧ�䣬
                {
                    flag = 1;
                    break;
                }

            }
            if(small.size() > content)
            {
                flag = 1;
                break;
            }


        }
        if(small.empty()&&flag == 0)   //ѭ�������󣬴�ʱΪ����ƥ��
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
        while(!small.empty())
            small.pop();
    }

    return 0;
}
