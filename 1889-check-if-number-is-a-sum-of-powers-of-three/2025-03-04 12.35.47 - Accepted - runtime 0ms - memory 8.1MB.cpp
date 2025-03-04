class Solution {
public:
    bool checkPowersOfThree(int n) {
        if(n==2) return false;
        int m=n;
        bool firstTime=true;
        long long p=0,q=-1;
        while(1){
            while(pow(3,p) < n && firstTime){
                p++;
            }
            firstTime=false;
            while(pow(3,p) > m && !firstTime){
                p--;
            }
            if(p==q) return false;
            m-=pow(3,p);
            if(m==0 || m==1 ) return true;
            if(m<3) break;
            q=p;
        }
        return false;
    }
};
