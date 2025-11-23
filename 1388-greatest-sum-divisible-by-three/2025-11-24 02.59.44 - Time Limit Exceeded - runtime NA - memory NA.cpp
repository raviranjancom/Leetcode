class Solution {
public:
    int check(vector<int> &ds){
        int sum=0;
        for(int i=0;i<ds.size();i++){
            sum+=ds[i];
        }
        return sum;
    }
    void solve(vector<int> &nums,vector<int> &ds,priority_queue<int> &pq,int idx){
        if(idx>=nums.size()){
            int x=check(ds);
            if(x%3==0){
                pq.push(x);
            }
            return ;
        }
        //take
        ds.push_back(nums[idx]);
        solve(nums,ds,pq,idx+1);
        ds.pop_back();
        // Not take
        solve(nums,ds,pq,idx+1);
    }
    int maxSumDivThree(vector<int>& nums) {
        int n=nums.size();
        vector<int> ds;
        priority_queue<int> pq;
        solve(nums,ds,pq,0);
        return pq.top();
    }
};
