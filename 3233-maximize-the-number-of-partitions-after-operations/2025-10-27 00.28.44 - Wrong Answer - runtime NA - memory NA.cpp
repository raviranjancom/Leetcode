class Solution {
public:
    unordered_map<long long,int> dp;
    int N;
    int solve(int i,long long bit_set, bool can_change,string &s, int k){
        long long key=((i<<27) | (bit_set<<1) | can_change);
        if(i>=N){
            return 1;
        }
        if(dp.find(key)!=dp.end()){
            return dp[key];
        }
        int idx=s[i]-'a';
        int set_char=(bit_set | (1<<idx));
        int unique_char_count=__builtin_popcount(set_char);

        int ans=0;
        if(unique_char_count>k){
            ans=1+solve(i+1,(1<<idx),can_change,s,k);
        }
        else{
            ans=solve(i+1,set_char,can_change,s,k);
        }
        if(can_change==true){
            for(int c=0;c<26;c++){
                int set_char_=(bit_set | (1<<c));
                int unique_char_count_=__builtin_popcount(set_char_);
                if(unique_char_count_>k){
                    ans=max(ans,1+solve(i+1,(1<<c),false,s,k));
                }
                else{
                    ans=max(ans,solve(i+1,set_char_,false,s,k));
                }
                // ans=max(ans,solve(i+1,unique_char_count_,false,s,k));
            }
        }
        return dp[key]=ans;
    }
    int maxPartitionsAfterOperations(string s, int k) {
        N=s.length();
        return solve(0,0,true,s,k);
    }
};
