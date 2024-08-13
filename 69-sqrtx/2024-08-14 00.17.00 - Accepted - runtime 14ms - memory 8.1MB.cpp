class Solution {
public:
    int mySqrt(int x) {
        int i=0,ans=0;
        if(x>2147395599) return 46340;
        while(i*i<=x && i<46340){
            ans=i;
            i++;
        }
        return ans;
    }
};
