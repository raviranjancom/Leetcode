class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        vector<double> p(n+1,0.0);
        p[0]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=maxPts;j++){
                if(i-j>=0 && i-j<k){
                    p[i]+=p[i-j]/maxPts;
                }
            }
        }
        double ans=0.0;
        for(int i=k;i<=n;i++){
            ans+=p[i];
        }
        return ans;
    }
};