class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n=fruits.size();
        vector<int> position(n),prefixsum(n);
        for(int i=0;i<n;i++){
            position[i]=fruits[i][0];
            prefixsum[i]=fruits[i][1]+((i>0)?prefixsum[i-1]:0);
        }
        int ans=0;
        for(int d=0;d<=k/2;d++){
            int remain=k-2*d;
            int i=startPos-d;
            int j=startPos+remain;
            int left=lower_bound(position.begin(),position.end(),i)-position.begin();
            int right=upper_bound(position.begin(), position.end(),j)-position.begin()-1;

            if(left<=right){
                int sum=prefixsum[right]-(left>0?prefixsum[left-1]:0);
                ans=max(ans,sum);
            }

            i=startPos-remain;
            j=startPos+d;
            left=lower_bound(position.begin(),position.end(),i)-position.begin();
            right=upper_bound(position.begin(), position.end(),j)-position.begin()-1;

            if(left<=right){
                int sum=prefixsum[right]-(left>0?prefixsum[left-1]:0);
                ans=max(ans,sum);
            }
            
        }
        return ans;
    }
};
