#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

#include<vector>
#include<queue>


const int max_n = 1005;
std::vector<int> g[max_n];
	//访问标记：true=已访问，false=未访问
bool vis[max_n];

void bfs(int s)
{
	std::queue<int> q;
	q.push(s);
	vis[s] = true;

	while (!q.empty())
	{
		int layer_size = q.size();

		for (int i = 0; i < layer_size; ++i)
		{
			int u = q.front();
			q.pop();
			std::cout << u << " ";

			for (int v : g[u])
			{
				if (!vis[v])
				{
					vis[v] = true;
					q.push(v);
				}
			}
		}
	}
}

int main()
{
	int n, m = 0;
	std::cin >> n >> m;

	memset(vis, 0, sizeof(vis));

		for (int i = 0; i < m; ++i)
	{
		int u, v;
		std::cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);//删了这行就变成有向图了
	}

	// 处理非连通图：多个不相连的部分
	for (int i = 1; i <= n; i++)
	{
		if (!vis[i])//// 如果这个点还没被访问过
			bfs(i);
	}

	return 0;
}