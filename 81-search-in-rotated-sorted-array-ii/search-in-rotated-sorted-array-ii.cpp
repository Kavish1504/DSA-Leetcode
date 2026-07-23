class Solution {
public:
    bool solve(vector<int>& nums,int target,int left,int right){
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]==target){
                return true;
            }
            else if(nums[mid]>target){
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return false;
    }
    bool search(vector<int>& nums, int target) {
        if(nums.size()==1){
            return nums[0]==target;
        }
        int split_index=-1;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]){
                split_index=i;
                break;
            }
        }
        if(split_index==-1){
            return solve(nums,target,0,nums.size()-1);
        }
        bool left=solve(nums,target,0,split_index);
        bool right=solve(nums,target,split_index+1,nums.size()-1);
        return left||right;
    }
};