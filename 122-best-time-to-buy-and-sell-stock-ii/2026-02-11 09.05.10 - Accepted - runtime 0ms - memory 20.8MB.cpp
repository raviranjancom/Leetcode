class Solution {
public:
    int maxProfit(vector<int>& prices){
        int n=prices.size();
        priority_queue<int, vector<int>, greater<int>> pq;   // min pq
        int ans=0;
        for(int i=0;i<n;i++){
            pq.push(prices[i]);
            int nextPrice=(i+1==n)?INT_MIN:prices[i+1];
            if(prices[i]>nextPrice){
                ans+=prices[i]-pq.top();
                pq={};
            }
        }
        return ans;
    }
};
