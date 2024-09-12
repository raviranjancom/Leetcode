class Solution {
public:
    int climbStairs(int n) {
        int f=1,s=0,ans=0;
        for(int i=0;i<n;i++){
            ans=f+s;
            s=f;
            f=ans;
        }
        return ans;
    }
};

/// 0,1,1,2,3,5,8,13,21