#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<queue>



struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};


class Solution
{
private:
	std::vector<std::vector<int>> ans;  
public:
    void dfs(TreeNode* root, int depth)
    {
        if (root == nullptr)   return;
        if(depth >= ans.size())
			ans.push_back({root->val});
        else
			ans[depth].push_back(root->val);

        dfs(root->left, depth + 1);
		dfs(root->right, depth + 1);
    }


    std::vector<std::vector<int>> levelOrder(TreeNode* root)
    {
        dfs(root, 0);
        return ans;
    }
};

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    Solution sol;
    std::vector<std::vector<int>> result = sol.levelOrder(root);
    for (const auto& level : result)
    {
        for (int val : level)
        {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}