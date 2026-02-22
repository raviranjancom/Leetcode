class Solution {
public:
    int binaryGap(int n){
        int p=-1;
        int ans=0;
        for(int i=0;i<32;i++){
            if((n&(1<<i))!=0){
                if(p==-1) p=i;
                else{
                    ans=max(ans,abs(i-p));
                    p=i;
                }
            }
        }
        return ans;
    }
};
