class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index=1;
        int count=1;
        for(int j=1;j<nums.size();j++){
            if(nums[j]==nums[j-1]){
                count++;
            }
            else{;
                count=1;
            }
            if(count<=2){
                nums[index]=nums[j];
                index++;
            }
            
        }
        return index;
    }
};