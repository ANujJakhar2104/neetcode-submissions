class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        vector<int> ans(n , 0);
        stack<pair<int,int>> st;

        for(int i=0;i<n;i++){
            while (!st.empty() && st.top().first < temp[i]){
                auto [t , idx] = st.top();
                st.pop();
                ans[idx] = i-idx;
            }
            st.push({temp[i] , i});
        }

        return ans;
    }
};
