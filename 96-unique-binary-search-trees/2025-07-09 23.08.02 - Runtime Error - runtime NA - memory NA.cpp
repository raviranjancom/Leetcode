class Solution {
public:
    long long fact(int n){
        long long ans=1;
        for(int i=1;i<=n;i++){
            ans=ans*i;
        }
        return ans;
    }
    int numTrees(int n) {
        long long x=fact(2*n);
        long long y=fact(n);
        long long z=fact(n+1);
        long long k=x/y;
        return k/z;
    }
};