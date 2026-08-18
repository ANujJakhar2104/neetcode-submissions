class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>> q;
        int one= 0;
        int zero = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 2) q.push({i,j});
                if(grid[i][j] == 1) one += 1;
                if(grid[i][j] == 0) zero += 1;
            }
        }
        if (zero == m*n) return 0;
        if (one+zero == m*n) return -1;
        int ans =0;
        while (!q.empty()){
            int sz = q.size();
            ans += 1;
            while(sz--){
                auto [i,j] = q.front();
                q.pop();

                int x[4] = {1,0,-1,0};
                int y[4] = {0,1,0,-1};

                for(int k=0;k<4;k++){
                    int r = i + x[k];
                    int c = j + y[k];

                    if (r<0 || c<0 || r>=m || c>=n || grid[r][c] != 1) continue;

                    grid[r][c] = 2;
                    q.push({r,c});
                }
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1) return -1;
            }
        }
        return ans-1;
    }
};
