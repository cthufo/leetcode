/**
 * Definition for singly-linked list.
 * struct ListNode {
 *	 int val;
 *	 struct ListNode *next;
 * };
 */
struct ListNode * reverseList(struct ListNode * head) {
	struct ListNode * prev = NULL, * current = head;
	while (current) {
		struct ListNode * temp = current->next;
		current->next = prev;
		prev = current;
		current = temp;
	}
	return prev;
}

bool hasCycle(struct ListNode *head) {
	if (!head || head->next == NULL) {
		return false;
	}
	struct ListNode * end = reverseList(head);
	reverseList(end);
	return end == head;
}