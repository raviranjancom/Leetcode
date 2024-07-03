class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n>0 && n<2147483648){
            float x;
            x=log2(n);
            x=x/2;
            if (x==int(x)) return true;
        }
        return false;
    }
};
