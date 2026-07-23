class Solution {
public:
    void solve(vector<string>& mapping,vector<string>& ans,string result,int index,string digits){
        if(index>=digits.size()){
            ans.push_back(result);
            return;
        }
        for(int i=0;i<mapping[digits[index]-'2'].size();i++){
            result+=mapping[digits[index]-'2'][i];
            solve(mapping,ans,result,index+1,digits);
            result.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> mapping={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> ans;
        string result="";
        solve(mapping,ans,result,0,digits);
        return ans;
    }
};