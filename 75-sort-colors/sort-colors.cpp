class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero_index=0;
        int two_index=nums.size()-1;
        for(int i=0;i<=two_index;i++){
            if(nums[i]==0){
                while(zero_index<i && nums[zero_index]==0){
                    zero_index++;
                }
                if(zero_index<i){
                    swap(nums[i],nums[zero_index]);
                    i--;
                    zero_index++;
                }
            }
            else if(nums[i]==2){
                while(two_index>i && nums[two_index]==2){
                    two_index--;
                }
                if(two_index>i){
                    swap(nums[i],nums[two_index]);
                    i--;
                    two_index--;
                }
            }
        }
    }
};