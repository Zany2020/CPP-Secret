#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
#include<vector>


std::vector<int> dijkstra
(int n, std::vector<std::vector<std::pair<int, int >>>& adj, int start)
						//adj是邻接表，pair<int, int> = (邻居节点号，权重)
{
	const int INF = INT_MAX / 2;//无穷大
	std::vector<int> dist(n, INF);//初始化距离数组，初始值为无穷大，好让他在第一次比较if时更新为正确的距离
	dist[start] = 0;


	//priority_queue< 元素类型, 底层容器, 比较规则 >
	std::priority_queue<std::pair<int, int>,  //pair<int, int> = (距离，节点号)
		std::vector<std::pair<int, int>>, //固定写 vector 就行，不用管
		std::greater<std::pair<int, int>>> pq; //greater：从小到大排序，让堆顶永远是 距离最小的元素

	pq.emplace(0, start);

	while (!pq.empty())
	{
		//auto [d, u] = pq.top();
		int d = pq.top().first; //距离，d是下面pq进栈后的结果
		int u = pq.top().second; //节点
		pq.pop();

		if (d > dist[u]) continue; 
		//d指的是弹出那个节点（当前在处理的节点）的距离（在下面for中压进去的），现在才处理是否消除
		// 大于dist[u]的话，说明这个节点已经被更新过了，之前的距离更短，所以跳过本次循环，继续处理下一个节点。
									//u指的是弹出的那节点的距离
							       //如果大于的话，跳过本次然后pop弹出

		// 遍历 u 的所有邻居，更新距离
		for (const auto& edge : adj[u])//每次while循环都要遍历一次adj【u】！！！是【u】
		{						//这里的u代表下面输入的，从u到v的距离是w
			int v = edge.first; //看输入，这里的v指的是从u到v（输入的那个节点号）的距离是w的意思
			int w = edge.second; 
			if (dist[v] > dist[u] + w) //这个w是输入进去的数值，u是弹出的那个节点
				//满足说明通过u到达v的距离更短
			{
				dist[v] = dist[u] + w; //更新到这个节点号的权重
				pq.emplace(dist[v], v);
			}
		}
	}
	return dist;
}

int main()
{
	int n = 4;
	std::vector<std::vector<std::pair<int, int>>> adj(n);

	adj[0].push_back({ 1, 1 });
	adj[1].push_back({ 0, 1 });
	adj[0].push_back({ 2, 4 });
	adj[1].push_back({ 2, 2 });
	adj[2].push_back({ 3, 3 });

	auto dist = dijkstra(n, adj, 0);

	for (int i = 0; i < n; i++) {
		std::cout << "0 -> " << i << " : " << dist[i] << std::endl;
	}
	return 0;
}