class Solution {
public:
    bool isHappy(int n) {
        int a=0,x;
        bool temp=true;
        while(temp){
            while(n>0){
            a=n%10;
            x=a*a;
            n=n/10;
        }
        if (x==1) return true;
        if (x>1 && x<10) return false;
        }
        return false;
    }
};