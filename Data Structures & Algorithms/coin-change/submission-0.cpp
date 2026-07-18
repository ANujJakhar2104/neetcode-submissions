class Solution {
public:
    vector<vector<int>> dp;
    int n;
    const int INF = INT_MAX/2;
    int solve(int idx ,vector<int>& coins , int amount){
        if (amount < 0) return INF;
        if (idx == n) return INF;
        if (amount == 0) return 0;
        if(dp[idx][amount] != -1) return dp[idx][amount];
        
        int take = INF;
        if (coins[idx] <= amount){
            take = 1 + solve(idx , coins , amount-coins[idx]);
        }
        int ntake = solve(idx+1 , coins , amount);
        return dp[idx][amount] = min(take , ntake);
    }
    int coinChange(vector<int>& coins, int amount) {
        n = coins.size();
        dp.assign(n , vector<int>(amount + 1, -1));

        int ans = solve(0 , coins , amount);
        return  ans >= INF ? -1 : ans;
    }
};
