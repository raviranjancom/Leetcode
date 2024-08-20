class Solution {
public:
    bool isPerfectSquare(int num){
        bool t=false;
        if(num==1 || num==4) return true;
        for(long long i=1;i<num/2;i++){
            if(i*i==num){
                t=true;
                break;
            }
        }
        return t;
    }
};
