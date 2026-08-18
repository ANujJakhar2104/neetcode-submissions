class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if (grid[i][j] == 0) q.push({i,j});
            }
        }
        if (q.empty()) return;

        while (!q.empty()){
            auto [i,j] = q.front();
            q.pop();

            int x[4] = {1,0,-1,0};
            int y[4] = {0,1,0,-1};

            for(int k=0;k<4;k++){
                int new_x = i + x[k];
                int new_y = j + y[k];
                if (new_x < 0 || new_y < 0 || new_x >= m || new_y >= n || 
                grid[new_x][new_y] != INT_MAX) continue;
                
                grid[new_x][new_y] = min(grid[new_x][new_y] , 1 + grid[i][j]);
                q.push({new_x , new_y});
            }
        }

    }
};
