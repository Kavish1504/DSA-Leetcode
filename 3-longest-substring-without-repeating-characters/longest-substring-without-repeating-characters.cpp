class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int i=0,length=0;
        for(int j=0;j<s.length();j++){
            if(mp.find(s[j])!=mp.end() && mp[s[j]]>=i){
                i=mp[s[j]]+1;
            }
            mp[s[j]]=j;
            length=max(length,j-i+1);
        }
        return length;
    }
};