class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        if (nums[0] < nums[n-1]) return nums[0];

        int i=0,j=n-1;
        while (i <= j){
            int mid = i + (j-i)/2;
            if (mid > 0 && nums[mid] < nums[mid-1]){
                return nums[mid];
            }
            else if (nums[mid] < nums[j]){
                j = mid-1;
            }
            else i = mid+1;
        }

        return nums[0];
    }
};