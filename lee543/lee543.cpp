#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>	
#include<cstring>
#include<vector>


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
	int res = 0;

    int maxDepth(TreeNode* root)
    {
        if(!root)	return 0;
		int left = maxDepth(root->left);
		int right = maxDepth(root->right);

        res = std::max(res, left + right);
		return std::max(left, right) + 1;//返回以当前节点为根的树的深度
	}

    int diameterOfBinaryTree(TreeNode* root)
    {
        maxDepth(root);
        return res;
    }
};