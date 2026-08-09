class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        unordered_map<int,unordered_set<char>> row;
        unordered_map<int,unordered_set<char>> col;
        map<pair<int,int>,unordered_set<char>> box;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if (board[i][j] != '.'){
                    pair<int,int> superKey = {i/3 , j/3};

                    if (row[i].count(board[i][j]) 
                    || col[j].count(board[i][j]) || 
                    box[superKey].count(board[i][j])) return false;

                    row[i].insert(board[i][j]);
                    col[j].insert(board[i][j]);
                    box[superKey].insert(board[i][j]);
                }
            }
        }

        return true;
    }
};
