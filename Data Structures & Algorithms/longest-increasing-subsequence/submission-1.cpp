class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int solve(int idx , int prev , vector<int>& nums){
        if (idx >= n) return 0;
        if (dp[idx][prev+1] != -1) return dp[idx][prev+1];

        int take = 0;
        if (prev == -1 || nums[idx] > nums[prev]) 
            take = 1 + solve(idx+1 , idx ,nums);

        int ntake = solve(idx+1 , prev , nums);
        return dp[idx][prev+1]= max(take , ntake);
    }
    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        dp.assign(n , vector<int>(n+1 , -1));
        return solve(0 , -1 , nums);
    }
};
