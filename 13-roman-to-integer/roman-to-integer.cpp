class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> mp = {
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}
        };
        int num=0;
        int index=0;
        while(index<s.size()){
            if(mp[s[index+1]]>mp[s[index]]){
                num-=mp[s[index]];
                num+=mp[s[index+1]];
                index+=2;
            }
            else{
                num+=mp[s[index]];
                index++;
            }

        }
        return num;
    }
};