class Solution {
public:
    int countTriples(int n){
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                double c=sqrt(pow(i,2)+pow(j,2));
                int k=(int)c;
                if(c==k && k>=1 && k<=n){
                    ans++;
                }
            }
        }
        return ans;
    }
};
