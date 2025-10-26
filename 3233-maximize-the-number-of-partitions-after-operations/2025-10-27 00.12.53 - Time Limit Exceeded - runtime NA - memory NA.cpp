class Solution {
public:
    int N;
    int solve(int i,long long unique_char, bool can_change,string &s, int k){
        if(i>=N){
            return 1;
        }
        int idx=s[i]-'a';
        int new_unique_char=(unique_char | (1<<idx));
        int unique_char_count=__builtin_popcount(new_unique_char);

        int ans=0;
        if(unique_char_count>k){
            ans=1+solve(i+1,(1<<idx),can_change,s,k);
        }
        else{
            ans=solve(i+1,new_unique_char,can_change,s,k);
        }
        if(can_change==true){
            for(int c=0;c<26;c++){
                int new_unique_char_=(unique_char | (1<<c));
                int unique_char_count_=__builtin_popcount(new_unique_char_);
                if(unique_char_count_>k){
                    ans=max(ans,1+solve(i+1,(1<<c),false,s,k));
                }
                else{
                    ans=max(ans,solve(i+1,new_unique_char_,false,s,k));
                }
                // ans=max(ans,solve(i+1,unique_char_count_,false,s,k));
            }
        }
        return ans;
    }
    int maxPartitionsAfterOperations(string s, int k) {
        N=s.length();
        return solve(0,0,true,s,k);
    }
};
