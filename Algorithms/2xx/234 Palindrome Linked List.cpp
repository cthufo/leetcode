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
    bool isPalindrome(ListNode * head) {
        int count = 0;
        ListNode * tail = NULL, * current = head;
        while (current && ++count) current = current->next;
        count = count / 2 + count % 2, current = head;
        while (count-- && current) current = current->next;
        while (current != NULL) {
            ListNode * temp = current->next;
            current->next = tail;
            tail = current;
            current = temp;
        }
        while (head != NULL && tail != NULL) {
            if (head->val != tail->val) {
                return false;
            }
            head = head->next;
            tail = tail->next;
        }
        return true;
    }
};
