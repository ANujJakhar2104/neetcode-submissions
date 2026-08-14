class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0] , nums[1]);
        vector<long long> dp(n);
        int ans = 0;
        for(int i=0;i<n-1;i++){
            long long take = nums[i] + (i>=2 ? dp[i-2] : 0);
            long long ntake = (i>=1 ? dp[i-1] : 0);
            dp[i] = max(take , ntake);
        }

        ans = max(ans , (int)dp[n-2]);
        dp.assign(n,0);
        for(int i=1;i<n;i++){
            long long take = nums[i] + (i>=2 && (i-2 != 0)? dp[i-2] : 0);
            long long ntake = (i>=1 && (i-1 != 0)? dp[i-1] : 0);
            dp[i] = max(take , ntake);
        }

        return max(ans , (int)dp[n-1]);
    }
};
