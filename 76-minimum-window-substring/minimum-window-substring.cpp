class Solution {
public:
    string minWindow(string s, string t) {
        if(s.length()<t.length()){
            return "";
        }
        int minLen=INT_MAX;
        int left=0;
        unordered_map<char,int> need;
        unordered_map<char,int> count;
        for(int i=0;i<t.length();i++){
            need[t[i]]++;
        }
        int required=need.size();
        int formed=0,start=0;
        for(int right=0;right<s.length();right++){
            if(need.count(s[right])){
                count[s[right]]++;
                if(count[s[right]]==need[s[right]]){
                    formed++;
                }
            }

            while(formed==required){
                while(left<right && !need.count(s[left])){
                    left++;
                }
                int len=right-left+1;
                if(len<minLen){
                    minLen=len;
                    start=left;
                }
                count[s[left]]--;
                if(count[s[left]]<need[s[left]]){
                    formed--;
                }
                left++;
            }
        }
        return minLen==INT_MAX?"":s.substr(start,minLen);
    }
};