class Solution {
public:
    vector<vector<int>> dp;
    int solve(int idx, int n, bool prevTaken, vector<int>& nums) {
        if (idx == n) return 0;
        if (dp[idx][prevTaken] != -1) return dp[idx][prevTaken];

        int nskip = 0;
        if (!prevTaken) {
            nskip = nums[idx] + solve(idx + 1, n, true, nums);
        }
        int skip = solve(idx + 1, n, false, nums);

        return dp[idx][prevTaken] = max(skip, nskip);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        dp.assign(n, vector<int>(2, -1));
        int excludeLast = solve(0, n - 1, false, nums);

        dp.assign(n, vector<int>(2, -1)); // reset before reuse
        int excludeFirst = solve(1, n, false, nums);

        return max(excludeLast, excludeFirst);
    }
};