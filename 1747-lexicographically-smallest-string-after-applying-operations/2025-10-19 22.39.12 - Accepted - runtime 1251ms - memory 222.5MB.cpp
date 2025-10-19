class Solution {
public:
    string rotate(string s, int r){
        string x=s.substr(0,s.length()-r);
        string y=s.substr(s.length()-r,r);
        return y+x;
    }
    char add_char(char ch, int a){
        int x=(ch-'0'+a)%10;
        return x+'0';
    }
    void solve(string &s, int &a, int &b, set<string> &mark){
        if(mark.find(s)!=mark.end()){
            return ;
        }
        mark.insert(s);
        string x=s;
        do{
            // adding to all odd positions
            for(int i=1;i<x.length();i+=2){
                x[i]=add_char(x[i],a);
            }
            mark.insert(x);
            string str=rotate(x,b);
            solve(str,a,b,mark);
        }while(x!=s);
    }
    string findLexSmallestString(string s, int a, int b) {
        int n=s.length();
        set<string> mark;
        solve(s,a,b,mark);
        string ans=s;
        for(auto &it:mark){
            ans=min(ans,it);
        }
        return ans;
    }
};
