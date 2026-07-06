class Solution {
public:
    vector<vector<int>> ans;
    int n;
    void solve(int idx , int sum , vector<int> temp ,vector<int>& nums, int target){
        if (idx == n) return;
        if (sum == target){
            ans.push_back(temp);
            return;
        }
        if (sum > target) return;

        for(int i=idx ; i<n ; i++){
            temp.push_back(nums[i]);
            solve(i , sum + nums[i] ,temp,nums,target);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        n = nums.size();
        vector<int> temp;
        sort(nums.begin() , nums.end());
        solve(0 , 0,temp ,nums , target);
        return ans;
    }
};
