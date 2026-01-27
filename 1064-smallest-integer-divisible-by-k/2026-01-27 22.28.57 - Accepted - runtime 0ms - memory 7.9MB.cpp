class Solution {
public:
    int Divide(int k){
        long long n=0;
        int len=0;
        while(len<=k){
            while(len<=k && n<k){
                n=1LL*n*10+1;
                len++;
            }
            n=n%k;
            if(n==0) return len;
        }
        return -1;
    }
    int smallestRepunitDivByK(int k){
        if(k==1) return 1;
        if(k%2==0 || k%5==0) return -1;
        return Divide(k);
    }
};
