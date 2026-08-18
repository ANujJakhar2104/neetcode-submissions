class Solution {
public:
    vector<int> countBits(int n) {
        int offset = 2;
        int next = 4;
        
        if (n == 0) return {0};
        if (n == 1) return {0 , 1};
        vector<int> ans(n+1);
        ans[0] = 0;
        ans[1] = 1;
        for(int i=2;i<=n;i++){
            if (i < next){
                ans[i] = 1 + ans[i-offset];
            }else {
                offset = next;
                next *= 2;
                ans[i] = 1 + ans[i-offset];
            }
        }
        return ans;
    }
};
