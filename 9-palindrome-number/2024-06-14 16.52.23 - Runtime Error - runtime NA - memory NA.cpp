class Solution {
public:
    bool isPalindrome(int x) {
        int n=x;
        int r;
        int rev=0;
        if (x>=0){
            while (n!=0){
                r=n%10;
                n=n/10;
                rev=rev*10+r;
            }
        if (rev==x) return true;
        else return false;
        }
        else return false;
    }
};
