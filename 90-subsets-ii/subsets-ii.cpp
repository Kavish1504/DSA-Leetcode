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

        int next_index=index+1;
        while(next_index<nums.size() && nums[index]==nums[next_index]){
            next_index++;
        }
        solve(nums,next_index,result,temp);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        vector<int> temp;
        solve(nums,0,result,temp);
        // temp.clear();
        // result.push_back(temp);
        return result;
    }
};