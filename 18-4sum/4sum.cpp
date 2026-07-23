class Solution {
public:
    void solve(vector<int>& nums,long long target,vector<vector<int>>& result,vector<int>& temp,int index,int k){
        if(k==0){
            if(target==0){
                result.push_back(temp);
            }
            return;
        }

        if(index>=nums.size()){
            return;
        }
        if(nums.size()-index<k) return;
        temp.push_back(nums[index]);
        solve(nums,target-nums[index],result,temp,index+1,k-1);
        temp.pop_back();
        int newindex=index+1;
        while(newindex<nums.size() && nums[index]==nums[newindex]){
            newindex++;
        }
        solve(nums,target,result,temp,newindex,k);
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        vector<int> ans;
        solve(nums,target,result,ans,0,4);
        return result;
    }
};