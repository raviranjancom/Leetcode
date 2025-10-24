class Solution {
public:
    long long minTime(vector<int>& skills, vector<int>& mana) {
        int n=mana.size(),m=skills.size();
        vector<long long> prev(m,0),next(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(j==0){
                    next[j]=prev[j]+skills[j]*mana[i];
                }
                else{
                    next[j]=max(next[j-1],prev[j])+skills[j]*mana[i];
                }
            }
            // syncronizing time
            for(int j=m-2;j>-0;j--){
                next[j]=next[j+1]-skills[j+1]*mana[i];
            }
            prev=next;
        }
        return prev[m-1];
    }
};
