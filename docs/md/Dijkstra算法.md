# Dijkstra算法
<https://www.bilibili.com/video/BV1ha4y1T7om/?spm_id_from=pageDriver&vd_source=c65196c22fdd3605640aeccf1b3b4a0e>

![Alt text](image-575.png)

1. 数组声明
    * 声明数组`dis`保存从起点到各个顶点的最短距离

    * 声明数组`T`保存已经找到最短路径的顶点

2. 初始化条件
    * 起始点`dis[start]`的最短路径初始化为0，将与起始点`start`的邻边保存到`dis[]`中，其它顶点`dis[v]`的最短路径初始化为**无穷大**

    * 数组`T`只有起始点`start`

3. 循环
    * 从`dis[]`选取最小值，该值表示从起点`start`到该值对应顶点的最短路径

    * 把该点加入`T`中

    * 检查新加入的顶点是否可以到达其它顶点，并比较是否比从源点直达短，如果是，则**更新**`dis[]`的数值

    * 不断重复循环过程，直到`T`包含所有顶点

# Dijkstra算法实现

```c
void dijkstra()
{
	put(1);
	dis[1] = 0;
	while (heap_size > 0)
	{
		int top = get();
		if (top == t) 						/// 到达某个点就终止，此题没用到
		{
			break;
		}
		Edge *temp = first[top];
		while (temp != NULL)				/// 遍历当前点的边
		{
			if(temp->v + dis[top] < dis[temp->to])
			{
				dis[temp->to] = temp->v + dis[top];
				if(in_heap[temp->to])
				{
					shift_up(pos[temp->to]);/// 该点已入堆但没被当成最小值弹出
				}
				else
				{
					put(temp->to);          /// 该点没入堆则入堆
				}
			}
			temp = temp->next;
		}
	}
}
```