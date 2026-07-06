class Solution {
public:
    int m,n;
    void solve(int i , int j, vector<vector<char>>& grid , vector<vector<int>>& vis){
        queue<pair<int,int>> q;
        q.push({i,j});
        vis[i][j] = 1;
        while(!q.empty()){
            auto [curr_r,curr_c] = q.front();
            q.pop();

            int r[4] = {0,1,0,-1};
            int c[4] = {1,0,-1,0};

            for(int k=0;k<4 ; k++){
                int new_r = curr_r+r[k];
                int new_c = curr_c+c[k];

                if (new_r>=0 && new_r<m && new_c>=0 && new_c<n){
                    if (grid[new_r][new_c] == '1' && vis[new_r][new_c] != 1){
                        q.push({new_r,new_c});
                        vis[new_r][new_c] = 1;
                    }
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        m = grid.size();
        n = grid[0].size();
        vector<vector<int>> vis(m , vector<int>(n , -1));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if (vis[i][j] == -1 && grid[i][j] == '1') {
                    cnt += 1;
                    solve(i ,j, grid , vis);
                }
            }
        }
        return cnt;
    }
};