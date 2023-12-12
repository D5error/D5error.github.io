# include <iostream>
# define MAX 1000
int n; // ����n��������1, 2, ..., n
int ret[MAX]; // �洢���н��
bool used[MAX]; // ��¼���Ƿ�ʹ��

void dfs(int depth) // ����u��ʾ��ǰ�ѷ��ʵ���ȣ���ret[]�ѱ������������
{
    if(depth == n)  // dfs�Ĳ������������ȣ��ó����н��
    {
        for(int i = 0; i < n; i++)
        {
            printf("%d ", ret[i]);
        }
        printf("\n");
        return ;
    }

    // ������ȱ���
    for(int i = 1; i <= n; i++)
    {
        if(!used[i])
        {
            ret[depth] = i;
            used[i] = true;
            dfs(depth + 1);
            used[i] = false;
        }
    }
}


int main()
{
    n = 4;
    dfs(0);
    return 0;
}