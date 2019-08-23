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
    static int check(TreeNode* curr, int sum, int target) {
        if (!curr) return 0;
        int currSum = curr->val + sum;
        bool isTarget = currSum == target;
        return isTarget + check(curr->left, currSum, target) + check(curr->right, currSum, target);
    }
public:
    int pathSum(TreeNode* root, int sum) {
        if (!root) return 0;
        return check(root, 0, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
};