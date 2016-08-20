/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
	struct ListNode * current = head;
	struct ListNode * temp = NULL, * previous = NULL;
	while (current != NULL) {
		temp = current->next;
		current->next = previous;
		previous = current;
		current = temp;
	}
	return previous;
}