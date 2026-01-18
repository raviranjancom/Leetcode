class Solution {
public:
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget){
        int n=costs.size();
        vector<pair<int,int>> pi(n);
        for(int i=0;i<n;i++){
            pi[i]={costs[i],capacity[i]};
        }
        sort(pi.begin(),pi.end());
        vector<long long> prefix(n);
        long long curr=0;
        for(int i=0;i<n;i++){
            curr=max(curr,1LL*pi[i].second);
            prefix[i]=curr;
        }
        long long ans=0;
        for(int i=0;i<n;i++){
            long long curr_cost=pi[i].first;
            long long curr_cap=pi[i].second;
            if(curr_cost<budget){
                ans=max(ans,curr_cap);
            }
            long long rem=1LL*budget-curr_cost;
            int l=0,r=i-1;
            int idx=-1;
            while(l<=r){
                int mid=l+(r-l)/2;
                if(pi[mid].first<rem){
                    idx=mid;
                    l=mid+1;
                }
                else{
                    r=mid-1;
                }
            }
            if(idx!=-1){
                ans=max(ans,curr_cap+prefix[idx]);
            }
        }
        return ans;
    }
};