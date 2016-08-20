/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
	int pVal = head ? head->val : 0;
	struct ListNode * current = head, * temp = NULL;
	while (current) {
		if (current->next && current->next->val == pVal) {
			temp = current->next;
			current->next = current->next->next;
			free(temp);
		} else {
			current = current->next;
			pVal = current ? current->val : 0;
		}
	}
	return head;
}