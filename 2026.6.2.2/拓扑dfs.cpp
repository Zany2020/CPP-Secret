#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stack>
#include<vector>

//adjacency（邻接）, st = stack 缩写

bool dfs(int u, std::vector<std::vector<int>>& adj,
	std::vector<int> visited, std::stack<int>& st) //visited数组是用来标记是否已经访问过了
{
	visited[u] = 1;	//1表示正在访问，2表示访问完成
	for (int v : adj[u])
	{
		if (visited[v] == 0)  // 后继未访问，递归处理
		{
			if (!dfs(v, adj, visited, st))
			{
				return false;
			}
			else if (visited[v] == 1)//从u又回到了v，形成了环
			{
				return false;
			}
		}
	}

	visited[u] = 2;//访问完成
	st.push(u);	//将访问完成的节点入栈
	return true;
}

std::vector<int> topologicalSortDFS(int numCourse, std::vector<std::vector<int>>& prerequisites)
{
	std::vector<std::vector<int>> adj(numCourse);
	for (auto& edge : prerequisites)//这里和kahn一样 
	{
		int u = edge[1];
		int v = edge[0];
		adj[u].push_back(v);
	}

	std::vector<int> visited(numCourse, 0);
	std::stack<int> st;

	for (int i = 0; i < numCourse; ++i)//遍历所有的节点，防止有的图是不相通的
	{
		if (visited[i] == 0)
		{
			if (!dfs(i, adj, visited, st))
			{
				return {};
			}
		}
	}
	
	std::vector<int> topoOrder;
	while (!st.empty())
	{
		topoOrder.push_back(st.top());
		st.pop();
	}

	return topoOrder;
}


