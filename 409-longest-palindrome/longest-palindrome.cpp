class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        int length=0;
        for(auto num:mp){
            if(num.second%2==0){
                length+=num.second;
            }
        }
        int maxi=INT_MIN;
        for(auto num:mp){
            if(num.second%2!=0){
                maxi=max(maxi,num.second);
                length+=num.second-1;
            }
        }

        if(maxi==INT_MIN)
            return length;

        return length+1;
    }
};