class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        unordered_map<int, vector<int>> adj(n+1);
        vector<int> ind(n+1 , 0);
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            ind[it[0]] += 1;
            ind[it[1]] += 1;
        }
        
        queue<int> q;
        for(int i=1;i<n+1;i++){
            if (ind[i] == 1) q.push(i);
        }

        while (!q.empty()) {
            int node = q.front(); q.pop();
            ind[node]--;
            for (int nei : adj[node]) {
                ind[nei]--;
                if (ind[nei] == 1) q.push(nei);
            }
        } 

        for (int i = edges.size() - 1; i >= 0; i--) {
            int u = edges[i][0], v = edges[i][1];
            if (ind[u] == 2 && ind[v])
                return {u, v};
        }
        return {};
    }
};

        


