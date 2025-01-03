class Solution {
public:
    int divide(int dividend, int divisor) {
        int sign;
        if((dividend<0 &&divisor<0) || (dividend>0 &&divisor>0)) sign=1;
        else sign=-1;
        dividend=abs(dividend);
        divisor=abs(divisor);
        int ans=0,x=divisor;;
        while(dividend>divisor && ans<=INT_MAX && ans>=INT_MIN){
            divisor+=x;
            ans++;
        }
        return sign*ans;
    }
};