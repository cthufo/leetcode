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
    int findBottomLeftValue(TreeNode* root, int level, int * answer) {
        if (root == NULL) {
            return level - 1;
        }
        int temp[2] = {root->val, root->val};
        int l = findBottomLeftValue(root->left, level + 1, &temp[0]);
        int r = findBottomLeftValue(root->right, level + 1, &temp[1]);
        *answer = l >= r ? temp[0] : temp[1];
        return l > r ? l : r;
    }
    int findBottomLeftValue(TreeNode* root) {
        int answer = 0;
        findBottomLeftValue(root, 0, &answer);
        return answer;
    }
};
