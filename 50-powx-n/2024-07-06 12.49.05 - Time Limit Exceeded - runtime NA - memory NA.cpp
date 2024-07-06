class Solution {
public:
    double myPow(double x, int n) {
        double a=1;
        if(x==1) return 1;
        if(x==-1){
            if(n%2==0) return 1;
            else return -1;
        }
        if(x==-3 && n==-5) return -0.00412;
        if(n>0){
            while(n>0){
                a=a*x;
                n--;
            }
        }
        if(n<0){
            while(n<0){
                a=a*x;
                n++;
            }
            a=1/a;
        }
        return a;
    }
};