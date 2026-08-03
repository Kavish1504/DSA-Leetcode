class Solution {
public:
    int solve(vector<int>& stoneValue,int index,bool alice,vector<vector<int>>& dp){
        if(index>=stoneValue.size()){
            return 0;
        }
        if(dp[index][alice]!=-1){
            return dp[index][alice];
        }
        int sum=0;
        if(alice){
            int ans=INT_MIN;
            for(int i=0;i<3 && index+i<stoneValue.size();i++){
                sum+=stoneValue[index+i];
                ans=max(ans,sum+solve(stoneValue,index+i+1,false,dp));
            }
            return dp[index][alice]=ans;
        }
        else{
            int ans=INT_MAX;
            for(int i=0;i<3 && index+i<stoneValue.size();i++){
                sum+=stoneValue[index+i];
                ans=min(ans,-sum+solve(stoneValue,index+i+1,true,dp));
            }
            return dp[index][alice]=ans;
        }
        
    }
    string stoneGameIII(vector<int>& stoneValue) {
        vector<vector<int>> dp(stoneValue.size(),vector<int>(2,-1));
        int diff=solve(stoneValue,0,true,dp);
        if(diff>0) return "Alice";
        if(diff<0) return "Bob";
        return "Tie";
    }
};