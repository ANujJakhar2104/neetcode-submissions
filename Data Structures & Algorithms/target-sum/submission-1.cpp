class Solution {
public:
    int n;
    int offset;
    vector<vector<int>> dp;
    int solve(int idx, int sum , int target , vector<int>& nums){
        if (idx == n) return sum == target ? 1 : 0;
        if (dp[idx][sum+offset] != -1) return dp[idx][offset+sum];
        int pos = solve(idx+1 , sum-nums[idx] , target , nums);
        int neg = solve(idx+1 , sum+nums[idx] , target , nums);

        return dp[idx][offset+sum] = pos+neg;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        n = nums.size();
        offset = 0;
        for (int num : nums) offset += num;
        dp.resize(n , vector<int>(2*offset+1 , -1));
        return solve(0 , 0 , target , nums);
    }
};
