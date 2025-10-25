class Solution {
public:
    typedef long long ll;
    int mod=1e9+7;
    int N,M,K;

    ll solve(int count, ll sum, vector<int> &nums){
        if(count==M){
            if(__builtin_popcountll(sum)==K){
                return 1;
            }
            return 0;
        }
        ll total_sum=0;
        for(int i=0;i<N;i++){
            ll new_sum=sum + (1LL<<i);
            ll product=(nums[i]*solve(count+1,new_sum,nums))%mod;
            total_sum=(total_sum+product)%mod;
        }
        return total_sum;
    }
    int magicalSum(int m, int k, vector<int>& nums) {
        M=m;
        K=k;
        N=nums.size();
        return (int)(solve(0,0,nums)%mod);
    }
};
