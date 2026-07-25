class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        vector<pair<int,int>> vec;
        for(int i=0;i<items.size();i++){
            vec.push_back({items[i][0],items[i][1]});
        }
        sort(vec.begin(),vec.end());
        for(int i = 1; i < vec.size(); i++)
            vec[i].second = max(vec[i].second, vec[i-1].second);
        vector<int> result;
        for(int x:queries){
            int left=0;
            int right=vec.size()-1;
            int ans=0;
            while(left<=right){
                int mid=left+(right-left)/2;
                if(vec[mid].first<=x){
                    ans=vec[mid].second;
                    left=mid+1;
                }
                else{
                    right=mid-1;
                }
            }
            result.push_back(ans);
        }
        return result;
    }
};