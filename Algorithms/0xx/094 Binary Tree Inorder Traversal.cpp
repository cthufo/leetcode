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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        vector<TreeNode *> stack;
        TreeNode * current = root;
        if (current) stack.push_back(current);
        while (stack.size()) {
            if (current == NULL) {
                current = stack.back();
                stack.pop_back();
                inorder.push_back(current->val);
                if (current->right) stack.push_back(current->right);
                current = current->right;
                continue;
            }
            if (current->left) stack.push_back(current->left);
            current = current->left;
            continue;
        }
        return inorder;
    }
};
