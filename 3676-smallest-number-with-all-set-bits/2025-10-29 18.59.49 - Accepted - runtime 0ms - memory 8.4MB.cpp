class Solution {
public:
    int smallestNumber(int n) {
        n=log(n)/log(2);
        return pow(2,n+1)-1;
    }
};
