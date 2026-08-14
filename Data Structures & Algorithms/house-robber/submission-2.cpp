class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<long long> dp(n);
        for (int i = 0; i < n; i++) {
            long long take = nums[i] + (i >= 2 ? dp[i-2] : 0);
            long long skip = (i >= 1 ? dp[i-1] : 0);
            dp[i] = max(take, skip);
        }
        return (int)dp[n-1];
    }
};