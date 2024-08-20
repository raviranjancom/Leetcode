class Solution {
public:
    bool isPerfectSquare(int num){
        bool t=false;
        for(long long i=1;i<num/2;i++){
            if(i*i==num){
                t=true;
                break;
            }
        }
        return t;
    }
};
