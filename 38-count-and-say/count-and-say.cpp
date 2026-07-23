class Solution {
public:
    string solve(string s){
        string res="";
        int i=0;
        while(i<s.size()){
            int cnt=1;
            while(i+1<s.size() && s[i]==s[i+1]){
                cnt++;
                i++;
            }
            res+=to_string(cnt);
            res+=s[i];
            i++;
        }
        return res;
    }
    string countAndSay(int n) {
        if(n==0){
            return "";
        }
        string str="1";
        for(int i=1;i<n;i++){
            str=solve(str);
        }
        return str;
    }
};