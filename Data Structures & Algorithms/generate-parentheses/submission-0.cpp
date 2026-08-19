class Solution {
public:
    vector<string> ans;
    void solve(int open , int closed , int n , string& temp){
        if (closed == n && open == n){
            ans.push_back(temp);
            return;
        }

            if (open < n){
                temp += "(";
                solve(open+1 , closed , n , temp);
                temp.pop_back();
            }
            if (closed < open){
                temp += ")";
                solve(open , closed+1 , n , temp);
                temp.pop_back();
            }
    }
    vector<string> generateParenthesis(int n) {
        string temp = "";
        solve(0 , 0 , n , temp);
        return ans;
    }
};
