# Bellman-ford算法
<https://www.bilibili.com/video/BV18C4y137ck/?spm_id_from=333.999.0.0&vd_source=c65196c22fdd3605640aeccf1b3b4a0e>

* 初始化距离数组：将起始顶点到所有其它顶点的距离初始化为无穷大，将起始顶点到自身的距离为0

* 进行$n - 1$次松弛操作：对于每条边$（u，v）$，如果从起始顶点到$u$的距离加上边$（u，v）$小于起始顶点到$v$的距离，**则覆盖**

* 检测负权环：再进行一次松弛操作，如果仍然存在从起始顶点到某个顶点可以更新，则**说明图中存在负权环**

* 输出最短路径：如果不存在负权环，则距离数组中存储的即为起始顶点到各个顶点的最短距离

# Bellman-ford算法实现

```c
void Bellman_ford()
{
	for (int i = 1; i <= n; i++)
	{
		dist[i] = MAXINT;						/// 初始化到所有点的距离为无穷大
	}
	dist[1] = 0;								/// 到起点的距离为0
	for (int i = 1; i <= n - 1; i++)			/// 进行n - 1次松弛操作
	{
		// add sth. here
		for(int j = 1; j <= n; j++)				/// 对每条边进行松弛操作（遍历顶点的出边）
		{
			for(int k = f[j] + 1; k <= f[j + 1]; k++)/// 遍历出边
			{
				int v = linkto[k];
				if(dist[j] + cost[k] < dist[v])	/// 进行松弛操作
				{
					dist[v] = dist[j] + cost[k];
				}
			}
		}
	}
	for (int j = 1; j <= n; j++)				/// 检查是否存在负环
	{
		for(int k = f[j] + 1; k <= f[j + 1]; k++)
		{
			int v = linkto[k];
			if(dist[j] + cost[k] < dist[v])
			{
				printf("negative cycle!\n");
				break;
			}
		}
	}
}
```