# Floyd算法
<https://www.bilibili.com/video/BV1mM4y117mS/?spm_id_from=333.337.search-card.all.click&vd_source=c65196c22fdd3605640aeccf1b3b4a0e>

* 主要步骤
    1. 初始化：对于图中的每一对结点$i$和$j$，如果存在一条边连接$i$和$j$，则将这条边的权重作为结点$i$和结点$j$之间的初始最短路径长度。如果不存在连接$i$和$j$的边，则将结点$i$和结点$j$之间的初始化最短路径长度初始化为无穷大

    2. 逐步更新最短路径：对于每个结点$k$，考虑结点对$i$和$j$之间的最短路径，其中路径允许经过结点$k$。如果结点$k$能够缩短结点$i$和结点$j$之间的路径长度，则更新结点$i$和结点$j$之间的最短路径长度为经过结点$k$的路径长度

    3. 重复步骤2，直到对于每一对结点$i$和$j$，都**经过了所有的中间结点**（包括结点$k$和之前的中间结点）进行考虑

# Floyd算法实现
```c
void floyd(int n)
{
	for(int k = 1; k <= n; k++)			/// k为中间结点
	{
		for(int i = 1; i <= n; i++)		/// i为起始结点
		{
			for(int j = 1; j <= n; j++)	/// j为目标结点
			{
				if(dis[i][k] + dis[k][j] < dis[i][j])
				{
					dis[i][j] = dis[i][k] + dis[k][j];
					path[i][j] = k;
				}
			}
		}
	}
}
```
