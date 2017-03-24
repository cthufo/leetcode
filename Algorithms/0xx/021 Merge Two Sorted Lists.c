struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
	if (!(l1 && l2)) {
		return l1 ? l1 : (l2 ? l2 : NULL);
	}
	struct ListNode * head = l1->val < l2->val ? l1 : l2;
	head->next = mergeTwoLists(head->next, head == l1 ? l2 : l1);
	return head;
}