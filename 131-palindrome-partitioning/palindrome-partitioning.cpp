class Solution {
public:
    bool isPalindrome(string str){
        int start=0;
        int end=str.length()-1;
        while(start<end){
            if(str[start]!=str[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    void backtrack(string& s,int start,vector<string>& path,vector<vector<string>>& dp){
        if(start==s.length()){
            dp.push_back(path);
            return;
        }
        for(int end=start+1;end<=s.length();end++){
            string str=s.substr(start,end-start);
            if(isPalindrome(str)){
                path.push_back(str);
                backtrack(s,end,path,dp);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n=s.length();
        vector<vector<string>> dp;
        vector<string> path;
        backtrack(s,0,path,dp);
        return dp;
    }
};