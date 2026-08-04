class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        map<int,bool> mp;
        vector<int> ans;
        int mini=INT_MAX,maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            mini=min(mini,nums[i]);
            maxi=max(maxi,nums[i]);
            mp[nums[i]]=true;
        }
        int num=mini+1;
        while(num<maxi){
            if(mp.find(num)==mp.end()){
                ans.push_back(num);
            }
            num++;
        }
        return ans;
    }
};