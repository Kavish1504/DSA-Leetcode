class Solution {
public:
    int solve(vector<int>& piles,int start,int end,bool flag,vector<vector<int>>& dp){
        if(start>end){
            return 0;
        }
        if(dp[start][end]!=-1){
            return dp[start][end];
        }
        if(flag){
            int r1=solve(piles,start+1,end,false,dp)+piles[start];
            int r2=solve(piles,start,end-1,false,dp)+piles[end];
            return dp[start][end]=max(r1,r2);
        }
        int r1=solve(piles,start+1,end,true,dp)-piles[start];
        int r2=solve(piles,start,end-1,true,dp)-piles[end];
        return dp[start][end]=max(r1,r2);
    }
    bool stoneGame(vector<int>& piles) {
        // int final_alice=0,final_bob=0;
        vector<vector<int>> dp(piles.size(),vector<int>(piles.size(),-1));
        return solve(piles,0,piles.size()-1,true,dp);
        // return final_alice>final_bob;
    }
};