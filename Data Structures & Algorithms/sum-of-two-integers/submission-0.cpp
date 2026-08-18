class Solution {
public:
    int getSum(int a, int b) {
        int ans = 0;
        int carry = 0;
        for(int i=0;i<32;i++){
            int x = (a>>i & 1);
            int y = (b>>i & 1);
            int sumBit = x ^ y ^ carry;
            ans |= (sumBit << i); 
            carry = (x&y)|(y&carry)|(carry&x);
        }
        return ans;
    }
};
