class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int m=people.size(),n;
        if(m%2==0) n=m;
        else n=m-1;
        sort(people.begin(),people.end());
        int ans=0,i=0;
        while(i<n){
            if(people[i]+people[i+1]<=limit) ans++;
            else break;
            i+=2;
        }
        ans+=(m-i);
        return ans;
    }
};
