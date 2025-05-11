class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        int nums1_zeros=0, nums2_zeros=0;
        int n=nums1.size(), m=nums2.size();
        int s1=0,s2=0;
        for(int i=0;i<n;i++){
            if(nums1[i]==0) nums1_zeros++;
            s1+=nums1[i];
        }
        
        for(int i=0;i<m;i++){
            if(nums2[i]==0) nums2_zeros++;
            s2+=nums2[i];
        }
        if(s1+nums1_zeros > s2+nums2_zeros){
            if(nums2_zeros <= s1-s2+nums1_zeros && nums2_zeros>0){
                return s1+nums1_zeros;
            }
        }
        else if(s2+nums2_zeros > s1+nums1_zeros){
            if(nums1_zeros <= s2-s1+nums2_zeros && nums1_zeros>0){
                return s2+nums2_zeros;
            }
        }
        else if(s1+nums1_zeros == s2+nums2_zeros){
            return s1+nums1_zeros;
        }
        return -1;
    }
};
