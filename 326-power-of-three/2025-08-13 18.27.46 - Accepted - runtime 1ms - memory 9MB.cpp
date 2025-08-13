class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<1) return false;
        int num=1;
        if(n==1162261467) return true;
        for(int i=2;i<21;i++){
            if(abs(n)==num) return true;
            if(num>abs(n)) return false;
            num*=3;
        }
        return false;
    }
};
