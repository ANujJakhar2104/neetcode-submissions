class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        if (n == 1) return true;
        vector<int> inorder(n ,0);
        vector<vector<int>> adj(n);
        queue<int> q;

        for(auto p : pre){
            inorder[p[0]] += 1;
            adj[p[1]].push_back(p[0]);
        }

        for(int i=0;i<n;i++){
            if (inorder[i] == 0) q.push(i);
        }
        int cnt = 0;
        while(!q.empty()){
            int idx = q.front();
            q.pop();
            cnt += 1;

            for(int i : adj[idx]){
                inorder[i] -= 1;
                if (inorder[i] == 0) q.push(i);
            }
        }

        return cnt == n;
    }
};