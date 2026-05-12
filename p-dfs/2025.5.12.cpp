#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>

const int N = 1005;
std::vector<int> g[N];
bool vis[N];

void dfs(int s)
{
	std::cout << s << " ";
	vis[s] = true;

	for (int v : g[s])
	{
		if (!vis[v])
		{
			dfs(v);
		}
	}

}

int main()
{
	int n = 0, m = 0;
	std::cin >> n >> m;
	memset(vis, 0, sizeof(vis));

	//无向
	for (int i = 0; i < m; ++i)
	{
		int u, v;
		std::cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	//非连通
	for (int i = 1; i <= n; ++i)
	{
		if (!vis[i])
			dfs(i);
	}

	return 0;
}