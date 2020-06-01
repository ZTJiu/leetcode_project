#include <iostream>
#include <vector>

struct TreeNode {
  int val;
  struct TreeNode* left;
  struct TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr);
};

/*
bool isSymmetricCore(TreeNode* root1, TreeNode* root2) {
  if (!root1 && !root2) return true;
  if (root1 && root2) {
    if (root1->val != root2->val) return false;
    return isSymmetricCore(root1->left, root2->right) &&
           isSymmetricCore(root1->right, root2->left);
  }
  return false;
}
bool isSymmetric(TreeNode* root) {
  if (!root) return true;
  return isSymmetricCore(root->left, root->right);
}*/

// none-recursively
bool isSymmetric(TreeNode* root) {
  if (!root) return true;
  std::queue<TreeNode*> queue;
  queue.push(root->left);
  queue.push(root->right);
  int level_num = 2;
  while (!queue.empty()) {
    if (level_num % 2 != 0) return false;
    std::vector<TreeNode*> level_nodes(level_num, nullptr);
    int new_level_num = 0;
    for (int i = 0; i < level_num; ++i) {
      auto tmp = queue.front();
      queue.pop();
      level_nodes[i] = tmp;
      if (tmp) {
        queue.push(tmp->left);
        queue.push(tmp->right);
        new_level_num += 2;
      }
    }
    level_num = new_level_num;
    for (int l = 0, r = level_nodes.size() - 1; l < r; ++l, --r) {
      if (level_nodes[l] && level_nodes[r]) {
        if (level_nodes[l]->val != level_nodes[r]->val) return false;
      } else {
        if (level_nodes[l] || level_nodes[r]) return false;
      }
    }
  }
  return true;
}