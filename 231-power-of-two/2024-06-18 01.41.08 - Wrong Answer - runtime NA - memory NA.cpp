class Solution {
public:
    bool isPowerOfTwo(int n) {
        int flag=0;
        for(int i=1;i<=n;i++){
            if (i*i==n) flag+=1;
        }
        if (flag>0) return true;
        else return false;
    }
};