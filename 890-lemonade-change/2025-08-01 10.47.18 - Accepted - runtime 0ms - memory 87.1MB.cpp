class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n= bills.size();
        int mp[3]={0,0,0};
        for(int i=0;i<n;i++){
            if(bills[i]==5){
                mp[0]++;
            }
            else if(bills[i]==10){
                if(mp[0]>0){
                    mp[0]--;
                    mp[1]++;
                }
                else{
                    return false;
                }
            }
            else{
                if(mp[0]>0 && mp[1]>0){
                    mp[0]--;
                    mp[1]--;
                    mp[2]++;
                }
                else if(mp[0]>2){
                    mp[0]-=3;
                    mp[2]++;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};