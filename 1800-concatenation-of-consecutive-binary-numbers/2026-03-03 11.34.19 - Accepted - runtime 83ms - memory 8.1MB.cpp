class Solution {
public:
    int mod=1e9+7;
    int lastBit(int n){
        int ans=0;
        for(int i=0;i<32;i++){
            if((n&(1<<i))!=0){
                ans=i;
            }
        }
        return ans;
    }
    long long shiftByk(long long n,int k){
        return (n<<k);
    }
    int concatenatedBinary(int n){
        long long ans=0;
        for(int i=1;i<=n;i++){
            int k=lastBit(i);
            ans=1LL*(1LL*i+(1LL*(shiftByk(ans,k+1)%mod)))%mod;
        }
        return ans;
    }
};
