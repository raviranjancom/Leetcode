class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        sort(power.begin(),power.end());
        int n=power.size();
        long long ans=0;
        for(int i=0;i<n;i++){
            long long ds=0;
            int j=0;

            while(j<n){
                int lb=lower_bound(power.begin(),power.end(),power[j])-begin(power);
                int ub=upper_bound(power.begin(),power.end(),power[j])-begin(power);
                // int LB=lower_bound(power.begin(),power.end(),power[j]-2)-begin(power);
                int UB=upper_bound(power.begin(),power.end(),power[j]+2)-begin(power);

                ds+=1LL*(ub-lb)*power[j];
                j=UB;
            }
            ans=max(ans,ds);
        }
        return ans;
    }
};
