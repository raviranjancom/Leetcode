class Solution {
public:
    int MOD=1e9+7;
    long long findPow(long long a,long long b){
        if(b==0) return 1;
        long long half=findPow(a,b/2);
        long long ans=(half*half)%MOD;
        if(b%2==1) ans=(ans*a)%MOD;
        return ans;
    }
    int countGoodNumbers(long long n){
        long long i=(n+1)/2;
        long long j=n/2;
        long long even=findPow(5,i);
        long long odd=findPow(4,j);
        return (even*odd)%MOD;
    }
};
