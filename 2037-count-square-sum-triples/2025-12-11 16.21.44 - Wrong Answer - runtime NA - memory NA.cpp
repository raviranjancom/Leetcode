class Solution {
public:
    int countTriples(int n){
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                int a=pow(i,2), b=pow(j,2);
                float c=pow(a+b,0.5);
                if((int)c == c) ans++;
            }
        }
        return ans;
    }
};
