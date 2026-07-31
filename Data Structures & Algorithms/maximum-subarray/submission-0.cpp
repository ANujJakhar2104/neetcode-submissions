class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = nums[0];
        int curr = 0;

        for(int num : nums){
            curr = max(curr , 0);
            curr += num;
            maxi = max(maxi , curr);
        }
        return maxi ;
    }
};
// class Solution {
// public:
//     int n;
//     vector<vector<int>> dp;
//     int solve(int idx , int prev , vector<int>& nums){
//         if (idx == n) return 0;
//         if (dp[idx][prev+1] != -1) return dp[idx][prev+1];

//         int take = nums[idx] + solve(idx+1 , idx , nums);
//         int ntake = solve(idx+1 , prev , nums);
//         return dp[idx][prev+1] = max(take , ntake);
//     }
//     int maxSubArray(vector<int>& nums) {
//         n = nums.size();
//         dp.assign(n , vector<int>(n+1 , -1));

//         return solve(0 , -1 , nums);
//     }
// };
