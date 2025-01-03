class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==INT_MIN && divisor==-1) return INT_MAX;
        if(dividend==INT_MIN && divisor==1) return INT_MIN;
        if(dividend==INT_MAX && divisor==-1) return -1*INT_MAX;
        if(dividend==INT_MAX && divisor==1) return INT_MAX;
        int sign;
        if((dividend<0 &&divisor<0) || (dividend>0 &&divisor>0)) sign=1;
        else sign=-1;
        long long dividend1=(long long) dividend;
        dividend1=abs(dividend1);
        long long divisor1=(long long) divisor;
        divisor1=abs(divisor1);
        if(dividend1==divisor1) return sign*1;
        long long ans=0,x=divisor1;;
        while(dividend1>divisor1){
            divisor1+=x;
            ans++;
        }
        if(ans>INT_MAX) ans=INT_MAX;
        if(ans<INT_MIN) ans=INT_MIN;
        return sign*(int)ans;
    }
};
