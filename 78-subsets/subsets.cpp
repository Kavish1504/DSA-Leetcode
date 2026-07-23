class Solution {
public:
    void solve(vector<int>& nums,int index,vector<vector<int>>& result,vector<int> &temp){
        if(index>=nums.size()){
            result.push_back(temp);
            return;
        }
        temp.push_back(nums[index]);
        solve(nums,index+1,result,temp);
        temp.pop_back();
        solve(nums,index+1,result,temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;
        solve(nums,0,result,temp);
        return result;
    }
};