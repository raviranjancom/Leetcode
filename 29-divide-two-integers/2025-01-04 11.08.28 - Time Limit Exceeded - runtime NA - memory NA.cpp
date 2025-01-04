class Solution {
public:
    int divide(int dividend, int divisor) {
        int sign;
        if((dividend<0 &&divisor<0) || (dividend>0 &&divisor>0)) sign=1;
        else sign=-1;
        long long n=abs((long long)dividend), d=abs((long long)divisor),x=0,r=0;
        while(x+d<=n){
            x+=d;
            r++;
        }
        if(sign*r>=INT_MAX) return INT_MAX;
        if(sign*r<=INT_MIN) return INT_MIN;
        return sign*r;
    }
};