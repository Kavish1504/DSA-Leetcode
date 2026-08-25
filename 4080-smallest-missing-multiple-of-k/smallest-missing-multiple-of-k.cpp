class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]=1;
        }
        int cand;
        bool flag=false;
        for(int i=1;i<=n;i++){
            if(!mp.count(k*i)){
                cand=k*i;
                flag=true;
                break;
            }
        }
        if(!flag) cand=k*(n+1);
        return cand;
    }
};