class Solution {
public:
    void solve(int n,int k,string temp,vector<string>& ans,bool prev,int index,int cost){
        if(cost > k)
            return;

        if(index >= n) {
            ans.push_back(temp);
            return;
        }
        if(prev){
            solve(n,k,temp+'0',ans,false,index+1,cost);
        }
        else{
            solve(n,k,temp+'0',ans,false,index+1,cost);
            solve(n,k,temp+'1',ans,true,index+1,cost+index);
        }
    }
    vector<string> generateValidStrings(int n, int k) {
        string temp="";
        vector<string> ans;
        solve(n,k,temp,ans,false,0,0);
        return ans;
    }
};