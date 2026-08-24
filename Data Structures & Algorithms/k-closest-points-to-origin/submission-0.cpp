class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<float,int> , vector<pair<float,int>> , 
            greater<pair<float,int>>> pq;
        int i = 0;
        for(auto it : points){
            int x = it[0]; int y = it[1];
            float dist = x*x + y*y;
            pq.push({dist , i++});
        }

        vector<vector<int>> ans;
        while (k-- && !pq.empty()){
            ans.push_back(points[pq.top().second]);
            pq.pop();
        }

        return ans;
    }
};
