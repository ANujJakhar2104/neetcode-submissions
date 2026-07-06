class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> temp;
        int n = nums.size();
        for(int i=0;i<n;i++){
            temp.push_back({nums[i] , i});
        }

        sort(temp.begin() , temp.end() , [](pair<int,int>& a , pair<int,int>& b){
            if (a.first != b.first) return a.first<b.first;
            return a.second < b.second;
        });

        int i=0,j=n-1;

        while(i<=j){
            long long sum = temp[i].first + temp[j].first;

            if (sum == target){
                int a = temp[i].second;
                int b = temp[j].second;
                if (a < b) return {a,b};
                return {b,a};
            }else if (sum > target) j-= 1;
            else i+=1;
        }
        return  {};
    }
};
