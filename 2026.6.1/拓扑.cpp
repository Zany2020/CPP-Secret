#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>

std::vector<int> topologicalSortKanhn(int numCount, std::vector<std::vector<int>>& pre)
{
	std::vector<std::vector<int>> adj(numCount);
	std::vector<int> inDegree(numCount, 0);

	for (std::vector<int>& edge : pre)
	{
		int u = edge[1];
		int v = edge[0];
		adj[u].push_back(v);
		inDegree[v]++;
	}

}