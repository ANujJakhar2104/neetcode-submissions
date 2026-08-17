class Solution {
public:
    int n ,m;
    vector<vector<int>> dp;
    bool solve(int i, int j, string& s1, string& s2, string& s3){
        if (i == n && j == m) return true;
        if (dp[i][j] != -1) return dp[i][j];

        bool ok = false;
        if (i < n && s1[i] == s3[i+j]) ok = solve(i+1, j, s1, s2, s3);
        if (!ok && j < m && s2[j] == s3[i+j]) ok = solve(i, j+1, s1, s2, s3);

        return dp[i][j] = ok;
    }
    bool isInterleave(string s1, string s2, string s3) {
        n = s1.size();
        m = s2.size();
        if (n+m != s3.size()) return false;
        dp.assign(n+1 , vector<int>(m+1 , -1));
        return solve(0 , 0 ,s1 , s2 , s3);
    }
};