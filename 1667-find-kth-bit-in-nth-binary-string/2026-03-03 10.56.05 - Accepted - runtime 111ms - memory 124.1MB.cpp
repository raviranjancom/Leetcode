class Solution {
public:
    unordered_map<int,string> mp;
    string operate(string s){
        string ans;
        for(int i=s.length()-1;i>=0;i--){
            char x=(s[i]=='0')?'1':'0';
            ans.push_back(x);
        }
        return ans;
    }
    string generate(int n){
        if(n==1) return "0";
        if(mp.find(n)!=mp.end()) return mp[n];
        string x=generate(n-1);
        return mp[n]=x+"1"+operate(x);
    }
    char findKthBit(int n, int k){
        string s=generate(n);
        return s[k-1];
    }
};
