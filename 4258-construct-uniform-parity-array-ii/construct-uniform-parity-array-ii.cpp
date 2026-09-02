class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        sort(nums1.rbegin(),nums1.rend());
        int j=nums1.size()-1;
        while(j>=0 && nums1[j]%2==0){
            j--;
        }
        if(j<0) return true;
        int odd=nums1[j];
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]%2==0 && nums1[i]<odd){
                return false;
            }
        }
        return true;
    }
};