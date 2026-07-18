class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int solve(int idx, int prev, string& s){
        if (idx == n) return 1;
        if (s[idx] == '0') return 0;
        if (dp[idx][prev] != -1) return dp[idx][prev];

        int take = solve(idx+1, idx, s);
        int next_take = 0;
        if (idx+1 < n) {
            int a = stoi(s.substr(idx, 2));
            if (a <= 26) next_take = solve(idx+2, idx, s);
        }

        return dp[idx][prev] = take + next_take;
    }
    int numDecodings(string s) {
        n = s.size();
        dp.resize(n, vector<int>(n, -1));
        return solve(0, 0, s);
    }
};