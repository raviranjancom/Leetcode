class Solution {
public:
    int bin2deci(string s){
        int ans=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[n-i-1]=='1') ans+=pow(2,i);
        }
        return ans;
    }
    void fun(string str, int n, map<string,int> &mp,vector<string> &ans){
        for(int i=0;i<n;i++){
            string s=str;
            s[n-1-i]=(s[n-1-i]=='0')?'1':'0';
            mp[s]++;
            if(mp[s]==1){
                ans.push_back(s);
                fun(s,n,mp,ans);
            }
        }
    } 
    
    vector<int> grayCode(int n) {
        string s(n,'0');
        map<string,int> mp;
        vector<string> ds;
        mp[s]++;
        ds.push_back(s);
        fun(s, n, mp, ds);
        vector<int> ans;
        for(auto it:ds){
            ans.push_back(bin2deci(it));
        }
        return ans;
    }
};
