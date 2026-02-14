class Solution {
public:
    // my solution
    int n;
    vector<bool> marked;
    map<pair<int,bool>,long long> dp; // idx,marked[i-1] ---> ans
    long long solve(vector<int>& nums, vector<int>& colors,int idx){
        if(idx==n) return 0;
        if(dp.find({idx,((idx==0)?false:marked[idx-1])})!=dp.end()) return dp[{idx,((idx==0)?false:marked[idx-1])}];
        long long skip=solve(nums,colors,idx+1);
        long long take=0;
        if(idx==0 || (idx>0 && colors[idx]!=colors[idx-1]) || (idx>0 && colors[idx]==colors[idx-1] && marked[idx-1]==false)){
            marked[idx]=true;
            take=nums[idx]+solve(nums,colors,idx+1);
            marked[idx]=false;
        }
        return dp[{idx,((idx==0)?false:marked[idx-1])}]=max(take,skip);
    }
    long long rob(vector<int>& nums, vector<int>& colors){
        n=nums.size();
        marked.resize(n,false);
        return solve(nums,colors,0);
    }
};
