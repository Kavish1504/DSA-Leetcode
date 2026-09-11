class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        unordered_map<int,int> mp;
        for(int i=0;i<9;i++){
            mp[i]=0;
        }
        for(int i=0;i<digits.size();i++){
            mp[digits[i]]++;
        }
        int res=0;
        for(int i=1;i<10;i++){
            for(int j=0;j<10;j++){
                for(int k=0;k<9;k+=2){
                    res+=(mp[i]>0 && mp[j]>(i==j) && mp[k]>(i==k) + (j==k));
                }
            }
        }
        return res;
    }
};