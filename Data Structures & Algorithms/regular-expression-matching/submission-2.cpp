class Solution {
public:
    int n ,m;
    vector<vector<int>> dp;
    int solve(int i, int j , string& s , string& p){
        if (j == m) return i == n;
        if (dp[i][j] != -1) return dp[i][j];

        bool found = i < n && (s[i] == p[j] || p[j] == '.');
        if (j+1 < m && p[j+1] == '*'){
            dp[i][j] = solve(i , j+2 , s ,p) || (found && solve(i+1 , j , s, p));
        }else{
            dp[i][j] = found && solve(i+1 , j+1 , s, p);
        }
        return dp[i][j];
    }
    bool isMatch(string s, string p) {
        n = s.size();
        m = p.size();
        dp.assign(n+1 , vector<int> (m+1 , -1));
        return solve(0 , 0 , s , p);
        // return false;
    }
};
