class Solution {
public:
    bool isPowerOfTwo(int n) {
        bool flag=false;
        if (n==1) flag=true;
        for(int i=1;i<=n/2;i++){
            if (2<<i==n){
                flag=true;
                break;
            }
        }
        return flag;
    }
};