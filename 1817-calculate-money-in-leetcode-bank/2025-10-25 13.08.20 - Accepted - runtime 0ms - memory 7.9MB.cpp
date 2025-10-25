class Solution {
public:
    int sum(int n){
        return n*(n+1)/2;
    }
    int totalMoney(int n) {
        int r=n/7;
        int v=n%7;
        int ans=0;
        ans+=28*r + 7*sum(r-1);
        ans+=(r)*v+sum(v);
        return ans;
    }
};
