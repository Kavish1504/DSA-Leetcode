class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> freq(26,0);
        for(int i=0;i<chars.size();i++){
            freq[chars[i]-'a']++;
        }
        int ans=0;
        for(int i=0;i<words.size();i++){
            vector<int> freq1(26,0);
            for(int j=0;j<words[i].size();j++){
                freq1[words[i][j]-'a']++;
            }
            bool flag=true;
            for(int i=0;i<26;i++){
                if(freq1[i]>freq[i]){
                    flag=false;
                    break;
                }
            }
            if(flag){
                ans+=words[i].size();
            }
        }
        return ans;
    }
};