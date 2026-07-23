class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> steps(nums.size(),INT_MAX);
        steps[0]=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<=i+nums[i] && j<n;j++){
                steps[j]=min(steps[j],1+steps[i]);
            }
        }
        return steps[n-1];
    }
};