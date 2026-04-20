#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
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
    TreeNode* inorder(TreeNode* root, std::vector<int>& v)
    {
        if (!root) return nullptr;

        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);    

		return root;
	}

    int kthSmallest(TreeNode* root, int k) 
    {
		std::vector<int> v;
        inorder(root, v);
        return v[k - 1];
    }
};