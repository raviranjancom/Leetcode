class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=size(prices);
        int min=prices[0],x=0,profit=0;
        for(int i=0;i<n;i++){
            if(min>prices[i]){
                min=prices[i];
                x++;
            }
        }
        int max=prices[x];
        for(int i=x;i<n;i++){
            if(max<prices[i]) max=prices[i];
        }
        profit=max-min;
        return profit;
    }
};