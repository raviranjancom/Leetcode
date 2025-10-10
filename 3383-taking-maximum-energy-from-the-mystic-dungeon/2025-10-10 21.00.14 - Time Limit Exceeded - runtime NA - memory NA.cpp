class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n=energy.size();
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j+=k){
                sum+=energy[j];
            }
            ans=max(ans,sum);
        }
        return ans;
    }
};
