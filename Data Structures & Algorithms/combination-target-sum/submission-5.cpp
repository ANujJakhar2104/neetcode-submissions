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

        temp.push_back(nums[idx]);
        solve(idx, sum + nums[idx], nums, temp, target);
        temp.pop_back();

        solve(idx + 1, sum, nums, temp, target);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> temp;
        solve(0, 0, nums, temp, target);
        return ans;
    }
};