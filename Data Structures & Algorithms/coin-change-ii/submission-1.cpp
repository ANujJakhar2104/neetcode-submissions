class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int solve(int idx , int sum , int amount ,vector<int>& coins){
        if (sum == amount) return 1;
        if (idx >= n || sum > amount) return 0;
        if (dp[idx][sum] != -1) return dp[idx][sum];

        int ntake = solve(idx+1 , sum , amount , coins);
        sum += coins[idx];
        int take = solve(idx , sum , amount , coins);
        sum -= coins[idx];

        return dp[idx][sum] = take + ntake;
    }
    int change(int amount, vector<int>& coins) {
        n = coins.size();
        // int sum = 0;
        // for(int coin : coins) sum += coin;
        dp.assign(n , vector<int>(amount+1 , -1));
        return solve(0 , 0, amount ,coins);
    }
};
