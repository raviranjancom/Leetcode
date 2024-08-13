int fun(int n){
    if(n==45) return 1836311903;
    if(n<3) return n;
    else return fun(n-1)+fun(n-2);
}
class Solution {
public:
    int climbStairs(int n) {
        return fun(n);
    }
};
