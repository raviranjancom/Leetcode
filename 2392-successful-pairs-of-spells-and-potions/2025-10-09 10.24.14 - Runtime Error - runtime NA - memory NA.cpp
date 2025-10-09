class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n=spells.size(),m=potions.size();
        sort(potions.begin(),potions.end());
        vector<int> ans;
        for(int i=0;i<n;i++){
            int l=0,r=m-1;
            while(l<r){
                int mid=(l+r)/2;
                if(potions[mid]*spells[i]>=success){
                    r=mid;
                }
                else{
                    l=mid+1;
                }
            }
            if(potions[r]*spells[i]>=success){
                ans.push_back(m-r);
            }
            else{
                ans.push_back(0);
            }
        }
        return ans;
    }
};