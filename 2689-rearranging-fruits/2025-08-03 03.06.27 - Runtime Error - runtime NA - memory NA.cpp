class Solution {
public:
    int min(int a,int b){
        return (a<b)?a:b;
    }
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        int minEl=INT_MAX;
        int n=basket1.size(),m=basket2.size();
        map<int,int> mp;
        for(int i=0;i<n;i++){
            minEl=min(minEl,min(basket2[i],basket1[i]));
            mp[basket1[i]]++;
            mp[basket2[i]]--;
        }

        vector<int> arr;
        for(auto it:mp){
            if(it.second%2==1) return -1;
            if(it.second==0) continue;
            for(int c=1;c<=abs(it.second)/2;c++){
                arr.push_back(it.first);
            }
        }
        int ans=0;
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size()/2;i++){
            ans+=min(2*minEl,arr[i]);
        }
        return ans;
    }
};
