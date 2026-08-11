class Solution {
    template<typename T>
    using v = vector<T>;

public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};

        v<v<int>> res;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int size = q.size();

            vector<int> temp;
            temp.reserve(size);

            // Get all the current level elements, and add their children
            while(size--) {
                TreeNode *peek = q.front(); q.pop();
                temp.emplace_back(peek->val);
                if(peek->left) q.push(peek->left);
                if(peek->right) q.push(peek->right);
            }

            res.emplace_back(temp);
        }

        return res;
    }
};
