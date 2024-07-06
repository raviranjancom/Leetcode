class Solution {
public:
    double myPow(double x, int n) {
        double a=1;
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