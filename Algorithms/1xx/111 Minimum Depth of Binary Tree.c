/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int minDepth(struct TreeNode* root) {
	if (!root) {
		return 0;
	} else if (root->left && root->right) {
		int left = minDepth(root->left);
		int right = minDepth(root->right);
		return 1 + (left > right ? right : left);
	}
	return !root->left && !root->right ? 1 : 1 + minDepth(root->left ? root->left : root->right);
}