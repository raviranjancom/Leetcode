class Solution {
public:
    typedef long long ll;
    const int mod=1e9+7;
    int N,K;
    vector<ll> fact,invfact;
    map<tuple<ll,int,int,int>,ll> dp;

    ll findpow(ll a, ll b){
        if(b==0) return 1;

        ll half=findpow(a,b/2);
        ll result=(half*half)%mod;

        if(b%2==1){
            result=(result*a)%mod;
        }
        return result;
    }

    ll nCr(int n, int r){
        return (((fact[n]*invfact[r])%mod)*invfact[n-r])%mod;
    }

    ll solve(ll binarySum, int m, int k, int i, vector<int> &nums){
        // memoization
        auto key=make_tuple(binarySum,m,k,i);
        if(dp.count(key)){
            return dp[key];
        }
        // base case
        if(m==0 && __builtin_popcountll(binarySum)==k){
            return 1;
        }
        if(m==0 || i>=N){
            return 0;
        }
        ll totalSum=0;
        // skip
        totalSum=(totalSum+solve((binarySum>>1),m,k-(binarySum),i+1,nums))%mod;
        // take indexi for frequency number of times which is at max = m
        for(int fre=1;fre<=m;fre++){
            ll newBinarySum=binarySum+fre;

            ll product=solve((newBinarySum>>1),m-fre, k-(newBinarySum&1),i+1,nums)%mod;
            product=((findpow(nums[i],fre)%mod)*product)%mod;
            product=(product*nCr(m, fre))%mod;

            totalSum=(totalSum+product)%mod;
        }
        return dp[key]=totalSum;
    }
    int magicalSum(int m, int k, vector<int>& nums) {
        K=k;
        N=nums.size();
        fact.assign(m+1,1);
        invfact.assign(m+1,1);

        for(int i=2;i<=m;i++){
            fact[i]=(fact[i-1]*i)%mod;
        }

        for(int i=0;i<=m;i++){
            invfact[i]=findpow(fact[i],mod-2);
        }
        return (int)(solve(0,m,k,0,nums)%mod);
    }
};
