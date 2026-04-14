#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>


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
    TreeNode* invertTree(TreeNode* root)
    {
        if (!root) return root;
		std::swap(root->left, root->right);
		invertTree(root->left);
		invertTree(root->right);
        return root;
    }
};