class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        queue<pair<int,int>> q;
        vector<int> vis(n , 0);
        q.push({0,-1});
        vis[0] = 1;

        while(!q.empty()){
            auto [node , parent] = q.front();
            q.pop();

            for(int next : adj[node]){
                if (next == parent) continue;
                if (vis[next]) return false;
                vis[next] = 1;
                q.push({next , node}); 
            }
        }

        for (int i = 0; i < n; i++) if (!vis[i]) return false;
        return true;
    }
};
