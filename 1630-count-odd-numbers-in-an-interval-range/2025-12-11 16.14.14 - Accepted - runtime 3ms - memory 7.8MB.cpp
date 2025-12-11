class Solution {
public:
    int countOdds(int low, int high) {
        int len=high+1-low;
        if(low%2==1 && len%2==1) return 1+ (len/2);
        return len/2;
    }
};
