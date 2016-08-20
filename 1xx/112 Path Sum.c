/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool hasPathSum(struct TreeNode* root, int sum) {
	if (root) {
		if (sum - root->val == 0 && !root->left && !root->right) {
			return true;
		} else {
			return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
		}
	}
	return false;
}