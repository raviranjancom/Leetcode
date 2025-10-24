class Solution {
public:
    bool solve(int n){
        int hash[33]={0};
        while(n>0){
            int d=n%10;
            hash[d]++;
            n=n/10;
        }

        for(int i=0;i<33;i++){
            if(hash[i]==0 || hash[i]==i) continue;
            else return false;
        }
        return true;
    }
    int nextBeautifulNumber(int n) {
        for(int i=n+1;i<=INT_MAX;i++){
            if(solve(i)==true) return i;
        }
        return -1;
    }
};
