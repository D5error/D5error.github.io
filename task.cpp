#include<iostream>
using namespace std;
int func(int x)
{
    if(x==0)
    {
        return 0;
    }
    if(x%4==0)
    {
        int ret=0;
        while(x%4==0)
        {
            x/=4;
            ret++;
        }
        return ret+func(x);
    }
    if(x%3==0)
    {
        int ret=0;
        while(x%3==0)
        {
            x/=3;
            ret++;
        }
        return ret+func(x);
    }
    return func(x-1)+1;
}
int main()
{
    int T,x;
    cin>>T;
    for(int i=0;i<T;i++)
    {
        cin>>x;
        cout<<func(x)<<endl;
    }
    return 0;
}