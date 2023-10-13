#include <iostream>
using namespace std;
int i;
int *func()
{
    return &i;
}
int main()
{
    cout<<"你好";
    return 0;
}