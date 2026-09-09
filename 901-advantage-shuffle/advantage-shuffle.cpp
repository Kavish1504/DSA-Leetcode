class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        vector<int> ans;
        for(int i=0;i<nums2.size();i++){
            auto it=upper_bound(nums1.begin(),nums1.end(),nums2[i]);
            if(it!=nums1.end()){
                ans.push_back(*it);
                nums1.erase(it);
            }
            else{
                ans.push_back(nums1[0]);
                nums1.erase(nums1.begin());
            }
        }
        return ans;
    }
};