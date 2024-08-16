int fun(int n){
    int a=0,x=0;
    while(n){
        a=n%10;
        x+=a;
        n=n/10;
    }
    return x;
}
class Solution {
public:
    int addDigits(int num) {
        int r;
        while(num>0){
            if(num<10) return num;
            r=fun(num);
            num=r;
        }
        return r;
    }
};
