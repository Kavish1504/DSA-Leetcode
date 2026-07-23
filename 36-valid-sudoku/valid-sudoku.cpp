class Solution {
public:
    bool cal_row(vector<vector<char>>& board, int rows, int cols) {
        for (int i = 0; i < rows; i++) {
            unordered_set<char> s;
            for (int j = 0; j < cols; j++) {
                if (board[i][j] != '.') {
                    if (s.count(board[i][j])) {
                        return false; // Duplicate found in row
                    }
                    s.insert(board[i][j]);
                }
            }
        }
        return true;
    }

    bool cal_cols(vector<vector<char>>& board, int rows, int cols) {
        for (int j = 0; j < cols; j++) {
            unordered_set<char> s;
            for (int i = 0; i < rows; i++) {
                if (board[i][j] != '.') {
                    if (s.count(board[i][j])) {
                        return false; // Duplicate found in column
                    }
                    s.insert(board[i][j]);
                }
            }
        }
        return true;
    }

    bool cal_matrix(vector<vector<char>>& board, int rows, int cols) {
        for (int block = 0; block < 9; block++) {
            unordered_set<char> s;
            int rowStart = (block / 3) * 3;
            int colStart = (block % 3) * 3;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    char num = board[rowStart + i][colStart + j];
                    if (num != '.') {
                        if (s.count(num)) {
                            return false; // Duplicate found in 3×3 subgrid
                        }
                        s.insert(num);
                    }
                }
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        return cal_row(board, rows, cols) && cal_cols(board, rows, cols) && cal_matrix(board, rows, cols);
    }
};
