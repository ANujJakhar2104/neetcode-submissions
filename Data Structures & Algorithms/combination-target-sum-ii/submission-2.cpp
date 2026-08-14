class Solution {
public:
    int n;
    vector<vector<int>> ans;
    void solve(int idx, int sum, vector<int>& nums, vector<int>& temp, int target) {
        if (sum == target) {
            ans.push_back(temp);
            return;
        }
        if (idx >= n || sum > target) return;

        for(int i=idx;i<n;i++){
            if (i > idx && nums[i] == nums[i-1]) continue;
            if (nums[i] + sum > target) break;

            temp.push_back(nums[i]);
            solve(i+1 , sum+nums[i] , nums , temp , target);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> temp;
        // ans.clear();
        solve(0, 0, nums, temp, target);
        return ans;
    }
};