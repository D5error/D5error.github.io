# include <iostream>
# define MAX 1000
int n; // 共有n个数，即1, 2, ..., n
int ret[MAX]; // 存储排列结果
bool used[MAX]; // 记录数是否被使用

void dfs(int depth) // 参数u表示当前已访问的深度，即ret[]已保存的数字数量
{
    if(depth == n)  // dfs的层数等于最大深度，得出排列结果
    {
        for(int i = 0; i < n; i++)
        {
            printf("%d ", ret[i]);
        }
        printf("\n");
        return ;
    }

    // 深度优先遍历
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