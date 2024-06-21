class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        int br[n];
        for(int i=0;i<k;i++){
            br[i]=nums[n-k+i];
        }
        for(int j=k;j<n;j++){
            br[j]=nums[j-k];
        }
        for(int i=0;i<n;i++){
            nums[i]=br[i];
        }
    }
};