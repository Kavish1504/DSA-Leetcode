class Solution {
public:
    void solve(TreeNode* root, int& mini, int& second_min,bool& flag) {
        if(!root) return;

        if(root->val < mini) {
            second_min=mini;
            mini = root->val;
        }
        else if(root->val>mini){
            if(!flag || root->val<second_min){
                second_min=root->val;
                flag=true;
            }
        }

        solve(root->left, mini, second_min,flag);
        solve(root->right, mini, second_min,flag);
    }

    int findSecondMinimumValue(TreeNode* root) {
        int mini = INT_MAX;
        int second_min = INT_MAX;
        bool flag=false;
        solve(root,mini,second_min,flag);
        return flag?second_min:-1;
    }
};