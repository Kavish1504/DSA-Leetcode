class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int ans=0;
        int n=colors.size();
        if (k == 1)
            return n;
        int alternate=0;
        for(int i=1;i<n+k-1;i++){
            if(colors[(i-1)%n]!=colors[(i)%n]){
                alternate++;
            }
            else{
                alternate=0;
            }
            if(alternate>=k-1 && i>=k-1){
                ans++;
            }
        }
        return ans;
    }
};