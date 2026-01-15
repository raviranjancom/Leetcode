class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans=0;
        int n=prices.size();
        int l=0,r=0;
        while(l<n && r<n){
            if(r==l){
                ans++;
            }
            else if(prices[r-1]==prices[r]+1){
                ans+=r-l+1;
            }
            else{
                l=r;
                ans++;
            }
            r++;
        }
        return ans;
    }
};
