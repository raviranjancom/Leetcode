class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int full=numBottles,empty=0,ans=0;
        while(true){
            empty+=full;
            ans+=full;
            full=0;
            if(numExchange<=empty){
                full+=1;
                empty-=numExchange;
                numExchange++;
            }
            else{
                break;
            }
        }
        return ans;
    }
};
