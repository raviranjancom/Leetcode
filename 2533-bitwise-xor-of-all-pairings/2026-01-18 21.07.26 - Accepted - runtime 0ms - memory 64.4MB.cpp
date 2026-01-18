class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size()%2,m=nums2.size()%2;
        int ans=0;
        if(m){
            for(int i=0;i<nums1.size();i++){
                ans=(ans^nums1[i]);
            }
        }
        if(n){
            for(int i=0;i<nums2.size();i++){
                ans=(ans^nums2[i]);
            }
        }
        return ans;
    }
};
