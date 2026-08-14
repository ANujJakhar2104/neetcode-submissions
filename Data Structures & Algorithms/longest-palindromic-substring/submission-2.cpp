class Solution {
public:
    string longestPalindrome(string s) {
        // string t = s;
        // reverse(s.begin() , s.end());
        // int n = s.size();

        // vector<int> dp(n , 0);
        // int maxi = 0;
        // for(int i=0;i<n;i++){
        //     vector<int> new_dp(n,0);
        //     for(int j=0;j<n;j++){
        //         if (t[j] == s[i]){
        //             new_dp[j] = 1;
        //             if (j > 0){
        //                 new_dp[j] += dp[j-1];
        //             }
        //             maxi = max(maxi , dp[j]);
        //         }
        //     }
        // }

        // return maxi;

        string t = s;
        reverse(s.begin() , s.end());
        int n = s.size();

        vector<vector<int>> dp(n , vector<int>(n , 0));
        int maxi = 0;
        int x=0,y=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if (t[j] == s[i]){
                    dp[i][j] = 1;
                    if (j > 0 && i > 0){
                        dp[i][j] += dp[i-1][j-1];
                    }
                }
                int len = dp[i][j];
                int beforeStart = i - len + 1;
                if (beforeStart + j == n - 1 && len > maxi){
                    maxi = len;
                    x = i;
                }
            }
        }

        string ans = "";
        while(maxi--){
            ans += s[x];
            x--;
        }
        return ans;

    }
};
