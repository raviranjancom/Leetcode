class Solution {
public:
    int mod=1e9+7;
    vector<string> states;
    void fillstates(string &s,int m){
        if(s.length()==m){
            states.push_back(s);
            return ;
        }
        string colors={'R','G','B'};
        for(char ch:colors){
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
        string last=states[prev];
        int ans=0;
        for(int i=0;i<states.size();i++){
            string curr=states[i];
            if(last!=curr){
                ans+=(ans+solve(n,i))%mod;
            }
        }
        return ans;
    }
    int colorTheGrid(int n, int m){
        int ans=0;
        string s;
        fillstates(s,m);
        for(int i=0;i<states.size();i++){
            ans=(ans+solve(n-1,i))%mod;
        }
        return ans;
    }
};
