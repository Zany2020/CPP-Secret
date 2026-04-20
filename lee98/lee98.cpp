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
 
//class Solution 
//{
//public:
//    TreeNode* inorder(TreeNode* root, std::vector<int>& v)
//    {
//        if (!root) return nullptr;
//
//		inorder(root->left, v);
//		v.push_back(root->val);
//		inorder(root->right, v);     
//
//		return root;
//    }
//
//
//    bool isValidBST(TreeNode* root)
//    {
//        std::vector<int> v;
//        inorder(root, v);
//
//        for (int i = 1; i < v.size(); i++)
//        {
//            if (v[i] <= v[i - 1]) return false;
//		}
//        return true;
//    }
//};



  //递归上下界标准解法
  class Solution 
  {
  public:
      bool dfs(TreeNode* root, long long low, long long high) 
      {
          if (!root) return true;

          if (root->val <= low || root->val >= high)
          {
              return false;
          }

          // 递归左子树：左子树必须 < 当前值，上界更新为root->val
          bool left = dfs(root->left, low, root->val);

          // 递归右子树：右子树必须 > 当前值，下界更新为root->val
          bool right = dfs(root->right, root->val, high);

          return left && right;
      }

      bool isValidBST(TreeNode* root) 
      {
          // 根节点无上下界，用long long极值防止int溢出
          return dfs(root, LLONG_MIN, LLONG_MAX);
      }
  };


int main()
{
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    Solution s;
    std::cout << s.isValidBST(root) << std::endl;
    return 0;
}