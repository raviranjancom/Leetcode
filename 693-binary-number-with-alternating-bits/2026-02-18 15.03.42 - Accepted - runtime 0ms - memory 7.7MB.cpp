class Solution {
public:
    bool hasAlternatingBits(int n){
        int msb=0;
        for(int i=0;i<32;i++){
            if((n&(1<<i))!=0) msb=i;
        }
        for(int i=0;i<msb;i++){
            if(((n&(1<<i))==0 && (n&(1<<(i+1)))==0) || ((n&(1<<i))!=0 && (n&(1<<(i+1)))!=0)){
                return false;
            }
        }
        return true;
    }
};
