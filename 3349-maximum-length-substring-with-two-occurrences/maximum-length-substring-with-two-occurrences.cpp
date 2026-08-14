class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char,int> mp;
        int len=INT_MIN;
        int left=0;
        for(int right=0;right<s.size();right++){
            mp[s[right]]++;
            while(mp[s[right]]>2){
                mp[s[left]]--;
                left++;
            }
            len=max(len,right-left+1);
        }
        return len;
    }
};