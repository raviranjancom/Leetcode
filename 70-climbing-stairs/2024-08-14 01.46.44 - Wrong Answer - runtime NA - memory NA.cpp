int fun(int n){
    if(n<3) return n;
    else return 1+fun(n-1);
}
class Solution {
public:
    int climbStairs(int n) {
        return fun(n);
    }
};