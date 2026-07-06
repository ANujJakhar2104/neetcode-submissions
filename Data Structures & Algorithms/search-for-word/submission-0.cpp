class Solution {
public:
    int m, n;
    bool solve(vector<vector<char>>& board, string& word,
               queue<tuple<int,int,int,set<pair<int,int>>>>& q, bool& ans){
        int r[4] = {0,1,0,-1};
        int c[4] = {1,0,-1,0};

        auto [curr_i, curr_j, idx, visited] = q.front();
        q.pop();

        if (idx == (int)word.size() - 1) {
            ans = true;
            return true;
        }

        for(int k = 0; k < 4; k++){
            int new_i = curr_i + r[k];
            int new_j = curr_j + c[k];

            if (new_i < 0 || new_i >= m || new_j < 0 || new_j >= n) continue;
            if (visited.count({new_i, new_j})) continue;
            if (board[new_i][new_j] != word[idx+1]) continue;

            auto new_visited = visited;
            new_visited.insert({new_i, new_j});
            q.push({new_i, new_j, idx+1, new_visited});
        }

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        queue<tuple<int,int,int,set<pair<int,int>>>> q;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if (board[i][j] == word[0]){
                    set<pair<int,int>> vis;
                    vis.insert({i, j});
                    q.push({i, j, 0, vis});
                }
            }
        }

        bool ans = false;
        while(!q.empty()){
            if (word.size() == 1) return true;
            bool found = solve(board, word, q, ans);
            if (found) return true;
        }

        return ans;
    }
};