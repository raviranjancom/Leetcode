class Solution {
public:
    bool solve(vector<int> piles,int p,int h){
        int ans=0;
        int n=piles.size();
        for(int i=0;i<n;i++){
            ans+=(piles[i]+p-1)/p;
            if(ans>h) return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h){
        int n=piles.size();
        int ans=1e9;
        int i=1,j=1e9;
        while(i<j){
            int p=(i+j)/2;
            if(solve(piles,p,h)){
                j=p;
                ans=min(ans,p);
            }
            else{
                i=p+1;
            }
        }
        return ans;
    }
};
