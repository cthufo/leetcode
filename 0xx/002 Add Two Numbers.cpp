/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* root = new ListNode(0), * current = root;
        while (l1 != NULL || l2 != NULL) {
            current->val += (l1 == NULL ? 0 : l1->val) + (l2 == NULL ? 0 : l2->val);
            l1 = l1 == NULL ? NULL : l1->next, l2 = l2 == NULL ? NULL : l2->next;
            current->next = (current->val / 10 || l1 || l2) ? new ListNode(current->val / 10) : NULL;
            current->val %= 10;
            current = current->next;
        }
        return root;
    }
};
