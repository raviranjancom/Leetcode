class Solution {
public:
    int trap(vector<int>& height) {
        int l=0,r=height.size()-1;
        int Lmax=0,Rmax=0,ans=0;
        while(l<r){
            if(height[l] <= height[r]){
                if(height[l]>=Lmax){
                    Lmax=height[l];
                    l++;
                }
                else{
                    ans+=Lmax-height[l];
                    l++;
                }
            }
            else{
                if(Rmax<=height[r]){
                    Rmax=height[r];
                    r--;
                }
                else{
                    ans+=Rmax-height[r];
                    r--;
                }
            }
        }
        return ans;
    }
};