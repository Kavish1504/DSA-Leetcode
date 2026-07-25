class Solution {
public:
    long long dp[1000001][3][3];
    const int MOD=1e9+7;
    long long solve(int n,int absentCount,int clc){
        if(n==0) return 1;
        if(dp[n][absentCount][clc]!=-1) return dp[n][absentCount][clc];
        long long ans=0;
        ans = (ans + solve(n - 1, absentCount, 0)) % MOD;
        if(absentCount<1){
            ans=(ans+solve(n-1,absentCount+1,0))%MOD;
        }
        if(clc<2){
            ans=(ans+solve(n-1,absentCount,clc+1))%MOD;
        }
        return dp[n][absentCount][clc]=ans;
    }
    int checkRecord(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(n,0,0);
    }
};