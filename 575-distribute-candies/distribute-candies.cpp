class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_map<int,int> mp;
        for(int i=0;i<candyType.size();i++){
            mp[candyType[i]]++;
        }
        int n=candyType.size();
        int types=n/2;
        if(mp.size()>=types){
            return types;
        }
        return mp.size();
    }
};