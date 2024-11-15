class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c==1 || c==0) return true;
        for(int i=0;i<c;i++){
            for(int j=0;j<c;j++){
                if(i*i + j*j == c) return true;
                if(i*i> c && j*j>c) return false;
            }
        }
        return false;
    }
};