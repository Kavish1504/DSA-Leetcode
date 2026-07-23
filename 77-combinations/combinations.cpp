class Solution {
public:
    vector<vector<int>> ans;
    void solve(int start,int n,int k,vector<int> curr){
        if(curr.size()==k){
            ans.push_back(curr);
            return;
        }
        int left=k-curr.size();
        int can_be_acheived=n-start+1;
        if(can_be_acheived<left) return;
        
        for(int i=start;i<=n;i++){
            curr.push_back(i);
            solve(i+1,n,k,curr);
            curr.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> curr;
        solve(1,n,k,curr);
        return ans;
    }
};