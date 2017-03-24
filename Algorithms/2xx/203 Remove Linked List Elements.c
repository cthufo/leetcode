/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
	if (head) {
		if (head->val == val) {
			struct ListNode * next = head->next;
			free(head);
			return removeElements(next, val);
		}
		head->next = removeElements(head->next, val);
		return head;
	}
	return NULL;
}