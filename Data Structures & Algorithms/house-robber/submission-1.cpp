class Solution {
public:
    vector<vector<int>> dp;
    int n;
    int solve(int idx, bool prevTaken, vector<int>& nums){
        if (idx == n) return 0;
        if (dp[idx][prevTaken] != -1) return dp[idx][prevTaken];

        int nskip = 0;
        if (!prevTaken){
            nskip = nums[idx] + solve(idx+1, true, nums);
        }
        int skip = solve(idx+1, false, nums);

        return dp[idx][prevTaken] = max(skip, nskip);
    }
    int rob(vector<int>& nums) {
        n = nums.size();
        dp.assign(n, vector<int>(2, -1));
        return solve(0, false, nums);
    }
};