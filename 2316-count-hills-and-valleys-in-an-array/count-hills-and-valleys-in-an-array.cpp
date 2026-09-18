class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int i=1;
        int prev_notequal=nums[0];
        int count=0;
        while(i<nums.size()){
            if(nums[i]==prev_notequal){
                i++;
                continue;
            }
            int j=i+1;
            while(j<nums.size()){
                if(nums[j]!=nums[i]){
                    break;
                }
                j++;
            }
            if(j>=nums.size()) return count;
            if((nums[i] > nums[j] && nums[i] > prev_notequal) ||
               (nums[i] < prev_notequal && nums[i] < nums[j])) {
                count++;
            }
            prev_notequal=nums[i];
            i++;
        }
        return count;
    }
};