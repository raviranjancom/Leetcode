class Solution {
public:
    int maxf(vector<int> arr, int l, int r){
        int m=l;
        for(int i=l;i<=r;i++){
            if(arr[m]<arr[i]) m=i;
        }
        return m;
    }
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> steps(n);
        for(int i=0;i<n;i++){
            steps[i]=i+nums[i];
        }
        // calculate
        int ans=0;
        int i=0;
        while(i<n){
            int range=steps[i];
            if(range>=n-1) return ++ans;
            int nextindex=maxf(steps,i+1,range);
            i=nextindex;
            ans++;
        }
        return ans;
    }
};