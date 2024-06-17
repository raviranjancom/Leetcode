class Solution {
public:
    bool isPowerOfTwo(int n) {
        bool flag=false;
        if (n==1) flag=true;
        if (n<0) flag=false;
        if (n>0){
            for(int i=0;i<=31;i++){
            if (2<<i==n){
                flag=true;
                break;
            }
        }
        }
        return flag;
    }
};
