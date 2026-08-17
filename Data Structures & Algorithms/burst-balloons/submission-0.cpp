class Solution {
public:
    // int n;
    vector<vector<int>> dp;
    int solve(int i,  int j , vector<int>& nums){
        if (i > j) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        long long maxi = INT_MIN;

        for(int idx=i ;idx<=j;idx++){
            long long cost = nums[idx]*nums[j+1]*nums[i-1] 
                + solve(i , idx-1 , nums) + solve(idx+1 , j , nums);
            maxi = max(maxi , cost);
        }

        return dp[i][j] = maxi;
    } 
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin() , 1);
        dp.assign(n+1 , vector<int>(n+1 , -1));
        return solve(1 , n , nums);   
    }
};
