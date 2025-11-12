class Solution {
public:
    map<vector<int>,int> dp;      // ----> array => ans
    int solve(vector<int>& nums,vector<bool> &marked){
        bool flag=true;
        for(auto it:marked){
            if(it==false){
                flag=false;
                break;
            }
        }
        if(flag) return 0;
        

        int ans=INT_MAX;
        for(int i=0;i<nums.size()-1;i++){
            if(dp.count(nums)>0){
                return dp[nums];
            }
            if(marked[i]==false || marked[i+1]==false){
                int gcd=GCD(nums[i],nums[i+1]);
                int x=INT_MAX;

                if(gcd!=nums[i]){
                    int prev_val1=nums[i];
                    bool prev_flag1=marked[i];

                    nums[i]=gcd;
                    marked[i]=(gcd==1)?true:false;
                    x=solve(nums,marked);
                    if(x!=INT_MAX){
                        x++;
                    }
                    nums[i]=prev_val1;
                    marked[i]=prev_flag1;
                }

                int y=INT_MAX;
                if(gcd!=nums[i+1]){
                    int prev_val2=nums[i+1];
                    bool prev_flag2=marked[i+1];

                    nums[i+1]=gcd;
                    marked[i+1]=(gcd==1)?true:false;
                    y=solve(nums,marked);
                    if(y!=INT_MAX){
                        y++;
                    }
                    nums[i+1]=prev_val2;
                    marked[i+1]=prev_flag2;
                }
                
                ans=min(ans,min(x,y));
            }
        }
        return dp[nums]=ans;
    }
    int GCD(int n,int m){
        return (m==0)?n:GCD(m,n%m);
    }
    int minOperations(vector<int>& nums){
        int n=nums.size();
        vector<bool> marked(n,false);
        if(nums[0]==1) marked[0]=true; 
        int result=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]==1){
                marked[i]=true;
            }
            result=GCD(result,nums[i]);
            if(result==1) break;
        }
        if(result>1) return -1;
        return solve(nums,marked);
    }
};
