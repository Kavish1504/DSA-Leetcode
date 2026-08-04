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
    int count=0;
    int leftsum=0,rightsum=0;
    pair<int,int> solve(TreeNode* root){
        if(!root){
            return {0,0};
        }
        pair<int,int> left=solve(root->left);
        pair<int,int> right=solve(root->right);
        int avg=(left.first+right.first+root->val)/(left.second+right.second+1);
        if(avg==root->val) count++;
        return {left.first+right.first+root->val,left.second+right.second+1};
    }
    int averageOfSubtree(TreeNode* root) {
        pair<int,int> temp=solve(root);
        return count;
    }
};