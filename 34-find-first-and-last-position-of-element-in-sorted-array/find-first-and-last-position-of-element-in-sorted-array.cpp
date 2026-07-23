class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left=0,right=nums.size()-1;
        int first=-1,second=-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]==target){
                first = mid;
                right = mid - 1;
            }
            else if(nums[mid]>target){
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        left=0,right=nums.size()-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]==target){
                second=mid;
                left=mid+1;
            }
            else if(nums[mid]>target){
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        vector<int> ans;
        if(first>second){
            ans.push_back(second);
            ans.push_back(first);
            return ans;

        }
        ans.push_back(first);
        ans.push_back(second);
        return ans;
    }
};