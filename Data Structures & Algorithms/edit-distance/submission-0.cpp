class Solution {
public:
    int n,m;
    vector<vector<int>> dp;
    const int maxi = INT_MAX;
    int solve(int i , int j , string& word1, string& word2){
        if (i >= n) return m-j;
        if (j >= m) return n-i;
        if (dp[i][j] != -1) return dp[i][j];

        int match = maxi;
        int rep = maxi;
        int del = maxi;
        int ins = maxi;

        if (word1[i] == word2[j]) {
            match = min(match,solve(i+1, j+1 ,word1 , word2));
        }else {
            del = min(del , 1+solve(i+1 , j , word1 , word2)); // DElETE
            rep = min(rep , 1+solve(i+1 , j+1 , word1 , word2)); // REPLACE
            ins = min(ins , 1+solve(i , j+1 , word1 , word2)); // insert
        }
        return dp[i][j] = min({match , rep , del , rep , ins});
    }
    int minDistance(string word1, string word2) {
        n = word1.size();
        m = word2.size();
        dp.resize(n , vector<int>(m , -1));

        return solve(0,0,word1,word2);
    }
};
