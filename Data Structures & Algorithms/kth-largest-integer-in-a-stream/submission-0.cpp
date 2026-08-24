class KthLargest {
public:
    multiset<int> m;
    int n;
    
    KthLargest(int k, vector<int>& nums) {
        for(int num : nums){
            if (m.size() < k){
                m.insert(num);
            }else{
                m.insert(num);
                m.erase(m.begin());
            }
        }
        n = k;
    }
    
    int add(int val) {
        m.insert(val);

        while (m.size() > n){
            m.erase(m.begin());
        }

        return *m.begin();
    }
};
