class Solution {
public:
    int minimizeXor(int num1, int num2){
        int ans=0;
        int n=__builtin_popcount(num2);
        for(int i=0;i<32 && n>0;i++){
            if(num1&(1<<i)!=0){
                ans=(ans|(1<<i));
                n--;
            }
        }
        for(int i=0;i<32 && n>0;i++){
            if(num1&(1<<i)==0){
                ans=(ans|(1<<i));
                n--;
            }
        }
        return ans;
    }
};
