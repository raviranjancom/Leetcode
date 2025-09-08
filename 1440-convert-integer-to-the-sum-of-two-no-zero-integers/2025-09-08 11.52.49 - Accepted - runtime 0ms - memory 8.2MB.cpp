class Solution {
public:
    bool check(int n){
        while(n>0){
            if(n%10==0) return false;
            n=n/10;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        int i=1;
        while(i<n){
            if(check(i) && check(n-i)) return {i,n-i};
            i++;
        }
        return {0,0};
    }
};