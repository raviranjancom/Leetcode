class Solution {
public:
    vector<vector<long long>> dp;
    int n;
    long long solve(int idx,int trend, vector<int> &nums){
        if(idx>=n){
            if(trend==3){
                return 0;
            }
            else{
                return LLONG_MIN/2;
            }
        }
        if(dp[idx][trend]!=LLONG_MIN){
            return dp[idx][trend];
        }
        long long take=LLONG_MIN/2;
        long long skip=LLONG_MIN/2;
        // skipping for next index to start in future
        if(trend==0){
            skip=solve(idx+1,0,nums);
        }
        // I am at trend 3 and i can now end at idx
        if(trend==3){
            take=nums[idx]; // finish it here
        }
        if(idx+1<n){
            int curr=nums[idx];
            int next=nums[idx+1];
            if(trend==0 && next>curr){
                take=max(take,curr+solve(idx+1,1,nums));
            }
            else if(trend==1){
                if(next>curr){
                    take=max(take,curr+solve(idx+1,1,nums));
                }
                else if(next<curr){
                    take=max(take,curr+solve(idx+1,2,nums));
                }
            }
            else if(trend==2){
                if(next<curr){
                    take=max(take,curr+solve(idx+1,2,nums));
                }
                else if(next>curr){
                    take=max(take,curr+solve(idx+1,3,nums));
                }
            }
            else if(trend==3 && next>curr){
                take=max(take,curr+solve(idx+1,3,nums));
            }
        }
        return max(take,skip);
    }
    long long maxSumTrionic(vector<int>& nums){
        n=nums.size();
        dp.assign(n,vector<long long>(4,LLONG_MIN));
        return solve(0,0,nums);
    }
};
