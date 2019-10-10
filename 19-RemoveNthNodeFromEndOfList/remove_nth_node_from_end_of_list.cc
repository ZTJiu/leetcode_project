/******************************************
* File  : remove_nth_node_from_end_of_list.cc
* Date  : 2018-10-17
* Author: Zhang Tianjiu
* Email : zhangtianjiu@vip.qq.com
*******************************************/

#include <iostream>
#include <vector>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* new_head = head;
        if (head == nullptr || n <= 0) {
            return new_head;
        }

        ListNode* pre_slow = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;
        while (--n > 0) {
            fast = fast->next;
            if (fast == nullptr) {
                return new_head;
            }
        }

        while (fast->next != nullptr) {
            fast = fast->next;
            pre_slow = slow;
            slow = slow->next;
        }

        if (pre_slow == nullptr) {
            new_head = head->next;
            delete head;
        } else {
            pre_slow->next = slow->next;
            delete slow;
        }

        return new_head;
    }
};

int main(void) {
    std::vector<int> nums = { 1, 2, 3, 4, 5 };
    ListNode* head = new ListNode(1);
    ListNode* tail = head;
    for (int i = 2; i <= 5; ++i) {
        ListNode* node = new ListNode(i);
        tail->next = node;
        tail = node;
    }

    for (ListNode* h = head; h != nullptr; h = h->next) {
        std::cout << h->val << "\t";
    }
    std::cout << std::endl;

    Solution s;
    ListNode* new_head = s.removeNthFromEnd(head, 5);

    for (ListNode* h = new_head; h != nullptr; h = h->next) {
        std::cout << h->val << "\t";
    }
    std::cout << std::endl;

    std::cout << (new_head == head) << std::endl;

    return 0;
}
