class Solution {
public:
    int mod=1e9+7;
    vector<int> dp;
    bool check(vector<bool> &visited){
        for(auto it:visited){
            if(it==false) return false;
        }
        return true;
    }
    int solve(vector<int> &nums,vector<bool>& visited,int mini){
        int ans=0;
        for(int i=1;i<nums.size();i++){
            if(visited[i]==false && mini<nums[i]){
                visited[i]=true;
                ans=(ans+solve(nums,visited,mini))%mod;
                visited[i]=false;
            }
        }
        if(!check(visited)) return ans;
        return ans+1;
    }
    int countPermutations(vector<int>& complexity){
        int n=complexity.size();
        dp.resize(n,-1);
        vector<bool> visited(n,false);
        visited[0]=true;
        return solve(complexity,visited,complexity[0]);
    }
};
