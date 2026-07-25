class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int ans=0;
        unordered_map<string,int> mp;
        int n=target.size();
        for(int i=0;i<nums.size();i++){
            int size=nums[i].size();
            if(size>=n) continue;
            string s1=target.substr(0,n-size);
            string s2=target.substr(size,n-1);
            if(mp.find(s1)!=mp.end() && s1+nums[i]==target){
                ans+=mp[s1];
            }
            if(mp.find(s2)!=mp.end() && nums[i]+s2==target){
                ans+=mp[s2];
            }
            mp[nums[i]]++;
        }
        return ans;
    }
};