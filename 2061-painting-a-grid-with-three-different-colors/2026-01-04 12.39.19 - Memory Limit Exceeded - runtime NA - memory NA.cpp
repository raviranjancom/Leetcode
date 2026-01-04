class Solution {
public:
    int mod=1e9+7;
    vector<vector<int>> dp;
    vector<string> states;
    void fillstates(string &s,int &m){
        if(s.length()==m){
            states.push_back(s);
            return ;
        }
        string colors={'R','G','B'};
        for(char &ch:colors){
            if((s.length()==0) || (s.length()>0 && s.back()!=ch)){
                s.push_back(ch);
                fillstates(s,m);
                s.pop_back();
            }
        }
        return ;
    }
    int solve(int n,int prev){
        if(n==0){
            return 1;
        }
        if(dp[n][prev]!=-1){
            return dp[n][prev];
        }
        int ans=0;
        string last=states[prev];
        for(int i=0;i<states.size();i++){
            bool conflict=false;
            string curr=states[i];
            for(int col=0;col<states[i].length();col++){
                if(curr[col]==last[col]){
                    conflict=true;
                    break;
                }
            }
            if(!conflict){
                ans=(ans+solve(n-1,i))%mod;
            }
        }
        return dp[n][prev]=ans;
    }
    int colorTheGrid(int n, int m){
        int ans=0;
        string s;
        fillstates(s,m);
        dp.resize(n,vector<int>(states.size(),-1));
        for(int i=0;i<states.size();i++){
            ans=(ans+solve(n-1,i))%mod;
        }
        return ans;
    }
};
