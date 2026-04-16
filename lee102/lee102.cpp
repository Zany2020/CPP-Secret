#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<queue>



  struct TreeNode
  {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution
{
public:
    std::vector<std::vector<int>> levelOrder(TreeNode* root)
    {
        std::vector<std::vector<int>> res;
        if (root == nullptr) return res;

        std::queue<TreeNode> q;
        q.push(*root);

        while (!q.empty())
        {
			int size = q.size();
			std::vector<int> level;

			for (int i = 0; i < size; ++i)
            {
                TreeNode node = q.front();
                q.pop();

				level.push_back(node.val);

                if (node.left)
                    q.push(*node.left);
                if (node.right)
                    q.push(*node.right);
            }
			res.push_back(level);
        }
		return res;

    }
};

int main()
{
	Solution s;
    std::vector<std::vector<int>> result = s.levelOrder(nullptr);
    for(int i = 0; i < result.size(); ++i)
    {
        for(int j = 0; j < result[i].size(); ++j)
        {
            std::cout << result[i][j] << " ";
        }
        std::cout << std::endl;
	}
}