class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        long long ed = *max_element(piles.begin() , piles.end());

        int st = 1;
        int ans = INT_MAX;

        while (st <= ed){
            int mid = st + (ed-st)/2;
            int temp = 0;
            for(int p : piles){
                temp += p/mid;
                if (p%mid != 0) temp += 1;
            }

            if (temp <= h){
                ans = min(ans , mid);
                ed = mid-1;
            }else st = mid +1;
        }

        return ans;
    }
};
