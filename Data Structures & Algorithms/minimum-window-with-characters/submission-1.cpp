class Solution {
public:
    int n;
    bool solve(int i , unordered_map<char,int> mp , string s , int& st ,int& end){
        bool found = false;
        for(int j=i;j<n;j++){
            if (mp.find(s[j]) != mp.end()){
                if (!found){
                    st = j;
                    found = true;
                }

                mp[s[j]] -= 1;
                if (mp[s[j]] == 0) mp.erase(s[j]);

                if (mp.empty()){
                    end = j;
                    break;
                }
            }
            if (mp.empty()) break;
        }
        return mp.empty();
    }
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";
        unordered_map<char,int> mp;
        for(char ch : t){
            mp[ch] += 1;
        }
        int st = 0 , end = 0;
        n = s.size();
        pair<int,int> temp;
        int ans = INT_MAX;
        for(int i=0;i<s.size();i++){
            if (solve(i , mp , s , st, end)){
                if (end-st+1 < ans){
                    ans = end-st+1;
                    temp = {st,end};
                }
            }
        }
        if (ans == INT_MAX) return "";
        return s.substr(temp.first, temp.second - temp.first + 1);;
    }
};
