#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<algorithm>
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
//    std::vector<int> inorderTraversal(TreeNode* root) 
//    {
//        if (root == nullptr) return {};
//		inorderTraversal(root->left);
//		std::cout << root->val << " ";
//		inorderTraversal(root->right);
//		return {};
//    }
//};


 class Solution
 {
 public:
     void inorder(TreeNode* root, std::vector<int>& result)
     {
         if (!root) return;
         inorder(root->left, result);
		 result.push_back(root->val);
		 inorder(root->right, result);
     }

     std::vector<int> inorderTraversal(TreeNode* root)
     {
         std::vector<int> res;
         inorder(root, res);
		 return res;
     }
 };


int main()
{
    Solution s;
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    s.inorderTraversal(root);
    return 0;
}