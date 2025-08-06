class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=fruits.size();
        vector<bool> mark(n,false);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(fruits[i]<=baskets[j] && mark[j]==false){
                    mark[j]=true;
                    break;
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(mark[i]==false){
                ans++;
            }
        }
        return ans;
    }
};