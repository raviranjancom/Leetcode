class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int n=__builtin_popcount(num1);
        int m=__builtin_popcount(num2);
        int r, ans;
        if(n==m) return num1;
        else if(n > m){
            ans=0;
            for(int i=0;i<31;i++){
                if((num1 & (1<<i)) != 0){
                    r=i;
                }
            }
            while(m>0 && r>=0){
                if(num1 & 1<<r != 0){
                    ans=ans | 1<<r;
                    m--;
                }
                r--;
            }
        }
        else{
            ans=num1;
            int a=m-n;
            int i=0;
            while(a>0 && i<31){
                if((num1 & (1<<i)) ==0){
                    ans=ans | (i<<i);
                    a--;
                }
                i++;
            }
        }
        return ans;
    }
};
