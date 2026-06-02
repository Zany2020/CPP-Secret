#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>

std::vector<int> topologicalSortKanhn(int numCourses, std::vector<std::vector<int>>& pre)
{
	std::vector<std::vector<int>> adj(numCourses);//邻接表
	std::vector<int> inDegree(numCourses, 0);

	for (std::vector<int>& edge : pre)
	{
		int u = edge[1];//u是前置课程
		int v = edge[0];//v是后续课程
		adj[u].push_back(v);
		inDegree[v]++;//inDegree是到达v的边的数量
	}

	std::queue<int> q;
	for (int i = 0; i < numCourses; ++i)
	{
		if (inDegree[i] == 0)
		{
			q.push(i);//让其先从零开始
		}
	}

	std::vector<int> topoOrder;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		topoOrder.push_back(u);

		for (int v : adj[u])
		{
			inDegree[v]--;
			if (inDegree[v] == 0)//到达v的边都被处理了，可以加入队列了
			{
				q.push(v);
			}
		}
	}

	if (topoOrder.size() != numCourses)
	{
		return {};//为环
	}

	return topoOrder;
}

int main()
{
	int numCourses = 4;
	std::vector<std::vector<int>> pre = { {1,0}, {2,0}, {3,1}, {3,2} };
	std::vector<int> result = topologicalSortKanhn(numCourses, pre);
	for (int course : result)
	{
		std::cout << course << " ";
	}
	std::cout << std::endl;
	return 0;
}