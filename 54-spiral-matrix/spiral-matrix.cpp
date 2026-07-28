class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> ans;

        int strow = 0;
        int endrow = m - 1;
        int stcol = 0;
        int endcol = n - 1;

        while(strow <= endrow && stcol <= endcol)
        {
            for(int i = stcol; i <= endcol; i++)
            {
                ans.push_back(matrix[strow][i]);
            }
            strow++;
            for(int i = strow; i <= endrow; i++)
            {
                ans.push_back(matrix[i][endcol]);
            }
            endcol--;
            if(strow<=endrow){
                for(int i = endcol; i >= stcol; i--)
            {

                ans.push_back(matrix[endrow][i]);
            }
            endrow--;
            }
            
            
            if(stcol <= endcol) {
                for(int i = endrow; i >= strow; i--)
                    ans.push_back(matrix[i][stcol]);
                stcol++;
            }
        }

        return ans;
    }
};