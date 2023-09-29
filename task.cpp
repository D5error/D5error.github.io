#include<iostream>
#include<cmath>
using namespace std;
#define kType long long
kType func(int m,int n)
{
    if(m==0)
    {
        return 1;
    }
    kType k=0;
    for(int i=1;i<=n;i++)
    {
        k+=func(m-1,i);
    }
    return k;
}
kType ans[100];
kType factorial(int n)
{
    if(n==1)
    {
        ans[1]=1;
    }
    else 
    {
        ans[n]=ans[n-1]*n;
    }
    return ans[n];
}
kType C(int m,int n)
{
    //return pow(n,m);
    return factorial(m+n-1)/factorial(m)/factorial(n-1);
}
int main()
{
    kType k=0;
    int n,m;
    cout<<"请输入m和n："<<endl;
    cin>>m>>n;
    for(int x=1;x<=m;x++)
    {
        for(int i=1;i<=n;i++)
        {
            printf("%5ld ",func(x,i));
        }
        cout<<endl<<endl;
    }
    cout<<endl;
    for(int x=1;x<=m;x++)
    {
        for(int i=1;i<=n;i++)
        {
            printf("%5ld ",C(x,i));
        }
        cout<<endl<<endl;
    }
    return 0;
}