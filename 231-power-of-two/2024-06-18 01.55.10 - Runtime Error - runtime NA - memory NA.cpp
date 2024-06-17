int fun(long int n){
    if (n==2) return 2;
    if (n==1) return 1;
    else{
        return 2*fun(n-1);
    }
}
class Solution {
public:
    bool isPowerOfTwo(int n) {
        int flag=0;
        for(int i=1;i<=n;i++){
            if (fun(i)==n){
                flag++;
            }
        }
        if (flag>0) return true;
        else return false;
    }
};