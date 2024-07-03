class Solution {
public:
    bool isPowerOfFour(int n) {
        float x=log2(n);
        x=x/2;
        if (x==int(x) || n==0 || n==1) return true;
        return false;
    }
};