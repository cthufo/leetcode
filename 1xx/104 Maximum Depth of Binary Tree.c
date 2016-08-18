int maxDepth(struct TreeNode* root) {
	if (root == NULL) {
		return 0;
	}
	int leftDepth = maxDepth(root->left) + 1;
	int rightDepth = maxDepth(root->right) + 1;
	return leftDepth > rightDepth ? leftDepth : rightDepth;
}
