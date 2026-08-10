class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        int i=0,j=0;
        int a = 0, b =0;
        for(int cnt = 0 ; cnt <= (n+m)/2 ; cnt++){
            b = a;
            if (i < n && j < m){
                if (nums1[i] > nums2[j]){
                    a = nums2[j];
                    j++;
                }else {
                    a = nums1[i];
                    i++;
                }
            }else if (i < n){
                a = nums1[i++];
            }else {
                a = nums2[j++];
            }
        }

        if ((n+m)%2 == 1){
            return (double) a;
        }
        return (a+b)/2.0;
    }
};
