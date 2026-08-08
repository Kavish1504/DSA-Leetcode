class Solution {
public:
    void solve(string s,set<string>& st,vector<string>& ans,int index,string temp){
        if(index>=s.size()){
            temp.pop_back();
            ans.push_back(temp);
            return;
        }
        for(int i=index;i<s.size();i++){
            string str=s.substr(index,i-index+1);
            if(st.count(str)){
                int old=temp.size();
                temp+=str;
                temp+=' ';
                solve(s,st,ans,i+1,temp);
                temp.resize(old);
                // temp.pop_back();
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> ans;
        set<string> st(wordDict.begin(),wordDict.end());
        solve(s,st,ans,0,"");
        return ans;
    }
};