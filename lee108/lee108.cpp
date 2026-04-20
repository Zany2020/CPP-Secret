#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<string>



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
    TreeNode* build(std::vector<int>& nums, int l, int r)
    {
        if(nums.empty() || l > r)
			return nullptr;
		int mid = l + (r - l) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        
		root->left = build(nums, l, mid - 1);
        root->right = build(nums, mid + 1, r);
		return root;
    }

    TreeNode* sortedArrayToBST(std::vector<int>& nums) 
    {
		return build(nums, 0, nums.size() - 1);
    }
};

int main()
{
    std::vector<int> nums = { -10, -3, 0, 5, 9 };
    Solution s;
    s.sortedArrayToBST(nums);
    return 0;
}