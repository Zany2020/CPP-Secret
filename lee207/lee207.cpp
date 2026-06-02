#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<stack>


//class Solution 
//{
//public:
//    Solution(int numCourses, std::vector<std::vector<int>>& prerequisites) 
//    {
//        numNodes = numCourses;
//		adj.resize(numNodes);// 设置邻接表的大小
//		visited.resize(numCourses, 0);// 初始化访问状态为未访问
//
//        for(auto& e : prerequisites)
//        {
//            int u = e[1];
//            int v = e[0];
//            adj[u].push_back(v);
//        }    
//    }
//
//    std::vector<int> sort()
//    {
//        for (int i = 0; i < numNodes; ++i)
//        {
//            if (visited[i] == 0)
//            {
//                if (!dfs(i))
//                    return {};
//            }
//        }
//
//        std::vector<int> result;
//        while (!st.empty())
//        {
//            result.push_back(st.top());
//            st.pop();
//        }
//        return result;
//
//    }
//
//
//private:
//    int numNodes;
//    std::vector<std::vector<int>> adj;
//	std::vector<int> visited;
//    std::stack<int> st;
//
//    bool dfs(int node)
//    {
//		visited[node] = 1;
//
//        for (int v : adj[node])
//        {
//            if (visited[v] == 0)
//            {
//                if (!dfs(v)) return false;
//            }
//            else if (visited[v] == 1)
//            {
//                return false;
//            }
//
//			visited[node] = 2;
//			st.push(node);
//			return true;
//        }
//    }
//
//};


class Solution 
{
private:
    std::vector<std::vector<int>> adj;
    std::vector<int> visited;
	bool hasCycle = false;

    void dfs(int u)
    {
        visited[u] = 1;
        for (int v : adj[u])
        {
            if (visited[v] == 0)
            {
                dfs(v);
				if (hasCycle) return;
            }
            else if (visited[v] == 1)
            {
                hasCycle = true;
            }
        }

		visited[u] = 2;
    }


public:
    bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites)
    {
        adj.resize(numCourses);
        visited.resize(numCourses, 0);

        for (auto& edge : prerequisites)
        {
            int to = edge[0];
            int from = edge[1];
            adj[from].push_back(to);
        }

        for (int i = 0; i < numCourses; ++i)
        {
            if (visited[i] == 0)
            {
                dfs(i);
                if (hasCycle)
                    return false;
            }
        }
        return true;
    }
};