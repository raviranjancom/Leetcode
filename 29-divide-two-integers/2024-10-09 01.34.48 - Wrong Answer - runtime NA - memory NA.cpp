class Solution {
public:
    int divide(int dividend, int divisor) {
        int ans=0,y,sign=1;
        if(dividend<0 && divisor>-1){
            sign=-1;
            dividend*=-1;
        }
        if(dividend>-1 && divisor<0){
            sign=-1;
            divisor*=-1;
        }
        for(int i=1;i<=dividend;i++){
            ans+=divisor;
            if(ans<=dividend){
                y=i;
            }
        }
        y=sign*y;
        return y;
    }
};