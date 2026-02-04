class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit){
        int n=people.size();
        sort(people.begin(),people.end());
        int i=0,j=n-1;
        int ans=0;
        while(i<=j){
            if(people[j]+people[i]<=limit){
                ans++;
                i++;
                j--;
            }
            else{
                ans++;
                j--;
            }
        }
        return ans;
    }
};
