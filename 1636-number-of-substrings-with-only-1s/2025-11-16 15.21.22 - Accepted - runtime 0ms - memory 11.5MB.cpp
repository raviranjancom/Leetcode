class Solution {
public:
    int MOD=1e9+7;
    long long fun(long long n){
        return n*(n+1)/2;
    }
    int numSub(string s) {
        int n=s.length();
        long long ans=0;
        for(int i=0;i<n;i++){
            long long cnt=0;
            while(s[i]=='1'){
                cnt++;
                i++;
            }
            ans=(ans+fun(cnt)%MOD)%MOD;
        }
        return ans;
    }
};
