class Solution {
public:
    void helper(int row, vector<string> &board, vector<vector<string>> &ans, vector<bool> &colLeft, vector<bool> &rightDiagonal, vector<bool> &leftDiagonal, int n) {
        if(row == n) {
            ans.push_back(board);
            return;
        }
        for(int col = 0; col < n; col++) {
            if(colLeft[col] == 0 and rightDiagonal[row + col] == 0 and leftDiagonal[n - 1 + row - col] == 0) {
                board[row][col] = 'Q';
                colLeft[col] = 1;
                rightDiagonal[row + col] = 1;
                leftDiagonal[n - 1 + row - col] = 1;
                helper(row + 1, board, ans, colLeft, rightDiagonal, leftDiagonal, n);
                board[row][col] = '.';
                colLeft[col] = 0;
                rightDiagonal[row + col] = 0;
                leftDiagonal[n - 1 + row - col] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<bool> colLeft(n), rightDiagonal(2*n-1), leftDiagonal(2*n-1);
        vector<string> board(n, string(n, '.'));
        helper(0, board, ans, colLeft, rightDiagonal, leftDiagonal, n);
        return ans;
    }
};