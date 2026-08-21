class Solution {
public:
    vector<vector<string>> ans;
    void solve(int row, int n, vector<int>& col, vector<int>& diag1, vector<int>& diag2,
               vector<string>& temp) {
        if (row == n) {
            ans.push_back(temp);
            return;
        }
        for (int c = 0; c < n; c++) {
            int d1 = row - c + n;
            int d2 = row + c;
            if (!col[c] && !diag1[d1] && !diag2[d2]) {
                string s(n, '.');
                s[c] = 'Q';
                temp.push_back(s);
                col[c] = diag1[d1] = diag2[d2] = 1;
                solve(row + 1, n, col, diag1, diag2, temp);
                col[c] = diag1[d1] = diag2[d2] = 0;
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<int> col(n, 0), diag1(2 * n, 0), diag2(2 * n, 0);
        vector<string> temp;
        solve(0, n, col, diag1, diag2, temp);
        return ans;
    }
};