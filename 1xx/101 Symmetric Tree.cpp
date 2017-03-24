/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSameTreeNode(TreeNode* l, TreeNode* r) {
        if (l == NULL && r == NULL) {
            return true;
        } else if (l == NULL || r == NULL) {
            return false;
        }
        if (l->val != r->val) return false;
        if (!isSameTreeNode(l->left, r->right)) return false;
        if (!isSameTreeNode(l->right, r->left)) return false;
        return true;
    }
    
    bool isSymmetric(TreeNode* root) {
        return root ? isSameTreeNode(root->left, root->right) : true;
    }
};
