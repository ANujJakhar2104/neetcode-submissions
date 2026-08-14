class Solution {
public:
    int climbStairs(int n) {
        int prev = 1;
        int curr = 2;
        if (n <= 2) return n;

        int sz = 2;

        while (sz!=n){
            int temp = prev+curr;
            prev = curr;
            curr = temp;
            sz++;
        }

        return curr;

        // if (n <= 2) return n;
        // vector<int> a(n+1 , 1);
        // for(int i=3;i<=n;i++){
        //     a[i] += a[i-1] + a[i-2];
        // }

        // return a[n];
    }
};
