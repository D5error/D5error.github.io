#include<iostream>
int i1,i2,i3,i4,n,k;
using namespace std;
int main()
{
    while (true)
    {
    k=0;
    cin>>n;
    cout<<"当n等于"<<n<<"时"<<endl;
    for(i1=1;i1<=n;i1++)
        for(i2=1;i2<=i1;i2++)
            for(i3=1;i3<=i2;i3++)
                for(i4=1;i4<=i3;i4++)
                    k++;

    cout<<"第一种结果："<<k<<endl;
    k=0;
    for(i1=1;i1<=n;i1++)
        for(i2=i1;i2>=1;i2--)
            for(i3=i2;i3>=1;i3--)
                for(i4=i3;i4>=1;i4--)
                    k++;
    cout<<"第二种结果："<<k<<endl;
    }
    return 0;
}