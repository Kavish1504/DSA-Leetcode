class Solution {
public:
    void solve(vector<string>& ans,string temp,int open,int close,int n){
        if(temp.size()==2*n){
            ans.push_back(temp);
            return;
        }
        if(open>0){
            solve(ans,temp+'(',open-1,close,n);
        }
        if(close>open){
            solve(ans,temp+')',open,close-1,n);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp="";
        solve(ans,temp,n,n,n);
        return ans;
    }
};