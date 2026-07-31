class Solution {
public:
    int n;
    vector<vector<int>> dp;

    bool solve(int idx, vector<int>& nums, int target, int sum){
        if (sum == target) return true;
        if (sum > target || idx >= n) return false;
        if (dp[idx][sum] != -1) return dp[idx][sum];

        bool ntake = solve(idx+1, nums, target, sum);
        bool take  = solve(idx+1, nums, target, sum + nums[idx]);

        return dp[idx][sum] = (ntake || take);
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        n = nums.size();
        for (int num : nums) sum += num;
        if (sum & 1) return false;

        dp.assign(n, vector<int>(sum/2 + 1, -1));
        return solve(0, nums, sum/2, 0);
    }
};