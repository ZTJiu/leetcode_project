/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
  TreeNode* sortedListToBST(ListNode* head) {
    if (!head) return nullptr;
    return toBST(head, nullptr);
  }

 private:
  TreeNode* toBST(ListNode* head, ListNode* tail) {
    if (head == tail) return nullptr;
    if (head->next == tail) {
      TreeNode* root = new TreeNode(head->val);
      return root;
    }
    if (head->next->next == tail) {
      TreeNode* root1 = new TreeNode(head->val);
      TreeNode* root2 = new TreeNode(head->next->val);
      root2->left = root1;
      return root2;
    }
    ListNode* slow = head;
    ListNode* fast = head->next;
    while (fast != tail && fast->next != tail) {
      slow = slow->next;
      fast = fast->next->next;
    }
    TreeNode* root = new TreeNode(slow->val);
    root->left = toBST(head, slow);
    root->right = toBST(slow->next, tail);
    return root;
  }
};
