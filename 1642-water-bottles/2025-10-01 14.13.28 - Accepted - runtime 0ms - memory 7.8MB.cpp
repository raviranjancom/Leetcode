class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int full=numBottles;
        int empty=0;
        int ans=0;
        while(true){
            ans+=full;
            empty+=full;
            full=0;
            if(empty<numExchange) break;
            full=empty/numExchange;
            empty=empty%numExchange;
        }
        return ans;
    }
};
