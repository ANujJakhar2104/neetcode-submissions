class Solution {
public:
    vector<vector<int>> dp;
    bool check(int i , int j , string s ){
        if (i >= j) return true;

        if (dp[i][j] != -1) return dp[i][j];

        if (s[i] == s[j]) return dp[i][j] = check(i+1 , j-1 , s);

        return dp[i][j] = false;
    }

    string longestPalindrome(string s) {
        int n = s.size();
        dp.resize(n , vector<int>(n+1 , -1));

        int maxi = 1;
        int st_idx = 0;
        string temp;
        for (int i=0; i<n;i++){
            for(int j=i;j<n;j++){
                if (check(i ,j ,s)){
                    if (j-i+1 > maxi){
                        st_idx = i;
                        maxi = j-i+1;
                    }
                }
            }
        }
        return s.substr(st_idx , maxi);
    }
};
