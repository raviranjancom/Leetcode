class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int x=0,ans=0;
        for(int i=0;i<m;i++){
            x=(x^nums2[i]);
        }
        int y=0;
        for(int i=0;i<n;i++){
            y=(y^nums1[i]);
        }
        if(n%2==1 && m%2==1){
            ans=(x^y);
        }
        else if(n%2==1 && m%2==0 ){
            ans=x;
        }
        else if(n%2==0 && m%2==1 ){
            ans=y;
        }
        else if(n%2==0 && m%2==0 ){
            ans=0;
        }
        return ans;
    }
};
