class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        // int tp = n%10;
        // n = n/10;
        for(int i = 0; i<32; i++){
            if ((n>>i) & 1){
                ans += pow(2 , 31-i);
            }
        }
        return ans;
    }
};
