class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=size(prices);
        int max=0,min=0,t=0,profit=0;
        for(int i=n-1;i>-1;i--){
            max=prices[i];
            for(int j=i-1;j>-1;j--){
                min=prices[j];
                t=max-min;
                if(t>profit) profit=t;
            }
        }
        return profit;
    }
};