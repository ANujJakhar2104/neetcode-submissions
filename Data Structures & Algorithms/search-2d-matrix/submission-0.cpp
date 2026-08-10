class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int st =0 , ed = n*m-1 , mid = 0;

        while (st <= ed){
            int mid = st + (ed-st)/2;
            int i = mid/m;
            int j = mid%m;
            if (matrix[i][j] == target) {
                return true;
            }else if (matrix[i][j] > target){
                ed = mid - 1;
            }else {
                st = mid+1;
            }
        }

        return false;
    }
};
