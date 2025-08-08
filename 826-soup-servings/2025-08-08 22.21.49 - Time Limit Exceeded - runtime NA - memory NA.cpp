class Solution {
public:
    double calculate(int a,int b){
        if(a<=0 && b<=0){
            return 0.5;
        }
        if(a<=0){
            return 1.0;
        }
        if(b<=0){
            return 0;
        }
        double ans=0.0;
        ans+=0.25*calculate(a-100,b);
        ans+=0.25*calculate(a-75,b-25);
        ans+=0.25*calculate(a-50,b-50);
        ans+=0.25*calculate(a-25,b-75);
        return ans;
    }
    double soupServings(int n) {
        return calculate(n,n);
    }
};
