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
    int solve(TreeNode* root,unordered_map<int,int>& mp){
        if(!root){
            return 0;
        }
        int left_sum=solve(root->left,mp);
        int right_sum=solve(root->right,mp);
        int sum=left_sum+right_sum+root->val;
        mp[sum]++;
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int,int> mp;
        int ans=solve(root,mp);
        int max_freq=INT_MIN;
        for(auto num:mp){
            max_freq=max(max_freq,num.second);
        }
        vector<int> temp;
        for(auto num:mp){
            if(num.second==max_freq){
                temp.push_back(num.first);
            }
        }
        return temp;
    }
};