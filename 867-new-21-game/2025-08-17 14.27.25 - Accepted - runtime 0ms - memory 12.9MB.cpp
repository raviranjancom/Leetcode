class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        vector<double> p(n+1,0);
        p[0]=1;
        double sum=(k==0)?0:1;
        for(int i=1;i<=n;i++){
            p[i]=sum/maxPts;
            if(i<k){
                sum+=p[i];
            }
            if(i-maxPts>=0 && i-maxPts<k){
                sum-=p[i-maxPts];
            }
        }
        double ans=0;
        for(int i=k;i<=n;i++){
            ans+=p[i];
        }
        return ans;
    }
};
