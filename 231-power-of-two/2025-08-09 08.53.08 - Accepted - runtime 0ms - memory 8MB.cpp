class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==-2147483648) return false;
        int i=0;
        while(i<32){
            if((n^(1<<i))==0){
                return true;
            }
            i++;
        }
        return false;
    }
};
