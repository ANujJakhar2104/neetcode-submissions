class Solution {
public:
    void solve(int i , vector<vector<int>>& adj , vector<int>& vis){
        queue<int> q;
        q.push(i);
        vis[i] = 1;
        while(!q.empty()){
            int idx = q.front();
            q.pop();

            for(int next : adj[idx]){
                if (vis[next] == 0) q.push(next); 
                vis[next] = 1;
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> vis(n , 0);
        int cnt = 0;
        vector<vector<int>> adj(n);
        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        for(int i=0;i<n;i++){
            if (!vis[i]) {
                cnt += 1;
                solve(i , adj , vis);
            }
        }
        return cnt;
    }
};
