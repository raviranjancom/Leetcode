class Solution {
public:
    int mod=1e9+7;
    int fact(int n){
        int ans=1;
        for(int i=2;i<=n;i++){
            ans=(ans*i)%mod;
        }
        return ans;
    }
    int countPermutations(vector<int>& complexity){
        int ans=0;
        int n=complexity.size();
        for(int i=1;i<n;i++){
            if(complexity[0]>=complexity[i]){
                return 0;
            }
        }
        return fact(n-1);
    }
};
