struct TreeNode* invertTree(struct TreeNode* root) {
	if (root == NULL) {
		return NULL;
	}
	struct TreeNode *leftTemp = root->left;
	root->left = invertTree(root->right);
	root->right = invertTree(leftTemp);
	return root;
}

