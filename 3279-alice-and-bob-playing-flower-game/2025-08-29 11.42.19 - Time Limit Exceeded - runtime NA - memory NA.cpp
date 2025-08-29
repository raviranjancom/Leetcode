class Solution {
public:
    long long flowerGame(int n, int m) {
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                ans+=((i+j)%2==1)?1:0;
            }
        }
        return ans;
    }
};
