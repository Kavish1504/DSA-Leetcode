class Solution {
public:
    void solve(bitset<32>& bits,vector<int>& ans,int n){
        if(n==0){
            ans.push_back(bits.to_ulong());
        }
        else{
            solve(bits,ans,n-1);
            bits.flip(n-1);
            solve(bits,ans,n-1);
        }
    }
    vector<int> grayCode(int n) {
        bitset<32> bits;
        vector<int> ans;
        solve(bits,ans,n);
        return ans;
    }
};