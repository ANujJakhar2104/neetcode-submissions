class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 1));

        priority_queue<pair<int,pair<int,int>>> pq; // max-heap by value
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                pq.push({mat[i][j], {i, j}});

        int x[4] = {1, 0, -1, 0};
        int y[4] = {0, -1, 0, 1};
        int ans = 0;

        while (!pq.empty()) {
            auto [val, ij] = pq.top();
            auto [i, j] = ij;
            pq.pop();

            for (int k = 0; k < 4; k++) {
                int ni = i + x[k], nj = j + y[k];
                if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
                if (mat[ni][nj] < mat[i][j])
                    dp[ni][nj] = max(dp[ni][nj], dp[i][j] + 1);
            }
            ans = max(ans, dp[i][j]);
        }
        return ans;
    }
};