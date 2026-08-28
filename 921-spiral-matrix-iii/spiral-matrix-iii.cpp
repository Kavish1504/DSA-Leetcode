class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols,
                                         int rStart, int cStart) {

        vector<vector<int>> ans;

        int curr_row = rStart;
        int curr_col = cStart;

        int up = rStart;
        int bottom = rStart;
        int right = cStart;
        int left = cStart;

        ans.push_back({rStart, cStart});

        while(ans.size() < rows * cols) {

            // RIGHT
            right++;

            for(int i = max(curr_col + 1, 0);
                i <= min(right, cols - 1); i++) {

                if(curr_row >= 0 && curr_row < rows)
                    ans.push_back({curr_row, i});
            }

            curr_col = right;


            // DOWN
            bottom++;

            for(int i = max(curr_row + 1, 0);
                i <= min(bottom, rows - 1); i++) {

                if(curr_col >= 0 && curr_col < cols)
                    ans.push_back({i, curr_col});
            }

            curr_row = bottom;


            // LEFT
            left--;

            for(int i = min(curr_col - 1, cols - 1);
                i >= max(left, 0); i--) {

                if(curr_row >= 0 && curr_row < rows)
                    ans.push_back({curr_row, i});
            }

            curr_col = left;


            // UP
            up--;

            for(int i = min(curr_row - 1, rows - 1);
                i >= max(up, 0); i--) {

                if(curr_col >= 0 && curr_col < cols)
                    ans.push_back({i, curr_col});
            }

            curr_row = up;
        }

        return ans;
    }
};