class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        unordered_map<int,int> top;
        for(int i=0;i<tops.size();i++){
            top[tops[i]]++;
        }
        unordered_map<int,int> bottom;
        for(int i=0;i<bottoms.size();i++){
            bottom[bottoms[i]]++;
        }
        int max_element_in_top;
        int max_count=INT_MIN;
        for(auto num:top){
            if(num.second>max_count){
                max_count=num.second;
                max_element_in_top=num.first;
            }
        }
        int max_element_in_bottom;
        max_count=INT_MIN;
        for(auto num:bottom){
            if(num.second>max_count){
                max_count=num.second;
                max_element_in_bottom=num.first;
            }
        }
         int top_swaps = 0;
        bool possible = true;

        for(int i = 0; i < tops.size(); i++) {

            if(tops[i] == max_element_in_top)
                continue;

            if(bottoms[i] == max_element_in_top)
                top_swaps++;
            else {
                possible = false;
                break;
            }
        }

        int ans = INT_MAX;

        if(possible)
            ans = min(ans, top_swaps);


        // Try candidate from bottom
        int bottom_swaps = 0;
        possible = true;

        for(int i = 0; i < bottoms.size(); i++) {

            if(bottoms[i] == max_element_in_bottom)
                continue;

            if(tops[i] == max_element_in_bottom)
                bottom_swaps++;
            else {
                possible = false;
                break;
            }
        }

        if(possible)
            ans = min(ans, bottom_swaps);

        return ans == INT_MAX ? -1 : ans;
    }
};