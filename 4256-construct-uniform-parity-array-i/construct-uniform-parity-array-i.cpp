class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int odd=0,even=0;
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]%2==0){
                even++;
            }
            else{
                odd++;
            }
        }
        if(odd>=0 || even==0){
            return true;
        }
        return false;
    }
};