class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int n = height.size();

        int i=0,j=n-1;
        while (i < n && height[i] == 0) i++;
        while (j >= 0 && height[j] == 0) j--;
        int lmax = 0 , rmax = 0 ;
        while(i < j){
            if (height[i] <= height[j]) {
                if (lmax > height[i]) ans += lmax - height[i];
                lmax = max(lmax, height[i]);
                i++;
            } else {
                if (rmax > height[j]) ans += rmax - height[j];
                rmax = max(rmax, height[j]);
                j--;
            }
        }
        return ans;
    }
};
