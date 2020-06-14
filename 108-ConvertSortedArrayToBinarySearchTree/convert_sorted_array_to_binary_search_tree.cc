/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
 public:
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    return toBST(nums, 0, nums.size());
  }

 private:
  TreeNode* toBST(std::vector<int>& nums, int beg, int end) {
    if (beg >= end) return nullptr;
    int mid = beg + ((end - beg) >> 1);
    TreeNode* node = new TreeNode(nums[mid]);
    node->left = toBST(nums, beg, mid);
    node->right = toBST(nums, mid + 1, end);
    return node;
  }
};