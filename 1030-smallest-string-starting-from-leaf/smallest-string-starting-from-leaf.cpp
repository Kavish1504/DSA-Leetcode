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
    string cand="";
    unordered_map<int,char> mp;
    void solve(TreeNode* root,string& temp){
        if(!root) return;
        temp+=mp[root->val];
        if(!root->left && !root->right){
            reverse(temp.begin(),temp.end());
            if(cand=="" || temp<cand){
                cand=temp;
            }
            reverse(temp.begin(),temp.end());
            temp.pop_back();
            return;
        }
        solve(root->left,temp);
        solve(root->right,temp);
        temp.pop_back();
    }
    string smallestFromLeaf(TreeNode* root) {
        for(int i=0;i<26;i++){
            mp[i]='a'+i;
        }
        string temp="";
        solve(root,temp);
        return cand;
    }
};