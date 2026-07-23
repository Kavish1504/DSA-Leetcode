/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root,vector<TreeNode*>& ans){
        if(!root) return;
        solve(root->left,ans);
        ans.push_back(root);
        solve(root->right,ans);
    }
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> inorder;
        solve(root,inorder);

        TreeNode* first=nullptr;
        TreeNode* second=nullptr;
        for(int i=1;i<inorder.size();i++){
            if(inorder[i]->val < inorder[i-1]->val){
                if(!first) first=inorder[i-1];
                second=inorder[i];
            }
        }
        if(first && second){
            swap(first->val,second->val);
        }
    }
};