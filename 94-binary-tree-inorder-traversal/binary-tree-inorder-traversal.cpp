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
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return {};
        stack<pair<TreeNode*,bool>> st;
        st.push({root,false});
        vector<int> result;
        while(!st.empty()){
            auto top=st.top();
            st.pop();
            if(top.second){
                result.push_back(top.first->val);
            }
            else{
                if(top.first->right)
                st.push({top.first->right,false});
                st.push({top.first,true});
                if(top.first->left)
                st.push({top.first->left,false});
            }
        }
        return result;
    }
};