class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int ans = 0;

        for(char ch='A'; ch <='Z';ch++){
            int cnt =0;
            int j =0;
            for(int i=0;i<n;i++){
                if (s[i] == ch){
                    ans = max(ans , i-j+1);
                    continue;
                }
                cnt++;
                while(cnt>k){
                    if (s[j] != ch) cnt -= 1;
                    j += 1;
                }
                ans = max(ans , i-j+1);
            }
        }

        return ans;
    }
};
