class Solution {
public:
    int n;
    vector<vector<string>> ans;
    vector<vector<bool>> dp;
    void solve(int i ,string& s , vector<string>& temp){
        if (i >= n){
            ans.push_back(temp);
            return;
        }
        
        for(int idx = i ; idx<n; idx++){
            if (dp[i][idx]) {
                temp.push_back(s.substr(i , idx-i+1));
                solve(idx+1 , s , temp);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> temp;
        n = s.size();
        dp.assign(n , vector<bool>(n));

        for (int l = 1; l <= n; l++) {
            for (int i = 0; i <= n - l; i++) {
                dp[i][i + l - 1] = (s[i] == s[i + l - 1] &&
                                    (i + 1 > (i + l - 2) ||
                                    dp[i + 1][i + l - 2]));
            }
        }

        solve(0 ,s, temp);
        return ans;
    }
};
