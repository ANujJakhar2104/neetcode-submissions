class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        int n = mat.size();
        int l = 0;
        int r = n-1;

        while (l < r){
            for(int i= 0 ; i < r-l ; i++){
                int top = l;
                int bot = r;

                int curr = 0;
                int next = 0;

                // top right change to top left
                curr = mat[top+i][bot];
                mat[top+i][bot] = mat[top][top+i];

                // bottom right change to top right;
                next = mat[bot][bot-i];
                mat[bot][bot-i] = curr;
                curr = next;

                // bottom left to bottom right
                next = mat[bot-i][top];
                mat[bot-i][top] = curr;
                curr = next;

                // top left to bottom left;
                mat[top][top+i] = curr;
            }
            l++;
            r--;
        }
    }
};
