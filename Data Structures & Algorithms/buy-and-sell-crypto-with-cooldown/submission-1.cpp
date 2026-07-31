class Solution {
public:
    int n;
    vector<vector<vector<int>>> dp;
    int solve(int idx  ,int prev , int buy ,vector<int>& prices){
        if (idx >= n) {
            if (buy) return INT_MIN/2;
            else return 0;
        }
        if (dp[idx][prev+1][buy] != -1) return dp[idx][prev+1][buy];
        int take = 0;
        if (buy == 0){
            if (prev == -1 || idx-prev > 1) {
                take = max(take ,
                    -1*prices[idx]  + solve(idx+1 , -1 ,1,prices));
            }
            take = max(take , solve(idx+1 , prev , 0 , prices));

        }else {
            take = max(prices[idx] + solve(idx+1 ,idx , 0 , prices) , 
                solve(idx+1 ,prev , 1, prices));
        }

        return dp[idx][prev+1][buy] = take;
    }
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        dp.assign(n ,vector<vector<int>>(n+1 ,vector<int>(2 , -1)));

        return solve(0 ,-1, 0 ,prices);
    }
};
