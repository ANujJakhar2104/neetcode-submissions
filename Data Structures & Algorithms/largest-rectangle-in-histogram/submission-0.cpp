class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        int ans = 0;

        for(int i=0;i<=n;i++){
            while (!st.empty() &&(i==n || heights[st.top()] > heights[i])){
                int high = heights[st.top()];
                st.pop();
                int nse = i;
                int pse = st.empty() ? -1 : st.top();
                ans = max(ans , (nse - pse -1)*high);
            }
            st.push(i);
        }

        return ans;
    }
};
