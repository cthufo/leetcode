void deleteNode(struct ListNode* node) {
	if (node->next) {
		node->val = node->next->val;
		struct ListNode * temp = node->next;
		node->next = node->next->next;
		free(temp);
	} else {
		free(node);
	}
}