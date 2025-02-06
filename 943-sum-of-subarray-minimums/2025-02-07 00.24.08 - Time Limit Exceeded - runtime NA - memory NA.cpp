class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        int ans=0;
        for(int i=0;i<n;i++){
            int a=INT_MAX;
            for(int j=i;j<n;j++){
                if(a>arr[j]) a=arr[j];
                ans+=a;
                ans=ans%(1000000007);
            }
        }
        return ans;
    }
};