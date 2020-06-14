
//  Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  bool isValidBST(TreeNode *root) {
    if (!root) return true;
    return isValidateBSTCore(root, nullptr, nullptr);
  }

 private:
  bool isValidateBSTCore(TreeNode *root, TreeNode *min, TreeNode *max) {
    if ((min && root->val <= min->val) || (max && root->val >= max->val))
      return false;
    return ((!root->left || isValidateBSTCore(root->left, min, root)) &&
            (!root->right || isValidateBSTCore(root->right, root, max)));
  }
};