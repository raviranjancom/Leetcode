class Solution {
public:
    string solve(int n){
        int min=0;
        for(int i=0;i<6;i++){
            if((n&(1<<i))!=0){
                min+=(1<<i);
            }
        }
        if(min<60){
            int hrs=0;
            for(int i=6;i<10;i++){
                if((n&(1<<i))!=0){
                    hrs+=(1<<(i-6));
                }
            }
            if(hrs<12){
                string s=(min<10)?"0"+to_string(min):to_string(min);
                return to_string(hrs)+":"+s;
            }
        }
        return "$";
    }
    vector<string> readBinaryWatch(int turnedOn){
        int n=(1<<10);
        vector<string> ans;
        for(int i=0;i<=n;i++){
            if(__builtin_popcount(i)==turnedOn){
                string str=solve(i);
                if(str!="$" && str!="0:00") ans.push_back(str);
            }
        }
        return ans;
    }
};
