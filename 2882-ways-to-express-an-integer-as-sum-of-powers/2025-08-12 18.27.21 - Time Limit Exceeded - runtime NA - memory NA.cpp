class Solution {
public:
    int fun(int num,int x,int sum){
        if(sum==0){
            return 1;
        }
        else if(sum<0){
            return 0;
        }
        else if(pow(num,x)>sum){
            return 0;
        }
        int p=pow(num,x);
        sum-=p;
        int a=fun(num+1,x,sum);
        sum+=p;
        int b=fun(num+1,x,sum);
        return a+b;
    }
    int numberOfWays(int n, int x) {
        int num=1;
        return fun(num,x,n);
    }
};