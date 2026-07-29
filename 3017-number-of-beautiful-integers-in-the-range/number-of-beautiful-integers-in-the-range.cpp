class Solution {
public:
    int dp[11][2][11][11][21][2];
    int solve(string str,int curr_index,bool tight,int even_count,int odd_count,int rem,int k,bool allzero){
        if(curr_index==str.size()){
            return !allzero && even_count==odd_count && rem==0;
        }
        if(dp[curr_index][tight?1:0][even_count][odd_count][rem][allzero]!=-1){
            return dp[curr_index][tight?1:0][even_count][odd_count][rem][allzero];
        }
        int end=tight?str[curr_index]-'0':9;
        int count=0;
        for(int digit=0;digit<=end;digit++){
            int newrem=(rem*10+digit)%k;
            bool newTight=tight && digit==end;
            bool AllZero=allzero && digit==0;
            if(digit%2==0){
                count+=solve(str,curr_index+1,newTight,AllZero?even_count:even_count+1,odd_count,newrem,k,AllZero);
            }
            else{
                count+=solve(str,curr_index+1,newTight,even_count,odd_count+1,newrem,k,AllZero);
            }
        }
        return dp[curr_index][tight?1:0][even_count][odd_count][rem][allzero]=count;
    }
    int countBeautiful(int x,int k){
        if(x<=0) return 0;
        string s = to_string(x);
        memset(dp,-1,sizeof(dp));
        return solve(s,0,true,0,0,0,k,true);
    }
    int numberOfBeautifulIntegers(int low, int high, int k) {
        return countBeautiful(high,k)
             - countBeautiful(low-1,k);
    }
};