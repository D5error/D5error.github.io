#include<iostream>
using namespace std;
int main()
{
    int n=1;
    {
        cout<<n<<endl;
        printf("%x\n",&n);
        int n=2;
        cout<<n<<endl;
        printf("%x\n",&n);
        {
            int n=3; 
            cout<<n<<endl;
            printf("%x\n",&n);
        }
    }
    cout<<n<<endl;
    printf("%x\n",&n);
    return 0;
}