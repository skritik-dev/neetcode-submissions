class Solution {
    int res = INT_MIN;

    int solve(TreeNode* root) {
        if(!root) return 0;
        int left = max(0, solve(root->left)), right = max(0, solve(root->right));
        res = max(res, root->val + left + right);
        return root->val + max(left, right);
    }

public:
    int maxPathSum(TreeNode* root) {
        res = max(res, solve(root));
        return res;
    }
};
