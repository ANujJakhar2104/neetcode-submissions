class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<vector<int>> adj(n);
        vector<int> in(n , 0);
        for(auto it : pre){
            adj[it[1]].push_back(it[0]);
            in[it[0]] += 1;
        }

        queue<int> q;
        for(int i=0;i<n;i++){
            if (in[i] == 0) q.push(i);
        }
        vector<int> ans;
        while (!q.empty()){
            int node = q.front();
            ans.push_back(node);
            q.pop();
            n -= 1;
            for(int next : adj[node]){
                in[next] -= 1;
                if (in[next] == 0){
                    q.push(next);
                }
            }
        }

        if (n == 0) return ans;
        return {};
    }
};
