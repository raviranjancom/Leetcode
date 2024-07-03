class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n>-1 && n<2147483648){
            float x;
            x=log2(n);
            x=x/2;
            if (x==int(x) || n==0 || n==1) return true;
        }
        return false;
    }
};
