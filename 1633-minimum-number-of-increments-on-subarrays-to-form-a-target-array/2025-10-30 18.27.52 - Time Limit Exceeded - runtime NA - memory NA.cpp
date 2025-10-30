class Solution {
public:
    int solve(vector<int>& target,int start,int end,int step){
        int a=-1,b=-1,ans=1;
        for(int i=start;i<=end;i++){
            if(target[i]>step){
                if(a==-1){
                    a=i;
                    b=i;
                }
                else{
                    b=i;
                }
            }
            else{
                if(a!=-1){
                    ans+=solve(target,a,b,step+1);
                    a=-1;
                    b=-1;
                }
            }
        }
        if(a!=-1){
            ans+=solve(target,a,b,step+1);
            a=-1;
            b=-1;
        }
        return ans;
    }
    int minNumberOperations(vector<int>& target) {
        int n=target.size();
        return solve(target,0,n-1,1);
    }
};
