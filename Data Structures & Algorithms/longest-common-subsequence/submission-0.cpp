class Solution {
public:
    int m,n;
    vector<vector<int>> dp;
    int solve(int i , int j , string text1, string text2){
        if (i >= m || j >= n) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        int take = 0;
        if (text1[i] == text2[j]){
            take = 1 + solve(i+1 , j+1 , text1 , text2);
        }
        else {
            take = max(solve(i+1 , j , text1 , text2) ,
                        solve(i , j+1 , text1 , text2));
        }

        return dp[i][j] = take;
    }
    int longestCommonSubsequence(string text1, string text2) {
        m = text1.size();
        n = text2.size();
        dp.assign(m , vector<int>(n+1 , -1));
        return solve(0,0,text1 , text2);
    }
};
