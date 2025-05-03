class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n=people.size();
        sort(people.begin(),people.end());
        int l=0,r=n-1,ans=0;
        while(l<r){
            if(people[l]+people[r] <= limit){
                people[l]=-1;
                people[r]=-1;
                ans++;
                l++;
                r--;
            }
            else{
                r--;
            }
        }
        for(int i=0;i<n;i++){
            if(people[i]!=-1){
                ans++;
            }
        }
        return ans;
    }
};
// 1 2 2 3
// 