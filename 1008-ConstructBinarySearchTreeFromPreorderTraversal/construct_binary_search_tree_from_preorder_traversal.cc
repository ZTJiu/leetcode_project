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
  TreeNode* bstFromPreorder(vector<int>& preorder) {
    return bstFromPreorder(preorder, 0, preorder.size());
  }

 private:
  TreeNode* bstFromPreorder(std::vector<int>& pre, int beg, int end) {
    if (beg >= end) return nullptr;
    TreeNode* root = new TreeNode(pre[beg]);
    int rbeg = beg;
    while (rbeg < end) {
      if (pre[rbeg] <= pre[beg])
        ++rbeg;
      else
        break;
    }
    root->left = bstFromPreorder(pre, beg + 1, rbeg);
    root->right = bstFromPreorder(pre, rbeg, end);
    return root;
  }
};