class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> pse,nse;
        int mod=1000000007;
        stack<pair<int,int>> st1,st2;
        int n=arr.size();
        for(int i=0;i<n;i++){
            while(!st1.empty() && arr[i]<=st1.top().first){
                st1.pop();
            }
            if(st1.empty()) pse.push_back(-1);
            else pse.push_back(st1.top().second);
            st1.push({arr[i],i});
        }

        for(int i=n-1;i>=0;i--){
            while(!st2.empty() && arr[i] < st2.top().first){
                st2.pop();
            }
            if(st2.empty()) nse.push_back(n);
            else nse.push_back(st2.top().second);
            st2.push({arr[i],i});
        }
        
        reverse(nse.begin(),nse.end());
        long long ans=0;
        for(int i=0;i<n;i++){
            int a=nse[i]-i;
            int b=i-pse[i];
            ans+=a*b*arr[i];
        }
        return ans%mod;
    }
};
