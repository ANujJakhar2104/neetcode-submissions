class Solution {
public:
    int n;
    vector<string> ans;
    void solve(int idx, string& temp, unordered_map<int,string>& mp, string digits){
        if (idx == n){
            ans.push_back(temp);
            return;
        }
        string& letters = mp[digits[idx] - '0'];
        for(int i = 0; i < letters.size(); i++){
            temp.push_back(letters[i]);
            solve(idx+1, temp, mp, digits);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits == "") return {};
        n = digits.size();
        unordered_map<int , string> mp;
        mp[2] = "abc";
        mp[3] = "def";
        mp[4] = "ghi";
        mp[5] = "jkl";
        mp[6] = "mno";
        mp[7] = "pqrs";
        mp[8] = "tuv";
        mp[9] = "wxyz";

        string temp = "";
        solve(0 , temp , mp , digits);
        return ans;
    }
};
