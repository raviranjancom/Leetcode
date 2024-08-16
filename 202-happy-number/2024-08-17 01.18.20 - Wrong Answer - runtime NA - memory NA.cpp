int fun(int n){
    int a=0,x=0;
    while(n>0){
        a=n%10;
        x=x+a*a;
        n=n/10;
    }
    return x;
}
class Solution {
public:
    bool isHappy(int n) {
        if(n==1 || n==7) return true;
        if(n!=1 && n<10) return false;
        int c,t=n;
        while(n>9){
            c=fun(n);
            n=c;
            if(c==1) return true;
            if(c>1 && c<10) return false;
        }
        return false;
    }
};
