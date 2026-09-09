class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        int left=0,maxfreq=0;
        int ans=0;
        for(int right=0;right<nums.size();right++){
            freq[nums[right]]++;
            maxfreq=max(maxfreq,freq[nums[right]]);
            while((right-left+1)-maxfreq>k){
                freq[nums[left]]--;
                left++;
            }
            ans=max(ans,maxfreq);
        }
        return ans;
    }
};