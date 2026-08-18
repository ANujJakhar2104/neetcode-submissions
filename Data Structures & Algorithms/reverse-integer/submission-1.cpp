class Solution {
public:
    int reverse(int x) {
        long long ans = 0;
        bool yes = false;
        if (x < 0) yes = false;
        if (yes) x = -1*x;

        while (x != 0){
            int curr = x%10;
            x = x/10;
            ans = ans*10 + curr;
        }
        
        if (yes) ans = -1*ans;
        if (ans > INT_MAX || ans < INT_MIN) return 0;
        return ans;
    }
};
