class TimeMap {
public:
    unordered_map<string , vector<pair<int , string>>> mp; 
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp , value});
    }
    
    string get(string key, int timestamp) {
        if (mp.find(key) == mp.end()) return "";
        auto &temp = mp[key];
        int i=0 , j=temp.size()-1;
        string ans = "";

        while (i <= j){
            int mid = i + (j-i)/2;

            if (temp[mid].first <= timestamp){
                ans = temp[mid].second;
                i = mid+1;
            }else {
                j = mid-1;
            }
        }

        return ans;
    }
};
