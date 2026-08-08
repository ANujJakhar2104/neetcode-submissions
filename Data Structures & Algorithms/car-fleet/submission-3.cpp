class Solution {
public:
    int carFleet(int target, vector<int>& pos, vector<int>& speed) {
        vector<pair<int,int>> temp;
        for(int i=0;i<pos.size();i++){
            temp.push_back({pos[i] , speed[i]});
        }
        sort(temp.rbegin() , temp.rend());
        int ans = 1;
        double prev = double(target - temp[0].first)/temp[0].second;

        for(int i=1;i<pos.size();i++){

            int dist = target - temp[i].first;
            double req = double(dist)/temp[i].second;

            if (req > prev){
                ans++;
                prev = req;
            }
        }

        return ans;
    }
};
