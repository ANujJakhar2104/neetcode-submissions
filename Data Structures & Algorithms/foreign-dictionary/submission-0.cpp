class Solution {
public:
    string topo(vector<vector<char>>& adj, unordered_map<char, int>& inorder){
        queue<char> q;
        for(auto [ch, value] : inorder){
            if (value == 0) q.push(ch);
        }
        string ans;

        while(!q.empty()){
            char ch = q.front();
            q.pop();
            ans += ch;

            for(char next : adj[ch - 'a']){
                inorder[next] -= 1;
                if (inorder[next] == 0){
                    q.push(next);
                }
            }
        }

        return ans;
    }

    string foreignDictionary(vector<string>& words) {
        vector<vector<char>> adj(26);
        unordered_map<char, int> inorder;

        unordered_set<char> allChars;
        for (auto& w : words)
            for (char c : w)
                allChars.insert(c);

        for (char c : allChars)
            inorder[c] += 0;

        int n = words.size();
        for(int i=0;i<n-1;i++){
            string a = words[i], b = words[i+1];
            int j = 0, k = 0;
            while (j != a.size() && k != b.size()){
                if (a[j] == b[k]) {
                    j += 1;
                    k += 1;
                    if (k == b.size() && j != a.size()) return "";
                    continue;
                }
                adj[a[j] - 'a'].push_back(b[k]);
                inorder[b[k]] += 1;
                break;
            }
        }

        string ans = topo(adj, inorder);

        if (ans.size() != allChars.size()) return "";

        return ans;
    }
};