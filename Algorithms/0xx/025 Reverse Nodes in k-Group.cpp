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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1) {
            return head;
        }
        int index = 0;
        ListNode *reverseHead = NULL, *reverseTail = NULL, *reverseTail2 = NULL, *current = head;
        while (current != NULL) {
            ListNode * tempNode = current->next;
            if (index % k == 0) {
                reverseHead = reverseTail = current;
                reverseTail->next = NULL;
            } else if (index % k == k - 1) {
                reverseTail->next = current->next;
                current->next = reverseHead;
                if (index == k - 1) {
                    head = current;
                } else {
                    reverseTail2->next = current;
                }
                reverseTail2 = reverseTail;
                reverseHead = reverseTail = NULL;
            } else {
                current->next = reverseHead;
                reverseHead = current;
            }
            index++;
            current = tempNode;
        }
        if (index % k) {
            reverseKGroup(reverseHead, index % k);
        }
        return head;
    }
};
