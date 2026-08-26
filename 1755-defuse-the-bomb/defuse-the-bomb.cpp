class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> ans(code.size(),0);
        int n=code.size();
        if(k>0){
            int i=1,j=k;
            int sum=0;
            for(int l=i;l<=j;l++){
                sum+=code[l];
            }
            ans[0]=sum;
            for(int l=1;l<code.size();l++){
                sum-=code[i];
                i=(i+1)%n;
                j=(j+1)%n;
                sum+=code[j];
                ans[l]=sum;
            }
        }
        else if(k<0){
            int i=n-1,j=n+k;
            int sum=0;
            for(int l=i;l>=j;l--){
                sum+=code[l];
            }
            ans[0]=sum;
            for(int l=1;l<code.size();l++){
                sum-=code[j];
                i=(i+1)%n;
                j=(j+1)%n;
                sum+=code[i];
                ans[l]=sum;
            }
        }
        return ans;
    }
};