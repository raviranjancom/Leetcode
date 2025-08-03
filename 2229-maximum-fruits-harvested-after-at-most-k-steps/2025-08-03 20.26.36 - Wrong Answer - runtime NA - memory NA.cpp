class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n=fruits.size();
        if(n==1){
            return fruits[0][1];
        }
        int startindex=0;
        while(startindex<n && fruits[startindex][0] <= startPos){
            startindex++;
        }
        if(startPos==fruits[startindex-1][0]){
            startindex--;
        }
        else{
            fruits.insert(fruits.begin()+startindex,{startPos,0});
        }
        fruits.push_back({n,0});
        n++;
        int left=startindex,right=startindex;
        int sum=fruits[startindex][1],ans=0;
        while(left>0 && fruits[startindex][0]-fruits[left-1][0]<=k){
            left--;
            sum+=fruits[left][1];
            ans=max(ans,sum);
        }
        while(right<n-1){
            cout<<" "<<sum<<" "<<ans<<" "<<fruits[left][0]<<" "<<fruits[right][0]<<endl;
            
            if(startPos-fruits[left][0] + fruits[right+1][0]-fruits[left][0]<=k){
                right++;
                sum+=fruits[right][1];
                if(startPos-fruits[right+1][0]>k) break;
            }
            else{
                sum-=fruits[left][1];
                if(left<startindex) left++;
                else{
                    break;
                }
            }
            ans=max(ans,sum);
        }
        return ans;
    }
};