class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;
        unordered_map<int,vector<char>> mp;
        int rows=0;
        bool down=true;
        for(int i=0;i<s.size();i++){
            mp[rows].push_back(s[i]);
            if(down){
                rows++;
                if(rows==numRows-1){
                    down=false;
                }
            }
            else{
                rows--;
                if(rows==0){
                    down=true;
                }
            } 
        }
        string ans="";
        for(int r=0;r<numRows;r++){
            for(char ch:mp[r]){
                ans+=ch;
            }
        }
        return ans;
    }
};