class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        if(!root) return false;

        queue<TreeNode*> q;
        q.push(root);

        bool nullSeen = false;

        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if(node == nullptr) {
                nullSeen = true;
                continue;
            }

            if(nullSeen)
                return false;

            q.push(node->left);
            q.push(node->right);
        }

        return true;
    }
};