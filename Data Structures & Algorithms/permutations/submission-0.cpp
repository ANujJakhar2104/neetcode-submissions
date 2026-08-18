class Solution {
public:
    int n;
    vector<vector<int>> ans;
    void solve(vector<int>& nums , vector<int>& temp , vector<int>& vis){
        if (temp.size() == n){
            ans.push_back(temp);
            return;
        }

        for(int i=0;i<n;i++){
            if (vis[i] == -1){
                temp.push_back(nums[i]);
                vis[i] = 1;
                solve(nums , temp , vis);
                temp.pop_back();
                vis[i] = -1;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        vector<int> temp;
        vector<int> vis(n , -1);
        solve(nums , temp , vis);
        return ans;
    }
};
