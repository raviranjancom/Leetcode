class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<1) return false;
        int num=1;
        for(int i=2;i<20;i++){
            if(abs(n)==num) return true;
            if(num>abs(n)) return false;
            num*=3;
        }
        return false;
    }
};
