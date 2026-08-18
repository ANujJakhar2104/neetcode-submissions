class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        queue<pair<int,int>> q;
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (board[r][c] == 'O' && (r == 0 || c == 0 || r == m-1 || c== n-1)) {
                    q.push({r,c});
                }
            }
        }

        while(!q.empty()){
            auto [i,j] = q.front();
            q.pop();
            board[i][j] = 'T';

            int x[4] = {1,0,-1,0};
            int y[4] = {0,1,0,-1};

            for (int k=0;k<4;k++){
                int nr = i + x[k];
                int nc = j + y[k];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && board[nr][nc] == 'O') {
                    q.push({nr, nc});
                }
            }
        }

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (board[r][c] == 'T') board[r][c] = 'O';
                else if (board[r][c] == 'O') board[r][c] = 'X';
            }
        }
    }
};