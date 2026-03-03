class Solution {
public:
    int fib(int n){
        vector<int> data(n+1,0);
        data[0]=0;
        data[1]=1;
        for(int i=2;i<=n;i++){
            data[i]=data[i-1]+data[i-2];
        }
        return data[n];
    }
};
