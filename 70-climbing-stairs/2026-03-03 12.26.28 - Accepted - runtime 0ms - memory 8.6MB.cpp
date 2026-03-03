class Solution {
public:
    int climbStairs(int n){
        vector<int> data(n+2,0);
        data[1]=1;
        data[2]=2;
        for(int i=3;i<=n;i++){
            data[i]=data[i-1]+data[i-2];
        }
        return data[n];
    }
};
