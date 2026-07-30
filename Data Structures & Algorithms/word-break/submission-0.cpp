class Solution {
public:
    unordered_map<int,bool> mp;
    bool solve(int idx, unordered_set<string>& word, string& s){
        if (idx == s.size()) return true;
        if (mp.count(idx)) return mp[idx];

        for(int i = idx + 1; i <= s.size(); i++){
            string temp = s.substr(idx, i - idx);
            if (word.count(temp) && solve(i, word, s)) {
                return mp[idx] = true;
            }
        }
        return mp[idx] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) 
    {   
        unordered_set<string> word(wordDict.begin(), wordDict.end());
        mp.clear();
        return solve(0, word, s);
    }
};