class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev=0;
        int ans=0;
        for(auto str:bank){
            int cnt=count(str.begin(),str.end(),'1');
            if(cnt==0) continue;
            ans+=prev*cnt;
            prev=cnt;
        }
        return ans;
    }
};