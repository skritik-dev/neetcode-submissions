class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return nullptr;

        // Post order traversal
        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty()) {
            auto peek = q.front(); q.pop();
            TreeNode *temp = peek->left;
            peek->left = peek->right;
            peek->right = temp;
            if(peek->left) q.push(peek->left);
            if(peek->right) q.push(peek->right);
        }

        return root;
    }
};
