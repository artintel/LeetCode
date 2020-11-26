class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> num = nums1;
        int i = 0, s1_i = 0, s2_i = 0;
        while(s1_i < m && s2_i < n){
            if(num[s1_i] <= nums2[s2_i]){ 
                nums1[i++] = num[s1_i];
                s1_i++;
            }
            else nums1[i++] = nums2[s2_i++];
        }
        if(s1_i < m) for(;s1_i < m; s1_i++) nums1[i++] = num[s1_i];
        else for(; s2_i < n; s2_i++) nums1[i++] = nums2[s2_i];
        return;
    }
};