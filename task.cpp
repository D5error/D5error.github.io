//    D5:2023/9/21
#include<iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
void Delete_a_to_b(struct node *head,int a,int b)
{
    struct node *p=head,*temp;
    while(p->next!=NULL)
    {
        temp=p->next;
        if(temp->data>a && temp->data<b)
        {
            p->next=temp->next;
            free(temp);
        }
    }
}