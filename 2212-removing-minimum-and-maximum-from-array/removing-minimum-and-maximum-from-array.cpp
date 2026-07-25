class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        int min_index=-1,max_index=-1,mini=INT_MAX,maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<mini){
                mini=nums[i];
                min_index=i;
            }
            if(nums[i]>maxi){
                maxi=nums[i];
                max_index=i;
            }
        }
        bool same=false;
        int min_distance_from_start=min_index+1;
        int min_distance_from_end=n-min_index;
        int max_distance_from_start=max_index+1;
        int max_distance_from_end=n-max_index;
        return min({
            max(min_distance_from_start, max_distance_from_start), 
            max(min_distance_from_end, max_distance_from_end),     
            min(min_distance_from_start + max_distance_from_end,
                max_distance_from_start + min_distance_from_end)   
        });
    }
};