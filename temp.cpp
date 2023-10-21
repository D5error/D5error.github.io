#include<iostream>
using namespace std;
int main()
{
    int *a=new int[10];
    for(int i=0;i<10;i++)
    {
        a[i]=i*100;
    }
    for(int i=0;i<10;i++)
    {
        cout<<a[i]<<endl;
    }
    cout<<endl;
    delete []a;

    
    for(int i=0;i<10;i++)
    {
        cout<<a[i]<<endl;
    } 
    
    cout<<endl;
    delete []a;

    
    for(int i=0;i<10;i++)
    {
        cout<<a[i]<<endl;
    } 
    return 0;
}