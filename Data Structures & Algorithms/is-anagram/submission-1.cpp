class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;

        vector<int> ch(26 , 0);
        for(int i=0;i<s.size();i++){
            ch[s[i]-'a']++;
            ch[t[i]-'a']--;
        }

        for(int a : ch){
            if (a != 0) return false;
        }
        return true;
    }
};

// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         sort(s.begin() , s.end());
//         sort(t.begin() , t.end());

//         return s == t;
//     }
// };
